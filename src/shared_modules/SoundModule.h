#ifndef SOUNDMODULE_H
#define SOUNDMODULE_H

#include <string>
#include <Arduino.h>
#include "freertos/FreeRTOS.h" // Include FreeRTOS definitions
#include "freertos/task.h"     // Include TaskHandle_t definition


// Other includes and declarations
void playSoundTask(void* parameter); // Declare the FreeRTOS task for playing sound

extern TaskHandle_t soundTaskHandle; // Declare the global handle as extern


class SoundModule {
public:
    void initializeAmplifier();
    void playSingleToneWithNewInstance(const std::string& fileName);
    void playAudioFile(const char* fileName);
    void deinitializeAmplifier();
    void playBeepI2S(uint32_t frequency, uint32_t duration_ms);
    void playSimultaneousDualToneI2S(uint32_t frequency1, uint32_t frequency2, uint32_t duration_ms);
    void playDualToneI2S(uint32_t frequency1, uint32_t frequency2, uint32_t toneDuration_ms, uint32_t pauseDuration_ms);

    // New function for sweep tone (outside-range alert)
    void playSweepToneI2S(uint32_t startFreq, uint32_t endFreq, uint32_t duration_ms);
    
    // Test function to try different options.
    void testToneOptions();

    // New R2D2 sound function:
    void playR2D2SoundI2S(uint8_t pattern);

    void playRandomSound();  // Add this declaration
};

#endif // SOUNDMODULE_H
