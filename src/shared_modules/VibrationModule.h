#ifndef VIBRATIONMODULE_H
#define VIBRATIONMODULE_H

#include <Arduino.h>

#define VIBRATION_PIN 48  // Define the vibration motor output pin

class VibrationModule {
public:
    VibrationModule();

    // Call this once in setup() to configure the vibration pin.
    void initialize();

    // Blocking function: Plays a vibration pattern based on the passed pattern number.
    void playVibrationPattern(uint8_t pattern);

    // Asynchronous function: Spawns a task to play the vibration pattern.
    void playVibrationPatternAsync(uint8_t pattern);

    // (Optional) You can add additional helper methods if desired.
};

#endif // VIBRATIONMODULE_H
