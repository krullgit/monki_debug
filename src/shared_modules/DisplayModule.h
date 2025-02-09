#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include <lvgl.h>
#include <Arduino_GFX_Library.h>

// Declare the external gfx object to be used in the flush function
extern Arduino_GFX *gfx;

// Function declaration for the LVGL display flush callback
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

void set_oled_brightness(int brightness);

#endif // DISPLAYMODULE_H

