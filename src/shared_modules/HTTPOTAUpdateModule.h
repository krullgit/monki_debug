#ifndef HTTP_OTA_UPDATE_MODULE_H
#define HTTP_OTA_UPDATE_MODULE_H

#include <Arduino.h>

namespace HTTPOTAUpdateModule {
    /**
     * @brief Checks for a firmware update at the given URL and applies it if available.
     *
     * @param updateUrl The full URL to the firmware file (e.g., "http://192.168.1.100/firmware.bin").
     */
    void checkAndUpdate(const char *updateUrl);
}

#endif // HTTP_OTA_UPDATE_MODULE_H
