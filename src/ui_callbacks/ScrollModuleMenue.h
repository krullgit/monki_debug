#ifndef SCROLL_MODULE_MENUE_H
#define SCROLL_MODULE_MENUE_H

#include <lvgl.h>
#include <map>
#include <string>

// Function to configure snapping behavior and dynamically add images
void configure_scroll_snapping_ui_menue(lv_obj_t *panel, lv_obj_t *focus_ring, const char *image_names[], size_t image_count);


// Function to get the name of the currently focused element
const char* get_focused_element_name();

void focussed_label_event_cb(lv_event_t * e);

// Declare the mapping between screen names and state variables
extern std::map<std::string, size_t*> screenStateMapping;

// Updated ImageInfo struct to include `sessionID`
struct screenMenueInfo {
    const char* internal_name;       // Internal identifier for the image
    const char* displayed_name;     // Default displayed name (fallback if not in `sessions`)
    void (*callback)();             // Callback function to call when selected
    int infoID;                  // Set ID associated with the image
};

struct FocusedLabelContext {
    const screenMenueInfo* menueInfos;  // e.g. pointer to the screen's array of ImageInfo
    size_t imageCount;                 // how many items are in that array
};

#endif // SCROLL_MODULE_MENUE_H
