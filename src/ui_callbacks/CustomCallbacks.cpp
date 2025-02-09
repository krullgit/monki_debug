#include "lvgl.h"
#include <cstdio>
#include <Arduino.h>
#include "../screenmanager/ScreenManager.h"


void gesture_event_cb(lv_event_t *e, void (*left_callback)(), void (*right_callback)()) {
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    // Serial.printf("Gesture detected: %d\n", dir); // Debugging gesture direction

    // Check for left or right gestures and trigger callbacks
    if (dir == LV_DIR_LEFT && left_callback) {
        // Serial.println("Navigating left.");
        left_callback();
    } else if (dir == LV_DIR_RIGHT && right_callback) {
        // Serial.println("Navigating right.");
        right_callback();
    } else {
        Serial.println("No navigation triggered.");
    }
}

