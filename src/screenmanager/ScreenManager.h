#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "lvgl.h"

class ScreenManager {
public:
    static void showScreenMain();  // Navigate to Main Screen
    static void showScreenS1_2();  
    static void showScreenS1_3();  
    static void showScreenS2_1();  
    static void showScreenS3_1();  
    static void showScreenS3_2();  
    static void showScreenS4_1();  
    static void showScreenS4_2();  
    static void showScreenS4_3(); 
    static void showScreenS4_4(); 
    static void showScreenS5_1();  
    static void showScreenS5_2();  
    static void showScreenS5_3();  
    static void showScreenS5_4(); 
    static void showScreenS5_5(); 
    static void showScreenS6_1(); 
    static void showScreenS6_2(); 
    static void showScreenS6_3(); 
    static void showScreenS6_4(); 
    static void showScreenS6_5(); 
    static void showScreenS6_6(); 
    static void showScreenS6_7(); 
    static void showScreenS6_8(); 
    static void showScreenS6_9();
    static void showScreenS7_1(); 
    static void showScreenS7_2(); 
    static void showScreenS7_3(); 
    static void showScreenS7_4(); 
    static void showScreenS7_5(); 
    static void showScreenS7_6(); 
    static void showScreenS7_7(); 
    static void showScreenS10_1();  
    static void doNothing();  
    static void loop();            // Handle the current screen's loop
    static void callLoop();        // Safely call the loop function

    static lv_obj_t *currentScreen; // Pointer to the currently active screen (accessible to other files)

private:
    static void (*currentLoop)();  // Pointer to the current loop function
};

#endif // SCREEN_MANAGER_H
