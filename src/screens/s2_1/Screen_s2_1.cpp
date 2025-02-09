#include "Screen_s2_1.h"
#include <cstdio>
#include <Arduino.h>
#include "ui_callbacks/ScrollModuleMenue.h" // Include for configure_scroll_snapping_ui_menue and get_focused_element_name
#include <vector> // Include for vector container
#include "shared_modules/other.h"
#include "screenmanager/ScreenManager.h" // Include the ScreenManager
#include "shared_modules/other.h" // Include for ImageInfo and get_image_info

// Array of image info objects with associated callbacks
const screenMenueInfo image_infos_s2_1[] = {
    {"s2_1_cf", "Crit. Force", ScreenManager::showScreenS2_1,1},
    {"s2_1_max", "Max Force", ScreenManager::showScreenS2_1,2},
    {"s2_1_train", "Train", ScreenManager::showScreenS2_1,3},
    {"s2_1_sets", "Sets", ScreenManager::showScreenS2_1,4},
    {"s2_1_settings", "Settings", ScreenManager::showScreenS2_1,5},
};

// Make a context that points to it:
static FocusedLabelContext context = {
    image_infos_s2_1,
    sizeof(image_infos_s2_1)/sizeof(image_infos_s2_1[0])
};

static bool callbacks_already_attached = false;


static const char* last_displayed_name = nullptr; // Track the last displayed name


namespace Screen_s2_1 {

    void setup() {
        printf("Screen_s2_1::setup() called.\n");




        // Get the number of images from the array
        size_t image_count = sizeof(image_infos_s2_1) / sizeof(image_infos_s2_1[0]);


        last_displayed_name = nullptr;

    }

    void loop() {
        // Get the name of the currently focused element
        const char* focused_name = get_focused_element_name();
        if (focused_name) {
            // Get the corresponding screenMenueInfo object
            const screenMenueInfo* info = nullptr;
            // Iterate through all elements in the image_infos_s2_1 array
            for (size_t i = 0; i < sizeof(image_infos_s2_1) / sizeof(image_infos_s2_1[0]); ++i) {
                // Compare the internal_name of the current element with the focused_name
                if (strcmp(image_infos_s2_1[i].internal_name, focused_name) == 0) {
                    // If a match is found, store the address of the matched element in 'info'
                    info = &image_infos_s2_1[i];

                    // Exit the loop early since the desired element has been found
                    break;
                }
            }
            if (info) {
                // Update the label only if the name has changed
                if (info->displayed_name != last_displayed_name) {
                    Serial.printf("Currently focused element: %s (Displayed: %s)\n", focused_name, info->displayed_name);


                    // Update the last displayed name
                    last_displayed_name = info->displayed_name;
                }

            } else {
                Serial.printf("No ImageInfo found for: %s\n", focused_name);
            }
        } else {
            if (last_displayed_name != nullptr) {
                Serial.println("No element is currently in focus.");

                // Reset the last displayed name
                last_displayed_name = nullptr;
            }
        }
    }
}