#include "OTAUpdateModule.h"
#include <WiFi.h>

namespace OTAUpdateModule {

    void setupOTA() {

        Serial.println("Start setting up OTA");
        // Set the OTA hostname (change "ESP32-S3" to something unique if needed)
        ArduinoOTA.setHostname("ESP32-S3");

        // Set an OTA password (change this to a secure value)
        ArduinoOTA.setPassword("yourOTApassword");

        // Callback when OTA update starts
        ArduinoOTA.onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH) {
                type = "sketch";
            } else { // U_SPIFFS or U_LITTLEFS
                type = "filesystem";
            }
            Serial.println("Start updating " + type);
        });

        // Callback when OTA update ends
        ArduinoOTA.onEnd([]() {
            Serial.println("\nOTA update complete.");
        });

        // Callback to report OTA progress
        ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("OTA Progress: %u%%\r", (progress * 100) / total);
        });

        // Callback if an OTA error occurs
        ArduinoOTA.onError([](ota_error_t error) {
            Serial.printf("OTA Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR) {
                Serial.println("Auth Failed");
            } else if (error == OTA_BEGIN_ERROR) {
                Serial.println("Begin Failed");
            } else if (error == OTA_CONNECT_ERROR) {
                Serial.println("Connect Failed");
            } else if (error == OTA_RECEIVE_ERROR) {
                Serial.println("Receive Failed");
            } else if (error == OTA_END_ERROR) {
                Serial.println("End Failed");
            }
        });

        // Start the OTA service
        ArduinoOTA.begin();
        Serial.println("OTA Ready");
    }

    void handleOTA() {
        ArduinoOTA.handle();
    }

} // namespace OTAUpdateModule
