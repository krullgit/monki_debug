#pragma once

#include <Arduino.h> // Or <string> if you’re not using Arduino
                     // but need String functionality.

#include "shared_modules/FileSystemModule.h" // <-- Adjust to where you define "User", "GripType", etc.
#include "SoundModule.h"
#include "VibrationModule.h"
#include "BLEModule.h"

extern User* currentUser;

// Global State for Screen s7_3
struct global_State {
    size_t scroll_s2_1 = 2;
    size_t scroll_s3_1 = 0;
    size_t scroll_s4_1 = 0;
    size_t scroll_s5_1 = 0;
    size_t scroll_s5_2 = 1; 
    size_t scroll_s6_1 = 0;
    size_t scroll_s7_1 = 0;
};

// Declare a single global instance of the state (extern keyword ensures only one definition exists)
extern global_State g_global_State;

// Create a global instance of SoundModule
extern SoundModule soundModule;

extern VibrationModule vibrationModule;

extern BLEModule bleModule;

// A simple struct to hold the current training status
struct TrainingState {
    Session currentSession;
    Set currentSet;
    int currentSetInSessionIndex = 0;
    int currentComboIndex = 0;
    bool sessionActive = false;
    int remainingTimeTrain = 0;
};

// Extern a single global instance (so only one copy in your project)
extern TrainingState g_trainingState;