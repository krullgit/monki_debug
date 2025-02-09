#include "HTTPOTAUpdateModule.h"
#include <HTTPUpdate.h>
#include <HTTPClient.h>
#include <WiFi.h>

namespace HTTPOTAUpdateModule {

    void checkAndUpdate(const char *updateUrl) {
        Serial.println("Checking for firmware update...");

        // Create an HTTPClient instance
        HTTPClient httpClient;

        // Call update with the HTTPClient, URL (as a String), and no callback (nullptr)
        t_httpUpdate_return ret = httpUpdate.update(httpClient, String(updateUrl), nullptr);

        // Handle the update result.
        switch(ret) {
            case HTTP_UPDATE_FAILED:
                Serial.printf("Update failed. Error (%d): %s\n",
                              httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
                break;
            case HTTP_UPDATE_NO_UPDATES:
                Serial.println("No update available.");
                break;
            case HTTP_UPDATE_OK:
                // On success the ESP32 will reboot automatically.
                Serial.println("Update successful. Rebooting...");
                break;
        }
    }

} // namespace HTTPOTAUpdateModule
