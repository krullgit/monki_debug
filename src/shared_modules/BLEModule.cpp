#include "BLEModule.h"

// --- Define MySecurityCallbacks before its usage (optional if you want to keep it for reference) ---
class MySecurityCallbacks : public BLESecurityCallbacks {
public:
    uint32_t onPassKeyRequest() override {
        return 123456; // or generate/pass a passkey
    }
    void onPassKeyNotify(uint32_t pass_key) override {
        Serial.printf("Passkey: %d\n", pass_key);
    }
    bool onConfirmPIN(uint32_t pass_key) override {
        return true;
    }
    bool onSecurityRequest() override {
        return true;
    }
    void onAuthenticationComplete(esp_ble_auth_cmpl_t auth_cmpl) override {
        if(auth_cmpl.success){
            Serial.println("Pairing success");
        } else {
            Serial.println("Pairing failed");
        }
    }
};

//////////////////////////
// Callback Definitions //
//////////////////////////

void BLEModule::MyServerCallbacks::onConnect(BLEServer* pServer) {
    parent->deviceConnected = true;
    Serial.println("Client connected");
}

void BLEModule::MyServerCallbacks::onDisconnect(BLEServer* pServer) {
    parent->deviceConnected = false;
    Serial.println("Client disconnected");
}

//////////////////////
// BLEModule Class  //
//////////////////////

BLEModule::BLEModule(const char* deviceName) :
    pServer(nullptr),
    pCharacteristic(nullptr),
    deviceConnected(false),
    deviceName(deviceName),
    pServerCallbacks(nullptr)
{
    // Nothing to do in the constructor body.
}

BLEModule::~BLEModule() {
    // Clean up the allocated callback object.
    if (pServerCallbacks != nullptr) {
        delete pServerCallbacks;
    }
}

void BLEModule::begin() {
    Serial.println("Starting BLE work!");

    // Initialize the BLE device with the given device name.
    BLEDevice::init(deviceName);

    // Create the BLE server.
    pServer = BLEDevice::createServer();
    pServerCallbacks = new MyServerCallbacks(this);
    pServer->setCallbacks(pServerCallbacks);

    // Create the BLE service.
    BLEService* pService = pServer->createService(serviceUUID);

    // Create the BLE characteristic with read, write, and notify properties.
    pCharacteristic = pService->createCharacteristic(
        characteristicUUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_NOTIFY
    );

    // Set an initial value for the characteristic.
    pCharacteristic->setValue("Hello from ESP32-S3!");

    // --- Security Setup ---
    BLESecurity *pSecurity = new BLESecurity();
    // The following line is removed because your library does not support setAuthenticationCallback.
    // pSecurity->setAuthenticationCallback(new MySecurityCallbacks());
    pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_MITM_BOND);  // Example mode

    // Start the service.
    pService->start();

    // Start advertising.
    BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(serviceUUID);
    pAdvertising->setScanResponse(false);
    pAdvertising->setMinPreferred(0x06);  // Helps with iPhone connection issues.
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();

    Serial.println("BLE Advertising started!");
}

void BLEModule::update() {
    // For example, if a client is connected, send a notification.
    if (deviceConnected) {
        pCharacteristic->setValue("Data update from ESP32-S3");
        pCharacteristic->notify();
        Serial.println("Notification sent!");
    }
}

void BLEModule::setCharacteristicValue(const std::string &value) {
    if (pCharacteristic) {
        pCharacteristic->setValue(value);
    }
}
