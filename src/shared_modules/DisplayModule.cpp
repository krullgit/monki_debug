#include "DisplayModule.h"

// LVGL display flush callback function
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int32_t w = (area->x2 - area->x1 + 1);
    int32_t h = (area->y2 - area->y1 + 1);

    gfx->startWrite();
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)color_p, w, h);
    gfx->endWrite();

    lv_disp_flush_ready(disp); // Indicate that flushing is done
}


void set_oled_brightness(int brightness) {
    // Clamp brightness to a minimum of 20
    int effectiveBrightness = (brightness < 20) ? 20 : brightness;

    // Map roller value from 20–99 to 0–255
    int mappedBrightness = map(effectiveBrightness, 0, 100, 0, 250);
    gfx->Display_Brightness(mappedBrightness); // Set brightness
    Serial.printf("OLED brightness set to: %d (clamped from %d)\n", mappedBrightness, brightness);
}

