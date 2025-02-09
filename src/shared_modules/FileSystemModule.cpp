#include "FileSystemModule.h"
#include <vector>
#include <ctime>

// **GLOBAL ARRAY OF USERS**
User users[MAX_USERS] = {
    {"User 1", {}, {}, {}},
    {"User 2", {}, {}, {}}
};

// Common combo names for all grip types
String commonCombos[] = {
    "l_00001", "r_10000",
    "l_00010", "r_01000",
    "l_00011", "r_11000",
    "l_00100", "r_00100",
    "l_00110", "r_00110",
    "l_00111", "r_11100",
    "l_01000", "r_00010",
    "l_01001", "r_10010",
    "l_01100", "r_00110",
    "l_01110", "r_01110",
    "l_10000", "r_00001",
    "l_11111", "r_11111"
};



// Define the size of the commonCombos array
const size_t commonCombosSize = sizeof(commonCombos) / sizeof(commonCombos[0]);

// **INITIALIZE FILE SYSTEM**
bool initFileSystem() {
    if (!LittleFS.begin()) {
        Serial.println("Failed to mount LittleFS. Attempting to format...");

        if (!LittleFS.format()) {
            Serial.println("Formatting LittleFS failed.");
            return false;
        }

        Serial.println("LittleFS formatted successfully. Retrying mount...");

        if (!LittleFS.begin()) {
            Serial.println("Failed to mount LittleFS after formatting.");
            return false;
        }
    }

    Serial.println("LittleFS mounted successfully.");
    return true;
}

// Function to generate a random floating-point number in a given range
float getRandomStrength(float minValue = 30.0f, float maxValue = 50.0f) {
    return minValue + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxValue - minValue)));
}

// Function to generate a random timestamp within a date range
String getRandomTimestamp() {
    int year = 2025;
    int month = 1;
    int day = rand() % 10 + 10; // Random day between 10 and 19
    int hour = rand() % 24;     // Random hour between 0 and 23
    int minute = rand() % 60;   // Random minute between 0 and 59
    int second = rand() % 60;   // Random second between 0 and 59

    char timestamp[25];
    snprintf(timestamp, sizeof(timestamp), "%04d-%02d-%02dT%02d:%02d:%02d", 
            year, month, day, hour, minute, second);
    return String(timestamp);
}

void initializeUsers() {
    
    constexpr int numCombos = sizeof(commonCombos) / sizeof(commonCombos[0]);

    for (int i = 0; i < MAX_USERS; ++i) {
        // Initialize Sessions
        for (int j = 0; j < MAX_SESSIONS; ++j) {
            // Initialize the session
            users[i].sessions[j] = {
                j + 1,
                "Session " + String(j + 1),
                5 // Default targetRange
            };

            // Initialize the sets for this session
            for (int k = 0; k < SETS_PER_SESSION; ++k) {
                users[i].sessions[j].sets[k] = {
                    1,                                  // Unique ID for the set, MUST MATCH THE ID'S in SETS(users[i].sets[k])!!!!, since this is a key to it
                    "Set " + String(j + 1) + "-" + String(k + 1), // Set name
                    2,                                     // Default break time
                    true                              // Activate only the first set by default
                };

                Serial.printf("Initialized Set %d for Session %d: Name = %s, BreakTime = %d, Active = %s\n",
                            k + 1, j + 1, users[i].sessions[j].sets[k].setName.c_str(),
                            users[i].sessions[j].sets[k].breakTime,
                            users[i].sessions[j].sets[k].active ? "true" : "false");
            }
        }

        // Initialize Sets
        for (int k = 0; k < MAX_SETS; ++k) {
            users[i].sets[k].id = k + 1;
            users[i].sets[k].name = "Set " + String(k + 1);

            // Initialize 5 combos for each set
            for (int c = 0; c < COMBOS_PER_SET; ++c) {
                users[i].sets[k].combos[c] = {
                    c + 1,                                 // Combo ID
                    commonCombos[c % numCombos],           // Cycle through common combo names
                    40,                                   // perOfMax
                    5,                                    // timeTrain
                    5,                                    // timePause
                    (c % 2 == 0),                         // Alternate active status
                    (c % 2 == 0) ? "O" : "C", // Alternate grip types
                    20
                };
            }
        }

        // Initialize Grip Types with the same combos
        // users[i].gripTypes[0] = {"open", {}};
        // users[i].gripTypes[1] = {"full cr.", {}};
        // users[i].gripTypes[2] = {"half cr.", {}};
        // users[i].gripTypes[3] = {"pinch", {}};

        // for (int g = 0; g < NUM_GRIP_TYPES; ++g) {
        //     for (int c = 0; c < numCombos; ++c) {
        //         users[i].gripTypes[g].combos[c] = {commonCombos[c], 40.0f}; // Default maxKg to 40.0f
        //     }
        // }

        // Grip type names
        const String gripTypeNames[] = {"O", "HC", "C", "PIN"};

        // Initialize users with grip types and combos
        for (int i = 0; i < MAX_USERS; ++i) {
            for (int g = 0; g < NUM_GRIP_TYPES; ++g) {
                // Assign the grip type name
                users[i].gripTypes[g].name = gripTypeNames[g];

                for (int c = 0; c < NUM_COMBOS_PER_GRIP; ++c) {
                    // Generate random example measurements for each combo
                    std::vector<maxStrengthMeasurement> randomMeasurements;
                    for (int m = 0; m < 3; ++m) { // Generate 3 random measurements
                        randomMeasurements.push_back({getRandomStrength(), getRandomTimestamp()});
                    }

                    // Initialize each combo with its name and randomized measurements
                    users[i].gripTypes[g].combos[c] = {
                        commonCombos[c],  // Name of the combo from `commonCombos`
                        randomMeasurements // Assign random measurements
                    };
                }
            }
        }

        // Manually set all 12 speakers settings
        users[i].speakers[0] = {true, 5, 80, "Training Reminder"};
        users[i].speakers[1] = {true, 3, 60, "Outside Range"};
        users[i].speakers[2] = {true, 4, 70, "Indside Range"};
        users[i].speakers[3] = {true, 6, 75, "Resume"};
        users[i].speakers[4] = {true, 2, 50, "Combo Finished"};
        users[i].speakers[5] = {true, 5, 85, "Set Finished"};
        users[i].speakers[6] = {true, 7, 90, "Session Finished"};
        users[i].speakers[7] = {true, 1, 40, "New Highscore"};
        users[i].speakers[8] = {true, 3, 65, "Startup"};
        users[i].speakers[9] = {true, 8, 95, "Scrolling"};
        users[i].speakers[10] = {true, 2, 55, "Menue"};
        users[i].speakers[11] = {true, 6, 80, "Roller"};
        users[i].speakers[12] = {true, 6, 80, "Swipe Back"};

        // Manually set all 3 screen settings
        users[i].settingsDisplay[0] = {100, "Brightness in %"};
        users[i].settingsDisplay[1] = {60, "Dim-after in sec"};
        users[i].settingsDisplay[2] = {60, "Off-after in sec"};

        users[i].hands[0].name = "Left";
        users[i].hands[1].name = "Right";

        users[i].bodyweight_kilogram = 10;
        users[i].bodyweight_firstDecimal = 0;

        users[i].tareValue = 1000;

        // saveUser(i + 1);
    }
    Serial.println("All users initialized and saved to memory.");
}



// // **SAVE A USER**
// void saveUser(int userId) {
//     if (userId < 1 || userId > MAX_USERS) {
//         Serial.println("Invalid user ID");
//         return;
//     }

//     const User &user = users[userId - 1];
//     String fileName = String("/user_") + userId + ".json";

//     StaticJsonDocument<8192> doc;
//     doc["name"] = user.name;

//     // Save Sessions
//     JsonArray sessionsArray = doc.createNestedArray("sessions");
//     for (const auto &session : user.sessions) {
//         JsonObject sessionObj = sessionsArray.createNestedObject();
//         sessionObj["id"] = session.id;
//         sessionObj["name"] = session.name;
//         sessionObj["target_range"] = session.targetRange;

//         JsonArray setsArray = sessionObj.createNestedArray("sets");
//         for (const auto &set : session.sets) {
//             JsonObject setObj = setsArray.createNestedObject();
//             setObj["id"] = set.id;
//             setObj["set_name"] = set.setName;
//             setObj["break_time"] = set.breakTime;
//             setObj["active"] = set.active;
//         }
//     }

//     // Save Sets
//     JsonArray setsArray = doc.createNestedArray("sets");
//     for (int k = 0; k < MAX_SETS; ++k) {
//         const Set &set = user.sets[k];
//         JsonObject setObj = setsArray.createNestedObject();
//         setObj["id"] = set.id;
//         setObj["name"] = set.name;

//         JsonArray combosArray = setObj.createNestedArray("combos");
//         for (const auto &combo : set.combos) {
//             JsonObject comboObj = combosArray.createNestedObject();
//             comboObj["id"] = combo.id;
//             comboObj["name"] = combo.name;
//             comboObj["per_of_max"] = combo.perOfMax;
//             comboObj["time_train"] = combo.timeTrain;
//             comboObj["time_pause"] = combo.timePause;
//             comboObj["active"] = combo.active;
//             comboObj["grip_type"] = combo.gripType;
//         }
//     }

//     // Save Grip Types
//     JsonArray gripTypesArray = doc.createNestedArray("grip_types");
//     for (const auto &gripType : user.gripTypes) {
//         JsonObject gripTypeObj = gripTypesArray.createNestedObject();
//         gripTypeObj["name"] = gripType.name;

//         JsonArray combosArray = gripTypeObj.createNestedArray("combos");
//         for (const auto &combo : gripType.combos) {
//             JsonObject comboObj = combosArray.createNestedObject();
//             comboObj["name"] = combo.name;
//             comboObj["max_kg"] = combo.maxKg;
//         }
//     }

//     File file = LittleFS.open(fileName, "w");
//     if (!file) {
//         Serial.println("Failed to open file for writing");
//         return;
//     }

//     serializeJson(doc, file);
//     file.close();

//     Serial.printf("User %d saved successfully\n", userId);
// }
void loadUser(int userId) {
    if (userId < 1 || userId > MAX_USERS) {
        Serial.println("Invalid user ID");
        return;
    }

    String fileName = String("/user_") + userId + ".json";

    File file = LittleFS.open(fileName, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    StaticJsonDocument<8192> doc; // Adjust size if necessary for larger files
    DeserializationError error = deserializeJson(doc, file);
    if (error) {
        Serial.println("Failed to parse JSON");
        file.close();
        return;
    }
    file.close();

    // Load user data into memory
    User &user = users[userId - 1];
    user.name = doc["name"].as<String>();

    // **Step 4: Process the 'sets' section of the JSON**
    JsonArray setsArray = doc["sets"];
    for (size_t k = 0; k < setsArray.size(); ++k) { // Loop through each set in the JSON
        const JsonObject setObj = setsArray[k];
        user.sets[k].id = setObj["id"];
        user.sets[k].name = setObj["name"].as<String>();

        // Process 'combos' inside the set
        JsonArray combosArray = setObj["combos"];
        for (size_t c = 0; c < combosArray.size(); ++c) {
            const JsonObject comboObj = combosArray[c];
            user.sets[k].combos[c].id = comboObj["id"];
            user.sets[k].combos[c].name = comboObj["name"].as<String>();
            user.sets[k].combos[c].perOfMax = comboObj["per_of_max"];
            user.sets[k].combos[c].timeTrain = comboObj["time_train"];
            user.sets[k].combos[c].timePause = comboObj["time_pause"];
            user.sets[k].combos[c].active = comboObj["active"];
            user.sets[k].combos[c].gripType = comboObj["grip_type"].as<String>();
        }
    }
}


// **LIST ALL USERS**
void listAllUsers() {
    Serial.println("Listing all users:");

    for (const auto &user : users) {
        Serial.printf("User Name: %s\n", user.name.c_str());
    }
}


void loadSet(int setId) {
    String fileName = String("/set_") + setId + ".json";

    File file = LittleFS.open(fileName, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    StaticJsonDocument<4096> doc;
    DeserializationError error = deserializeJson(doc, file);
    if (error) {
        Serial.println("Failed to parse JSON");
        file.close();
        return;
    }
    file.close();

    Serial.printf("Set %d Details:\n", setId);
    Serial.printf("Name: %s\n", doc["name"].as<const char *>());

    JsonArray combosArray = doc["combos"];
    for (JsonObject combo : combosArray) {
        Serial.printf("Combo ID: %d, Name: %s, Percent of Max: %d, Time Train: %d, Time Pause: %d, Active: %s, Grip Type: %s\n",
                      combo["id"].as<int>(),
                      combo["name"].as<const char *>(),
                      combo["per_of_max"].as<int>(),
                      combo["time_train"].as<int>(),
                      combo["time_pause"].as<int>(),
                      combo["active"].as<bool>() ? "Yes" : "No",
                      combo["grip_type"].as<const char *>());
    }
}