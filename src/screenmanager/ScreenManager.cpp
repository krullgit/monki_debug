#include "../screenmanager/ScreenManager.h"

#include "screens/s2_1/Screen_s2_1.h"

#include <cstdio>

#include "shared_modules/DisplayModule.h"
#include <Arduino_GFX_Library.h>
#include "Arduino_DriveBus_Library.h"

// Static member definitions
void (*ScreenManager::currentLoop)() = nullptr;
lv_obj_t *ScreenManager::currentScreen = nullptr;


void ScreenManager::showScreenS2_1() {
   
    Screen_s2_1::setup();          // Call setup to attach callbacks
    currentLoop = Screen_s2_1::loop; // Set the loop function
    
}



void ScreenManager::doNothing() {

}


void ScreenManager::loop() {
    if (currentLoop) {
        currentLoop(); // Call the loop function of the current screen
    }
}

void ScreenManager::callLoop() {
    if (currentLoop) {
        currentLoop(); // Safely call the current screen's loop function
    }
}
