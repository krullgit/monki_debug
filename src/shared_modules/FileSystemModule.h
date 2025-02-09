#ifndef FILE_SYSTEM_MODULE_H
#define FILE_SYSTEM_MODULE_H

#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <map>
#include <vector>

// Declare the commonCombos array as extern to make it globally accessible
extern String commonCombos[];
// Define the size of the commonCombos array
extern const size_t commonCombosSize;


/** 
 * **INITIALIZATION FUNCTIONS**
 * Functions to initialize and manage the file system.
 */
bool initFileSystem(); // Initialize the LittleFS file system

/** 
 * **USER, SESSION, SET, AND COMBO MANAGEMENT**
 * Hierarchical data structure for Users, Sessions, Sets, and Combos.
 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
// **CONSTANTS**
constexpr int MAX_USERS = 2;          // Maximum number of users
constexpr int MAX_SESSIONS = 5;       // Maximum sessions per user
constexpr int SETS_PER_SESSION = 8;   // Maximum sets per session
constexpr int MAX_SETS = 5;           // Maximum sets per user
constexpr int COMBOS_PER_SET = 8;     // WARNING, If you set this this less than 5, the flex container will break from time to time
constexpr int NUM_GRIP_TYPES = 4;     // Number of grip types
constexpr int NUM_COMBOS_PER_GRIP = 24; // Number of combos per grip type
constexpr int NR_SPEAKER_SETTINGS = 13; 
constexpr int NR_SCREEN_SETTINGS = 3; 

// Constants
// constexpr int TOTAL_ROUNDS = 24;
// constexpr int PULL_DURATION = 7; // Seconds

constexpr int TOTAL_ROUNDS = 4;
constexpr int PULL_DURATION = 2; // Seconds

// **STRUCTURES**
struct Combo {
    int id;               // Unique ID for the combo
    String name;          // Name of the combo
    int perOfMax;         // Percentage of max strength
    int timeTrain;        // Training time in seconds
    int timePause;        // Pause time in seconds
    bool active;          // Active status
    String gripType;      // Type of grip
    int gripEdgeMM;            // 
};

struct Set {
    int id;               // Unique ID for the set
    String name;          // Name of the set
    Combo combos[COMBOS_PER_SET]; // Array of combos in the set
};

struct SetInSession {
    int id;               // Unique ID for each set within a session
    String setName;       // Name of the set
    int breakTime;        // Break time in seconds
    bool active;          // Active status
};

struct Session {
    int id;               // Unique ID for the session
    String name;          // Name of the session
    int targetRange;      // Target range for session performance
    SetInSession sets[SETS_PER_SESSION]; // Fixed array of sets for the session
};

// Define a structure to hold CF measurement data
struct maxStrengthMeasurement {
    float maxKg; 
    String timestamp; // Time of measurement
};

// **NEW TYPES**
struct max_strength_combo {
    String name;  // Name of the combo (serves as ID)
    std::vector<maxStrengthMeasurement> maxStrengthMeasurements;
};

struct max_strength_gripType {
    String name;                      // Name of the grip type
    max_strength_combo combos[NUM_COMBOS_PER_GRIP]; // Array of 10 combos
};

struct Speaker {
    bool enabled;        // Indicates if the speaker is enabled
    int tone;            // Tone setting for the speaker
    int volume;          // Volume setting for the speaker
    String text;         // Associated text or label for the speaker
};

struct SettingsDisplay {
    int value;          // Volume setting for the speaker
    String text;         // Associated text or label for the speaker
};


// Define a structure to hold CF measurement data
struct CFMeasurement {
    float forceReadings[TOTAL_ROUNDS][PULL_DURATION]; // Force readings for this measurement
    float criticalForce; // Calculated CF value
    String timestamp; // Time of measurement
};

// Define a structure for hand-specific data
struct HandData {
    String name; // Name of the hand (e.g., "Left" or "Right")
    std::vector<CFMeasurement> cfMeasurements; // Vector to store historical CF measurements
};

// **UPDATED USER STRUCTURE**
struct User {
    String name;                      // User's name
    Session sessions[MAX_SESSIONS];   // Sessions per user
    Set sets[MAX_SETS];               // Sets per user
    max_strength_gripType gripTypes[NUM_GRIP_TYPES]; // Three predefined grip types
    Speaker speakers[NR_SPEAKER_SETTINGS];            // Array to hold data for 12 speakers
    SettingsDisplay settingsDisplay[NR_SCREEN_SETTINGS];            // Array to hold data for 12 speakers
    HandData hands[2];                // Data for "Left" and "Right" hands
    int bodyweight_kilogram;
    int bodyweight_firstDecimal;
    int tareValue;
};

// **GLOBAL ARRAY OF USERS**
extern User users[MAX_USERS]; // Array holding all user data



// **USER MANAGEMENT FUNCTIONS**
void initializeUsers();            // Initialize all users with default data
void saveUser(int userId);         // Save a user's data (sessions, sets, and grip types) to the filesystem
void loadUser(int userId);         // Load a user's data from the filesystem
void listAllUsers();               // Print details of all users
void listUserSessions(int userId); // List sessions of a specific user
void listUserSets(int userId);     // List sets and combos of a specific user

// **SET AND COMBO MANAGEMENT FUNCTIONS**
void loadSet(int setId);           // Load a set and its combos from the filesystem
void updateMaxKg(int userId, const String &gripTypeName, const String &comboName, float maxKg); // Update maxKg for a combo

#endif // FILE_SYSTEM_MODULE_H
