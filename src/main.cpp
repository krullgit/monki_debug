#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include "Arduino_DriveBus_Library.h"
#include "pin_config.h"

#include "shared_modules/DisplayModule.h"
#include "shared_modules/state_global.h"
#include "shared_modules/TouchModule.h"
#include "screenmanager/ScreenManager.h" // Include the ScreenManager
#include "shared_modules/FileSystemModule.h"
#include "ui_callbacks/CustomCallbacks.h"

#include "shared_modules/HTTPOTAUpdateModule.h"

#include "wifi_credentials.h"


// LVGL buffer and driver setup
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[LCD_WIDTH * LCD_HEIGHT / 10]; // Larger buffer for better performance

// Graphics and Display Setup
Arduino_DataBus *bus = new Arduino_ESP32QSPI(
    LCD_CS, LCD_SCLK, LCD_SDIO0, LCD_SDIO1, LCD_SDIO2, LCD_SDIO3);

Arduino_GFX *gfx = new Arduino_SH8601(
    bus, LCD_RST, 0 /* rotation */, false /* IPS */, LCD_WIDTH, LCD_HEIGHT);

// I2C Touch Bus
std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus =
    std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);

void Arduino_IIC_Touch_Interrupt(void);

std::unique_ptr<Arduino_IIC> FT3168(new Arduino_CST816x(IIC_Bus, FT3168_DEVICE_ADDRESS,
                                                        DRIVEBUS_DEFAULT_VALUE, TP_INT, Arduino_IIC_Touch_Interrupt));

void Arduino_IIC_Touch_Interrupt(void)
{
    FT3168->IIC_Interrupt_Flag = true;
}

// Flag to ensure screens are initialized only once
bool screensInitialized = false;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting Setup...");

    // Initialize Display
    pinMode(LCD_EN, OUTPUT);
    digitalWrite(LCD_EN, HIGH);
    gfx->begin();
    gfx->fillScreen(BLACK);
    gfx->Display_Brightness(250); // Must be here; later adjusted dynamically

    // Initialize LVGL
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, nullptr, LCD_WIDTH * LCD_HEIGHT / 10);
    
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Initialize Touch
    FT3168->begin();
    
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Initialize File System
    if (!initFileSystem()) {
        Serial.println("File system initialization failed");
        while (true);
    }

    // Load User Settings
    initializeUsers();
    set_oled_brightness(currentUser->settingsDisplay[0].value);

    // Initialize Screens
    Serial.println("Initializing screens...");

    // Show the main screen
    ScreenManager::showScreenS2_1();

    Serial.println("Setup Complete");

    // Initialize Sound Module

    soundModule.initializeAmplifier();
    // Play a random sound once at startup (or call this later)
    randomSeed(analogRead(0));
    soundModule.playRandomSound();

    vibrationModule.initialize();
    vibrationModule.playVibrationPatternAsync(1);

    // Initialize BLE.
    // bleModule.begin();

    // // Initialize OTA update
    // WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    // Serial.print("Connecting to WiFi");
    // while (WiFi.status() != WL_CONNECTED) {
    //     delay(500);
    //     Serial.print(".");
    // }

    // Start manual OTA update using the URL where the firmware is hosted.
    HTTPOTAUpdateModule::manualOTAUpdate("http://192.168.0.94:8080/firmware.bin");
}

void loop() {

    delay(10);  // Adjust delay as needed.

}


// 1. Firewall (UFW):
// Your Ubuntu machine might be blocking external connections on port 81. Check the status with:
// sudo ufw status
// 2. If the firewall is enabled, allow connections on port 81:
// sudo ufw allow 81/tcp
// 3. start local server in the folder with the firmware.bin
// npx http-server -p 8080
