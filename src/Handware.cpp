#include "Handware.hpp"

namespace Handware
{
    SoftwareSerial serial1(SERIAL1_RX, SERIAL1_TX); // RX, TX for software serial 1
    SoftwareSerial serial2(SERIAL2_RX, SERIAL2_TX); // RX, TX for software serial 2
    SoftwareSerial serial3(SERIAL3_RX, SERIAL3_TX); // RX, TX for software serial 3
    SoftwareSerial serial4(SERIAL4_RX, SERIAL4_TX); // RX, TX for software serial 4

    void ServelInit()
    {
        // Serial.begin(9600); // Initialize hardware serial communication
        Serial.begin(9600);
        serial1.begin(9600);
        serial2.begin(9600);
        serial3.begin(9600);
        serial4.begin(9600);
    }

    void ServelWrite(SoftwareSerial &serial, const char *str) { serial.println(str); }
    void ServelWrite(const char *str) { serial1.println(str); }

    JsonDocument SerialRead()
    {
        String receivedData = Serial.readString();
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, receivedData);
        if (error)
        {
            Serial.print("Failed to parse JSON: ");
            Serial.println(error.c_str());
        }
        else
            return doc;
    }

    JsonDocument SerialRead(SoftwareSerial &serial)
    {
        String receivedData = serial.readString();
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, receivedData);
        if (error)
        {
            Serial.print("Failed to parse JSON: ");
            Serial.println(error.c_str());
        }
        else
            return doc;
    }

} // namespace Handware