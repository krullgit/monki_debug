#include "HTTPOTAUpdateModule.h"
#include <HTTPUpdate.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "wifi_credentials.h"


namespace HTTPOTAUpdateModule {

    void checkAndUpdate(const char *updateUrl) {
        Serial.println("Checking for firmware update...");
        HTTPClient httpClient;
        httpClient.setTimeout(10000);
        // Force the HTTP client to not reuse connections.
        httpClient.setReuse(false);

        // Callback to set additional headers on every HTTP request.
        auto requestCallback = [](HTTPClient* client) {
            client->addHeader("Cache-Control", "no-cache");
            client->addHeader("Connection", "close");
        };

        t_httpUpdate_return ret = httpUpdate.update(httpClient, String(updateUrl), requestCallback);
        
        switch(ret) {
            case HTTP_UPDATE_FAILED:
                Serial.printf("Update failed. Error (%d): %s\n",
                              httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
                break;
            case HTTP_UPDATE_NO_UPDATES:
                Serial.println("No update available.");
                break;
            case HTTP_UPDATE_OK:
                Serial.println("Update successful. Rebooting...");
                break;
        }
    }

    void manualOTAUpdate(const char *firmwareUrl) {


        // LOCAL FIRMWARE DEPLOYMENT
        // 1. Firewall (UFW):
        // Your Ubuntu machine might be blocking external connections on port 81. Check the status with:
        // sudo ufw status
        // 2. If the firewall is enabled, allow connections on port 81:
        // sudo ufw allow 81/tcp
        // 3. start local server in the folder with the firmware.bin
        // npx http-server -p 8080


         // Initialize OTA update
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        Serial.print("Connecting to WiFi");
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }

        Serial.println("Checking for firmware update...");
        HTTPClient httpClient;
        httpClient.setTimeout(10000);
        // Force the HTTP client to not reuse connections.
        httpClient.setReuse(false);

        HTTPClient http;
        Serial.println("Starting manual OTA update...");

        // Begin the HTTP connection to the firmware URL.
        http.begin(firmwareUrl);
        int httpCode = http.GET();
        if (httpCode == HTTP_CODE_OK) {
            int contentLength = http.getSize();
            Serial.print("Content-Length: ");
            Serial.println(contentLength);

            if (contentLength > 0) {
            // Check if there is enough space to begin OTA update.
            if (Update.begin(contentLength)) {
                // Get the HTTP stream.
                WiFiClient * stream = http.getStreamPtr();
                // Write the firmware to the flash.
                size_t written = Update.writeStream(*stream);
                Serial.print("Written: ");
                Serial.println(written);

                if (written == contentLength) {
                Serial.println("Firmware written successfully.");
                } else {
                Serial.println("Firmware written partially. Check your connection or retry.");
                }

                if (Update.end()) {
                if (Update.isFinished()) {
                    Serial.println("Update successfully completed. Rebooting...");
                    ESP.restart();
                } else {
                    Serial.println("Update not finished? Something went wrong.");
                }
                } else {
                Serial.print("Update failed. Error #: ");
                Serial.println(Update.getError());
                }
            } else {
                Serial.println("Not enough space to begin OTA update.");
            }
            } else {
            Serial.println("Invalid content length.");
            }
        } else {
            Serial.printf("HTTP GET failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    }


} // namespace HTTPOTAUpdateModule
