#ifndef CUSTOM_CALLBACKS_H
#define CUSTOM_CALLBACKS_H

#include "lvgl.h"

void gesture_event_cb(lv_event_t *e, void (*left_screen_callback)(), void (*right_screen_callback)());

#endif
