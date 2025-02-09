#ifndef BLEMODULE_H
#define BLEMODULE_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

class BLEModule {
public:
    /// @brief Constructor. You can optionally pass a custom device name.
    BLEModule(const char* deviceName = "ESP32_S3_BLE");

    /// @brief Destructor.
    ~BLEModule();

    /// @brief Initializes BLE and starts advertising.
    void begin();

    /// @brief Should be called inside loop() to handle BLE events (e.g., sending notifications).
    void update();

    /// @brief Optionally set/update the characteristic value.
    void setCharacteristicValue(const std::string &value);

private:
    BLEServer* pServer;
    BLECharacteristic* pCharacteristic;
    bool deviceConnected;
    const char* deviceName;

    // UUIDs for BLE service and characteristic (you can change these if needed)
    const char* serviceUUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
    const char* characteristicUUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";

    // Internal callback class to handle connection events.
    class MyServerCallbacks : public BLEServerCallbacks {
    public:
        MyServerCallbacks(BLEModule* parent) : parent(parent) {}

        void onConnect(BLEServer* pServer) override;
        void onDisconnect(BLEServer* pServer) override;

    private:
        BLEModule* parent;
    };

    MyServerCallbacks* pServerCallbacks;
};

#endif // BLEMODULE_H
