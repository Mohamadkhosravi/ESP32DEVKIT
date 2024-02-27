// #pragma ONE
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID "8d9d08ae-dad3-4769-8555-1ed46402feae"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class BlouetoothServer
{
private:
    /* data */
public:
    BLEServer *pServer = NULL;
    BLECharacteristic *pCharacteristic = NULL;
    BLEDescriptor *pDescr;
    BLE2902 *pBLE2902;
    typedef enum
    {
        disconnect,
        connect
    } conection;

    void setup();
    void sendMassage(char *massage);
};
