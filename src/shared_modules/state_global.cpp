#include "state_global.h"
#include "shared_modules/FileSystemModule.h"
#include "SoundModule.h"

User* currentUser = &users[0]; // extern from helpers or wherever

// Define the global instance
global_State g_global_State;

// Define the global instance of SoundModule
SoundModule soundModule;

// Define the global instance of SoundModule
VibrationModule vibrationModule;

// Define the single global
TrainingState g_trainingState;

// Create an instance of the BLEModule.
BLEModule bleModule("MONKI");
