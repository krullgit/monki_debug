#ifndef OTA_UPDATE_MODULE_H
#define OTA_UPDATE_MODULE_H

#include <ArduinoOTA.h>

// Namespace to encapsulate OTA functions
namespace OTAUpdateModule {

    // Call this function after connecting to WiFi
    void setupOTA();

    // Call this in your loop() to handle OTA events
    void handleOTA();

}

#endif // OTA_UPDATE_MODULE_H
