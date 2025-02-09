#include "VibrationModule.h"
#include <Arduino.h>
#include <stdlib.h>

// For FreeRTOS on ESP32, include the task header if needed.
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"

VibrationModule::VibrationModule() {
    // Constructor: Initialize any internal state if needed.
}

void VibrationModule::initialize() {
    // Configure the vibration pin as an OUTPUT and ensure it is off.
    pinMode(VIBRATION_PIN, OUTPUT);
    digitalWrite(VIBRATION_PIN, LOW);
}

void VibrationModule::playVibrationPattern(uint8_t pattern) {
    // Use a switch statement to define different vibration patterns.
    switch (pattern) {
        case 1:
            // Pattern 1: Double pulse
            digitalWrite(VIBRATION_PIN, HIGH);
            delay(300);
            digitalWrite(VIBRATION_PIN, LOW);
            delay(50);
            digitalWrite(VIBRATION_PIN, HIGH);
            delay(300);
            digitalWrite(VIBRATION_PIN, LOW);
            delay(50);
            break;

        case 2:
            // Pattern 2: Single long pulse
            digitalWrite(VIBRATION_PIN, HIGH);
            delay(500);
            digitalWrite(VIBRATION_PIN, LOW);
            delay(100);
            break;

        case 3:
            // Pattern 3: Three rapid pulses
            for (int i = 0; i < 3; i++) {
                digitalWrite(VIBRATION_PIN, HIGH);
                delay(100);
                digitalWrite(VIBRATION_PIN, LOW);
                delay(50);
            }
            break;

        case 4:
            // Pattern 4: Five very short pulses
            for (int i = 0; i < 5; i++) {
                digitalWrite(VIBRATION_PIN, HIGH);
                delay(50);
                digitalWrite(VIBRATION_PIN, LOW);
                delay(50);
            }
            break;

        default:
            // Default pattern: a simple single pulse.
            digitalWrite(VIBRATION_PIN, HIGH);
            delay(200);
            digitalWrite(VIBRATION_PIN, LOW);
            delay(50);
            break;
    }
}

// --- Asynchronous Vibration Playback ---

// Define a structure to hold task parameters.
struct VibrationTaskParams {
    VibrationModule* module;  // Pointer to the VibrationModule instance.
    uint8_t pattern;          // The vibration pattern to play.
};

// Static task function that calls the blocking playVibrationPattern().
static void VibrationTask(void* param) {
    VibrationTaskParams* params = (VibrationTaskParams*) param;
    // Call the blocking function to play the pattern.
    params->module->playVibrationPattern(params->pattern);
    free(params);            // Free the allocated memory.
    vTaskDelete(NULL);       // Delete this task.
}

void VibrationModule::playVibrationPatternAsync(uint8_t pattern) {
    // Allocate memory for the task parameters.
    VibrationTaskParams* params = (VibrationTaskParams*) malloc(sizeof(VibrationTaskParams));
    if (params != NULL) {
        params->module = this;  // Pass the current instance.
        params->pattern = pattern;
        // Create the task.
        // Adjust stack size (here 2048 bytes) and priority as needed.
        xTaskCreate(VibrationTask, "VibrationTask", 2048, params, 1, NULL);
    }
}
