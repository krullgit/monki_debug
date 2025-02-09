#include "SoundModule.h"

#include "AudioTools.h"

#include <math.h>

I2SStream i2s;


TaskHandle_t soundTaskHandle = nullptr; // Global handle for the sound task

void SoundModule::initializeAmplifier() {
  // Initialize the audio logger (set verbosity as needed)
  AudioToolsLogger.begin(Serial, AudioToolsLogLevel::Warning);

  // Configure I2S in TX (transmit) mode and start it.
  auto cfg = i2s.defaultConfig(TX_MODE);
  i2s.begin(cfg);
}
#include <EEPROM.h>

// Assume LAST_PATTERN_ADDR is defined (e.g., #define LAST_PATTERN_ADDR 0)

struct SoundTaskParams {
    class SoundModule* module;  // Pointer to the SoundModule instance
    int pattern;                // The chosen pattern number
};

static void SoundTask(void* param) {
    SoundTaskParams* params = (SoundTaskParams*) param;
    // Call the method on the instance pointer
    params->module->playR2D2SoundI2S(params->pattern);
    free(params); // Free the allocated memory for the parameters
    vTaskDelete(NULL); // Delete this task
}

#define LAST_PATTERN_ADDR 0

void SoundModule::playRandomSound() {
    // Define your list of pattern numbers.
    int patterns[] = {1, 2, 6, 24, 27};
    int numPatterns = sizeof(patterns) / sizeof(patterns[0]);

    // Read the last played pattern from EEPROM.
    int lastPattern = EEPROM.read(LAST_PATTERN_ADDR);

    // Choose a random pattern, reselect if it's the same as the last.
    int randomIndex = random(numPatterns);
    int chosenPattern = patterns[randomIndex];
    while(chosenPattern == lastPattern && numPatterns > 1) {
        randomIndex = random(numPatterns);
        chosenPattern = patterns[randomIndex];
    }

    // Store the chosen pattern in EEPROM.
    EEPROM.write(LAST_PATTERN_ADDR, chosenPattern);
    EEPROM.commit();  // For ESP32; on some platforms this may not be needed

    Serial.print("Random pattern chosen: ");
    Serial.println(chosenPattern);

    // Allocate the parameters for the task.
    SoundTaskParams* params = (SoundTaskParams*) malloc(sizeof(SoundTaskParams));
    if (params != NULL) {
        params->module = this;       // Pass the current instance
        params->pattern = chosenPattern;
        // Create the asynchronous task.
        // Adjust the stack size (here 4096 bytes) and priority as needed.
        xTaskCreate(SoundTask, "SoundTask", 4096, params, 1, NULL);
    }
}

// Define the sample rate that your I2S configuration is using.
// Adjust this if your I2S stream uses a different rate.
const uint32_t SAMPLE_RATE = 96000;

// This function generates a sine wave beep of the given frequency and duration (in milliseconds)
// and writes it out via the I2S stream (assumed to be the global object 'i2s').
void SoundModule::playBeepI2S(uint32_t frequency, uint32_t duration_ms) {
  // Define a global or local amplitude factor (max 32767 for full scale)
  const int16_t maxAmplitude = 8000;  // Adjust this value as needed

  // To avoid allocating a very large buffer, we generate and write audio in small chunks.
  const size_t chunkSize = 256;   // number of samples per chunk
  int16_t chunk[chunkSize];       // 16-bit PCM samples (typical for MAX98357)

  // Calculate total number of samples for the given duration.
  uint32_t totalSamples = (duration_ms * SAMPLE_RATE) / 1000;

  // Setup a phase accumulator for the sine wave.
  float phase = 0.0;
  float phaseIncrement = 2.0 * PI * frequency / SAMPLE_RATE;

  // Loop until all samples are generated and written.
  while (totalSamples > 0) {
    // Determine how many samples to generate in this chunk.
    size_t n = (totalSamples > chunkSize) ? chunkSize : totalSamples;
    for (size_t i = 0; i < n; i++) {

      // Then, in your sine generation loop:
      chunk[i] = (int16_t)(maxAmplitude * sin(phase));
      phase += phaseIncrement;
      // Wrap the phase to keep it within 0 to 2π.
      if (phase >= 2.0 * PI) {
        phase -= 2.0 * PI;
      }
    }
    // Write the generated samples to the I2S stream.
    // (Ensure that your 'i2s' object is already configured and running.)
    size_t bytesToWrite = n * sizeof(int16_t);
    size_t bytesWritten = i2s.write((const uint8_t*)chunk, bytesToWrite);

    // Optionally, you could check that bytesWritten == bytesToWrite.

    totalSamples -= n;
  }
}

//---------------------------------------------------------------------
// Helper Function: playToneSegmentI2S
//
// Plays a tone segment with a frequency sweep from startFreq to endFreq,
// over duration_ms milliseconds at the specified amplitude.
// This function processes audio in small chunks to conserve RAM.
//---------------------------------------------------------------------
static void playToneSegmentI2S(uint32_t startFreq, uint32_t endFreq, uint32_t duration_ms, int16_t amplitude) {
    const size_t chunkSize = 256;
    int16_t chunk[chunkSize];
    uint32_t totalSamples = (duration_ms * SAMPLE_RATE) / 1000;
    uint32_t samplesProcessed = 0;
    float phase = 0.0;

    // Set fade duration (in ms) and compute fadeSamples.
    const uint32_t fadeDuration_ms = 20; // adjust as needed
    uint32_t fadeSamples = (fadeDuration_ms * SAMPLE_RATE) / 1000;
    if (fadeSamples > totalSamples / 2) {
        fadeSamples = totalSamples / 2;
    }

    // Make sure startFreq is not zero to avoid division by zero.
    float start = (float)startFreq;
    float end   = (float)endFreq;
    
    while (totalSamples > 0) {
        size_t n = (totalSamples > chunkSize) ? chunkSize : totalSamples;
        for (size_t i = 0; i < n; i++) {
            // Calculate t as the fraction of the total duration elapsed.
            float t = (float)samplesProcessed / ((duration_ms * SAMPLE_RATE) / 1000.0);
            // Exponential (logarithmic) interpolation for frequency:
            // currentFreq = start * (end / start)^t
            float currentFreq = start * pow(end / start, t);
            float phaseIncrement = 2.0 * PI * currentFreq / SAMPLE_RATE;
            
            // Apply an amplitude envelope to smooth the start and end.
            float env = 1.0;
            if (samplesProcessed < fadeSamples) {
                env = (float)samplesProcessed / fadeSamples;
            } else if (samplesProcessed > ((duration_ms * SAMPLE_RATE) / 1000 - fadeSamples)) {
                env = (float)(((duration_ms * SAMPLE_RATE) / 1000) - samplesProcessed) / fadeSamples;
            }
            
            chunk[i] = (int16_t)(amplitude * env * sin(phase));
            phase += phaseIncrement;
            if (phase >= 2.0 * PI) {
                phase -= 2.0 * PI;
            }
            samplesProcessed++;
        }
        size_t bytesToWrite = n * sizeof(int16_t);
        i2s.write((const uint8_t*)chunk, bytesToWrite);
        totalSamples -= n;
    }
}




//---------------------------------------------------------------------
// New function: Plays a frequency sweep tone from startFreq to endFreq.
// This will be our outside-range alert.
//---------------------------------------------------------------------
void SoundModule::playSweepToneI2S(uint32_t startFreq, uint32_t endFreq, uint32_t duration_ms) {
    const size_t chunkSize = 256;
    int16_t chunk[chunkSize];
    uint32_t totalSamples = (duration_ms * SAMPLE_RATE) / 1000;
    uint32_t samplesProcessed = 0;
    float phase = 0.0;
    // Adjust amplitude as needed (here using the same level as playBeepI2S).
    const int16_t amplitude = 16384;
    
    // Process the audio in chunks.
    while (totalSamples > 0) {
        size_t n = (totalSamples > chunkSize) ? chunkSize : totalSamples;
        for (size_t i = 0; i < n; i++) {
            // Calculate the fraction of the total duration that has passed.
            float t = (float)samplesProcessed / ((duration_ms * SAMPLE_RATE) / 1000);
            // Linearly interpolate the current frequency.
            float currentFreq = startFreq + (endFreq - startFreq) * t;
            float phaseIncrement = 2.0 * PI * currentFreq / SAMPLE_RATE;
            chunk[i] = (int16_t)(amplitude * sin(phase));
            phase += phaseIncrement;
            if (phase >= 2.0 * PI) {
                phase -= 2.0 * PI;
            }
            samplesProcessed++;
        }
        size_t bytesToWrite = n * sizeof(int16_t);
        i2s.write((const uint8_t*)chunk, bytesToWrite);
        totalSamples -= n;
    }
}

// this function make tones sound smoother for some reason
void playSilenceI2S(uint32_t duration_ms) {
    const size_t chunkSize = 256;
    int16_t chunk[chunkSize] = {0}; // a chunk of zeros
    uint32_t totalSamples = (duration_ms * SAMPLE_RATE) / 1000;
    while(totalSamples > 0) {
        size_t n = (totalSamples > chunkSize) ? chunkSize : totalSamples;
        size_t bytesToWrite = n * sizeof(int16_t);
        i2s.write((const uint8_t*)chunk, bytesToWrite);
        totalSamples -= n;
    }
}

// this function make tones sound smoother for some reason
void playBeepWithEnvelopeI2S(uint32_t frequency, uint32_t duration_ms, int16_t amplitude) {
    // Use the tone segment function with the same start and end frequency.
    playToneSegmentI2S(frequency, frequency, duration_ms, amplitude);
}


//---------------------------------------------------------------------
// Expanded Function: playR2D2SoundI2S
//
// Plays one of several R2D2-like sound patterns using different
// combinations of beeps, frequency sweeps, and silences.
//---------------------------------------------------------------------
void SoundModule::playR2D2SoundI2S(uint8_t pattern) {
    int16_t amplitude = 4096;  // You can adjust this value for volume
    switch(pattern) {
        case 1:
            Serial.println("Playing R2D2 Pattern 1: Upward sweep, downward sweep, constant beep");
            playToneSegmentI2S(800, 1400, 100, amplitude);
            playSilenceI2S(50);
            playToneSegmentI2S(1400, 600, 100, amplitude);
            playSilenceI2S(50);
            playToneSegmentI2S(800, 800, 100, amplitude);
            break;

        case 3:
            Serial.println("Playing R2D2 Pattern 3: Long ascending and descending sweep");
            playToneSegmentI2S(600, 1800, 300, amplitude);
            playSilenceI2S(50);
            playToneSegmentI2S(1800, 800, 100, amplitude);
            break;

        case 6:
            Serial.println("Playing R2D2 Pattern 6: Randomized micro-modulations");
            playToneSegmentI2S(950, 1150, 40, amplitude);
            playSilenceI2S(10);
            playToneSegmentI2S(1150, 850, 40, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1000, 40, amplitude);  // now with envelope
            playSilenceI2S(10);
            playToneSegmentI2S(1000, 1300, 40, amplitude);
            playSilenceI2S(10);
            playToneSegmentI2S(1300, 800, 40, amplitude);
            break;

        case 8:
            Serial.println("Playing R2D2 Pattern 8: Rapid sequence of micro sweeps");
            // Four rapid iterations of a micro upward and downward sweep.
            for (int i = 0; i < 4; i++) {
                playToneSegmentI2S(950, 1150, 30, amplitude);
                playSilenceI2S(10);
                playToneSegmentI2S(1150, 850, 30, amplitude);
                playSilenceI2S(10);
            }
            break;

        case 11:
            Serial.println("Playing R2D2 Pattern 11: Alternating sweeps with variable durations");
            // Alternating segments with different durations and sweep directions.
            playToneSegmentI2S(800, 1300, 80, amplitude);
            playSilenceI2S(15);
            playToneSegmentI2S(1300, 700, 60, amplitude);
            playSilenceI2S(15);
            playToneSegmentI2S(700, 1100, 100, amplitude);
            break;
        case 13:
            // Joyful – Ascending playful chirps.
            Serial.println("Playing R2D2 Pattern 13: Joyful - Ascending playful chirps");
            playToneSegmentI2S(800, 1200, 80, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1200, 40, amplitude);  // now with envelope
            playSilenceI2S(10);
            playToneSegmentI2S(1200, 1400, 80, amplitude);
            break;

        case 14:
            // Melancholic – Slow, descending tones with a lingering beep.
            Serial.println("Playing R2D2 Pattern 14: Melancholic - Slow descending with a lingering tone");
            playToneSegmentI2S(1100, 600, 200, amplitude);
            playSilenceI2S(20);
            playBeepWithEnvelopeI2S(600, 150, amplitude);  // now with envelope
            break;

        case 15:
            // Angry – Rapid staccato bursts with harsh sweeps.
            Serial.println("Playing R2D2 Pattern 15: Angry - Rapid staccato bursts");
            for (int i = 0; i < 4; i++) {
                playToneSegmentI2S(1000, 700, 40, amplitude);
                playSilenceI2S(10);
                playToneSegmentI2S(700, 1100, 40, amplitude);
                playSilenceI2S(10);
            }
            break;

        case 16:
            // Surprised – A sudden high beep followed by a quick, sharp sweep.
            Serial.println("Playing R2D2 Pattern 16: Surprised - Sudden high beep and quick sweep");
            playBeepWithEnvelopeI2S(1400, 50, amplitude);  // add envelope to the beep
            playSilenceI2S(10);
            playToneSegmentI2S(1400, 900, 70, amplitude);
            break;

        case 17:
            // Calm – Gentle, slowly evolving tones with soft transitions.
            Serial.println("Playing R2D2 Pattern 17: Calm - Gentle slow-evolving tone");
            playToneSegmentI2S(800, 1000, 300, amplitude);
            playSilenceI2S(50);
            playToneSegmentI2S(1000, 800, 300, amplitude);
            break;

        case 18:
            // Mysterious – A low rumble that rises into an eerie tone.
            Serial.println("Playing R2D2 Pattern 18: Mysterious - Low rumble with rising eerie tone");
            playToneSegmentI2S(600, 800, 150, amplitude);
            playSilenceI2S(20);
            playToneSegmentI2S(800, 1300, 150, amplitude);
            break;

        case 19:
            // Excited – Quick oscillating beeps and micro-sweeps.
            Serial.println("Playing R2D2 Pattern 19: Excited - Quick oscillations");
            for (int i = 0; i < 3; i++) {
                playBeepWithEnvelopeI2S(1000, 30, amplitude);
                playSilenceI2S(10);
                playToneSegmentI2S(1000, 1200, 30, amplitude);
                playSilenceI2S(10);
                playBeepWithEnvelopeI2S(1200, 30, amplitude);
                playSilenceI2S(10);
            }
            break;

        case 20:
            // Reflective – A slow, echoing tone with a delayed resolution.
            Serial.println("Playing R2D2 Pattern 20: Reflective - Slow echo with delayed resolution");
            playToneSegmentI2S(900, 700, 250, amplitude);
            playSilenceI2S(30);
            playBeepWithEnvelopeI2S(700, 100, amplitude);
            break;
         case 21:
            Serial.println("Playing R2D2 Pattern 21: Happy - Sparkling Ascending Chirps");
            // A series of three short, rising chirps with a brief pause in between.
            for (int i = 0; i < 3; i++) {
                playToneSegmentI2S(800, 1200, 50, amplitude);
                playSilenceI2S(10);
                // A short constant tone with envelope for extra sparkle.
                playBeepWithEnvelopeI2S(1200, 40, amplitude);
                playSilenceI2S(20);
            }
            break;

        case 22:
            Serial.println("Playing R2D2 Pattern 22: Happy - Bouncy Upbeat Melody");
            // Play an upward sweep followed by a quick, bouncy beep and then a descending sweep.
            playToneSegmentI2S(750, 1300, 80, amplitude);
            playSilenceI2S(15);
            playBeepWithEnvelopeI2S(1300, 50, amplitude);
            playSilenceI2S(15);
            playToneSegmentI2S(1300, 900, 80, amplitude);
            playSilenceI2S(30);
            // Repeat once for a short melody.
            playToneSegmentI2S(750, 1300, 80, amplitude);
            playSilenceI2S(15);
            playBeepWithEnvelopeI2S(1300, 50, amplitude);
            playSilenceI2S(15);
            playToneSegmentI2S(1300, 900, 80, amplitude);
            break;

        case 23:
            Serial.println("Playing R2D2 Pattern 23: Happy - Playful Bounce");
            // A rapid sequence of micro chirps that alternate in a bouncing fashion.
            for (int i = 0; i < 4; i++) {
                playToneSegmentI2S(900, 1100, 30, amplitude);
                playSilenceI2S(10);
                playToneSegmentI2S(1100, 900, 30, amplitude);
                playSilenceI2S(15);
            }
            break;

        case 24:
            Serial.println("Playing R2D2 Pattern 24: Happy - Cheerful Cascade");
            // A cascade of quick, rising micro-sweeps that resolve into a bright beep.
            playToneSegmentI2S(800, 1000, 40, amplitude);
            playSilenceI2S(10);
            playToneSegmentI2S(1000, 1200, 40, amplitude);
            playSilenceI2S(10);
            playToneSegmentI2S(1200, 1400, 40, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1400, 60, amplitude);
            break;
        case 25:
            Serial.println("Playing R2D2 Pattern 25: Happy - Rapid Sparkle with Soft Pulse");
            // A rapid sequence of micro beeps and short upward sweeps
            for (int i = 0; i < 5; i++) {
                playBeepWithEnvelopeI2S(1100, 20, amplitude);
                playSilenceI2S(5);
                playToneSegmentI2S(1100, 1200, 30, amplitude);
                playSilenceI2S(10);
            }
            break;

        case 26:
            Serial.println("Playing R2D2 Pattern 26: Happy - Alternating Chirp Cascade");
            // Alternating short sweeps that bounce upward and downward, finishing with a burst.
            for (int i = 0; i < 4; i++) {
                playToneSegmentI2S(900, 1100, 40, amplitude);
                playSilenceI2S(10);
                playToneSegmentI2S(1100, 900, 40, amplitude);
                playSilenceI2S(15);
            }
            playBeepWithEnvelopeI2S(1000, 50, amplitude);
            break;

        case 27:
            Serial.println("Playing R2D2 Pattern 27: Happy - Cheery Arpeggio");
            // Mimic a rising arpeggio: a sequence of beeps in ascending order followed by a resolving sweep.
            playBeepWithEnvelopeI2S(800, 40, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1000, 40, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1200, 40, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1400, 40, amplitude);
            playSilenceI2S(20);
            playToneSegmentI2S(1400, 900, 80, amplitude);
            break;

        case 28:
            Serial.println("Playing R2D2 Pattern 28: Happy - Joyful Whistle");
            // A “whistle” effect: an ascending sweep to a bright tone followed by a descending sweep.
            playToneSegmentI2S(1200, 1500, 100, amplitude);
            playSilenceI2S(10);
            playBeepWithEnvelopeI2S(1500, 60, amplitude);
            playSilenceI2S(10);
            playToneSegmentI2S(1500, 1300, 80, amplitude);
            break;

        // ===== Inside Range Options (Affirmative, "good" signals) =====

        case 29:
            Serial.println("Playing R2D2 Pattern 29: Inside Range Option - Light Upward Chirp");
            // A very short upward chirp with a smooth envelope.
            // This starts at 950 Hz and rises to 1100 Hz over 30 ms.
            playToneSegmentI2S(950, 1100, 30, amplitude);
            break;

        case 30:
            Serial.println("Playing R2D2 Pattern 30: Inside Range Option - Gentle Affirmative Ping");
            // A single crisp ping at a bright tone.
            // Using an envelope (via playBeepWithEnvelopeI2S) avoids abrupt onset.
            playBeepWithEnvelopeI2S(1050, 30, amplitude);
            break;

        case 31:
            Serial.println("Playing R2D2 Pattern 31: Inside Range Option - Quick Ascending Ping Pair");
            // Two very short elements:
            // First, a brief upward sweep from 900 Hz to 1000 Hz (20 ms),
            // followed by a tiny silence and then a short ping at 1100 Hz.
            playToneSegmentI2S(900, 1000, 20, amplitude);
            playSilenceI2S(5);
            playBeepWithEnvelopeI2S(1100, 20, amplitude);
            break;

        case 32:
            Serial.println("Playing R2D2 Pattern 32: Inside Range Option - Soft Resolving Chirp");
            // A two-part signal:
            // An upward sweep from 920 Hz to 1080 Hz (25 ms),
            // followed immediately by a constant tone at 1080 Hz for 25 ms.
            playToneSegmentI2S(920, 1080, 25, amplitude);
            playSilenceI2S(5);
            playBeepWithEnvelopeI2S(1080, 25, amplitude);
            break;

        // ===== Outside Range Options (Alert, "not good" signals) =====

        case 33:
            Serial.println("Playing R2D2 Pattern 33: Outside Range Option 1 - Rapid Alert Sweep");
            // A quick sweep from low to high to signal an out-of-range condition
            playToneSegmentI2S(600, 1400, 40, amplitude);
            break;

        case 34:
            Serial.println("Playing R2D2 Pattern 34: Outside Range Option 2 - Sharp Descending Chirp");
            // A rapid descending chirp that feels alerting
            playToneSegmentI2S(1400, 800, 30, amplitude);
            break;

        case 35:
            Serial.println("Playing R2D2 Pattern 35: Outside Range Option 3 - Quick Alert Ping");
            // A pair of very short pings that together create an urgent sound
            playBeepWithEnvelopeI2S(800, 30, amplitude);
            playSilenceI2S(5);
            playBeepWithEnvelopeI2S(800, 30, amplitude);
            break;

        case 36:
            Serial.println("Playing R2D2 Pattern 36: Outside Range Option 4 - Micro Staccato Alert");
            // Two rapid alternating sweeps to signal an alert condition
            playToneSegmentI2S(1300, 900, 25, amplitude);
            playSilenceI2S(5);
            playToneSegmentI2S(900, 1300, 25, amplitude);
            break;
        
        default:
            Serial.println("Unknown pattern, defaulting to Pattern 1");
            playToneSegmentI2S(800, 1400, 100, amplitude);
            playSilenceI2S(50);
            playToneSegmentI2S(1400, 600, 100, amplitude);
            playSilenceI2S(50);
            playToneSegmentI2S(800, 800, 100, amplitude);
            break;
    }
}

//---------------------------------------------------------------------
// UNUSED
// tone - general
//---------------------------------------------------------------------


// Test function: Plays your preferred inside-range tone followed by
// an outside-range alert tone (using a frequency sweep).
void SoundModule::testToneOptions() {
    // --- Inside Range Option ---
    // Option 3 (from your previous set) is:
    // "Inside Option 3: 900 Hz then 1100 Hz, tone: 250ms, pause: 100ms"
    Serial.println("=== Inside Range Option ===");
    Serial.println("Inside Option 3: 900 Hz then 1100 Hz (250ms each, 100ms pause)");
    playDualToneI2S(900, 1100, 250, 100);
    delay(1000); // Delay between options
    
    // --- Outside Range Option ---
    // Instead of two fixed tones, we now use a frequency sweep.
    // For example, we sweep from 500 Hz to 1500 Hz over 300ms.
    Serial.println("=== Outside Range Option ===");
    Serial.println("Frequency Sweep: from 500 Hz to 1500 Hz over 300ms");
    playSweepToneI2S(500, 1500, 300);
    delay(1000);
    
    Serial.println("Tone test complete.");
}

// Plays two beeps in sequence.
// frequency1: first tone frequency in Hz
// frequency2: second tone frequency in Hz
// toneDuration_ms: duration of each tone in milliseconds
// pauseDuration_ms: pause between tones in milliseconds (set to 0 if no pause is desired)
void SoundModule::playDualToneI2S(uint32_t frequency1, uint32_t frequency2, uint32_t toneDuration_ms, uint32_t pauseDuration_ms) {
    // Play the first tone
    playBeepI2S(frequency1, toneDuration_ms);
    
    // Optional pause between tones
    if (pauseDuration_ms > 0) {
        delay(pauseDuration_ms);
    }
    
    // Play the second tone
    playBeepI2S(frequency2, toneDuration_ms);
}


//---------------------------------------------------------------------
// UNUSED
// tone - mp3
//---------------------------------------------------------------------

// #include "AudioTools/AudioLibs/AudioSourceLittleFS.h"
// #include "AudioTools/AudioCodecs/CodecMP3Helix.h"
// AudioSourceLittleFS source(startFilePath, ext);
// AudioPlayer player(source, i2s, decoder);
// MP3DecoderHelix decoder;
// const char *startFilePath = "/";
// const char* ext = "mp3";

// void printMetaData(MetaDataType type, const char* str, int len) {
//     Serial.print("==> ");
//     Serial.print(toStr(type));
//     Serial.print(": ");
//     Serial.println(str); 
// }

// void playSoundTask(void* parameter) {
//     String* fileName = static_cast<String*>(parameter); // Cast parameter to file name
//     Serial.printf("Sound Task: Playing sound %s\n", fileName->c_str());

//     // Append ".mp3" to the file name
//     String fullFileName = *fileName + ".mp3";
//     // Construct the full file path (assuming the file is stored at the root)
//     String fullPath = "/" + fullFileName;

//     // Check if the file exists on LittleFS
//     if (!LittleFS.exists(fullPath)) {
//         Serial.printf("Warning: File %s not found. Aborting playback.\n", fullPath.c_str());
//         delete fileName;         // Free allocated memory
//         vTaskDelete(nullptr);    // Terminate the task early
//         return;
//     }else{
//         Serial.printf("INFO: File %s found.\n", fullPath.c_str());
//     }

//     // Configure the audio source with the full file name
//     const char* startFilePath = "/";
//     const char* ext = fullFileName.c_str();
//     AudioSourceLittleFS source(startFilePath, ext);
//     MP3DecoderHelix decoder;
//     AudioPlayer player(source, i2s, decoder);

//     // Set up metadata callback and volume
//     player.setMetadataCallback(printMetaData);
//     player.setVolume(1.0); // Ensure maximum volume

//     // Start playback
//     player.begin();
//     Serial.println("Playing audio frame...");
//     while (player.copy()) {
//         // Audio frame processing loop
//     }
//     Serial.printf("Playback completed for: %s\n", fullFileName.c_str());

//     delete fileName;         // Free allocated memory
//     vTaskDelete(nullptr);    // Delete this task
// }



// void SoundModule::playAudioFile(const char* fileName) {
//     // Construct the full file path (assumes your file is stored in the root directory)
//     String fullPath = String("/") + fileName;
    
//     // Check that the file exists on LittleFS
//     if (!LittleFS.exists(fullPath)) {
//         Serial.printf("Warning: File %s not found. Aborting playback.\n", fullPath.c_str());
//         return;
//     }
    
//     // Set up the audio source (using the root path "/" and the provided file name)
//     AudioSourceLittleFS source("/", fileName);
//     // Create a new decoder instance for MP3 playback
//     MP3DecoderHelix decoder;
//     // Create a local AudioPlayer using the source, global I2S stream, and the decoder
//     AudioPlayer player(source, i2s, decoder);
    
//     // Set a metadata callback (optional) and adjust the volume (range depends on your library)
//     player.setMetadataCallback(printMetaData);
//     player.setVolume(1.0);  // 1.0 = maximum volume (adjust if needed)
    
//     // Begin playback
//     player.begin();
//     Serial.printf("Playing audio file: %s\n", fileName);
    
//     // Process audio frames until playback is complete.
//     // This is a blocking loop.
//     while (player.copy()) {
//         // Each call to copy() processes an audio frame.
//     }
//     Serial.printf("Playback completed for: %s\n", fileName);
// }