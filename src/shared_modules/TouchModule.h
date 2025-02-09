#ifndef TOUCHMODULE_H
#define TOUCHMODULE_H

#include <lvgl.h>
#include <memory>
#include "Arduino_DriveBus_Library.h"

// Declare the external touch controller object
extern std::unique_ptr<Arduino_IIC> FT3168;

// Function declaration for the LVGL touchpad read callback
void touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

#endif // TOUCHMODULE_H
