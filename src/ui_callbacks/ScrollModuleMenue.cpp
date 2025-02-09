#include "ScrollModuleMenue.h"
#include <Arduino.h> // For Serial debugging
#include "screenmanager/ScreenManager.h" // Include the ScreenManager


#include <map>
#include <string>


// Keep track of the last focused element name
static const char* focused_element_name = nullptr;
// Function to get the currently focused element name
const char* get_focused_element_name() {
    return focused_element_name;
}

// Keep track of the last focused child index
static int last_focused_child_index = -1;

void snap_event_cb_menue(lv_event_t *e) {
    lv_obj_t *focus_ring = static_cast<lv_obj_t*>(lv_event_get_user_data(e));
    lv_obj_t *panel      = lv_event_get_target(e);

    lv_coord_t panel_height = lv_obj_get_height(panel);
    lv_coord_t scroll_y     = lv_obj_get_scroll_y(panel);
    lv_coord_t panel_center = scroll_y + panel_height / 2;

    uint32_t child_count = lv_obj_get_child_cnt(panel);
    lv_obj_t *focused_child = nullptr;

    const lv_coord_t focus_threshold = 0;
    int new_focused_index = -1; // Assume none is focused

    // Loop through children to find which one is centered (within threshold)
    for (uint32_t i = 0; i < child_count; i++) {
        lv_obj_t *child = lv_obj_get_child(panel, i);
        lv_coord_t child_center = lv_obj_get_y(child) + lv_obj_get_height(child) / 2;

        if (abs(child_center - panel_center) <= focus_threshold) {
            focused_child = child;
            new_focused_index = i;
            break;
        }
    }

    if (focused_child) {
        // Show or hide the ring based on the element’s user data
        const char *element_name = static_cast<const char*>(lv_obj_get_user_data(focused_child));
        if (element_name && strcmp(element_name, "fake_scroll_element") == 0) {
            Serial.println("SCROLLMODULEMENUE: Focused element is 'fake_scroll_element'. Hiding focus ring.");
            lv_obj_add_flag(focus_ring, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_clear_flag(focus_ring, LV_OBJ_FLAG_HIDDEN);
        }

        
    } else {
        // No child is in focus: Hide the focus ring
        lv_obj_add_flag(focus_ring, LV_OBJ_FLAG_HIDDEN);

        // If we previously had something focused and now have none, reset
        if (last_focused_child_index != -1) {
            last_focused_child_index = -1;
            focused_element_name = nullptr;
            Serial.println("SCROLLMODULEMENUE: Focus left all children (no child in focus now).");
        }
    }
}






void focussed_label_event_cb(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        // 1) Recover our user data (the context)
        FocusedLabelContext* ctx = 
            static_cast<FocusedLabelContext*>(lv_event_get_user_data(e));
        if (!ctx) return; // safety check

        // 2) Name of the currently focused element
        const char* name = get_focused_element_name();
        if (!name) return;

    }
}
