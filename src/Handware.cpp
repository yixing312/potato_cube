#include "Handware.hpp"

namespace Handware
{
    SoftwareSerial serial_1(SERIAL1_RX, SERIAL1_TX); // RX, TX for software serial 1
    SoftwareSerial serial_2(SERIAL2_RX, SERIAL2_TX); // RX, TX for software serial 2
    SoftwareSerial serial_3(SERIAL3_RX, SERIAL3_TX); // RX, TX for software serial 3
    SoftwareSerial serial_4(SERIAL4_RX, SERIAL4_TX); // RX, TX for software serial 4
    SoftwareSerial *serials[] = {&serial_1, &serial_2, &serial_3, &serial_4};
    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

    void HardwareInit()
    {
        SerialInit();
        TftInit();
    }

    // ! Serial 相关函数
    void SerialInit()
    {
        // Serial.begin(9600); // Initialize hardware serial communication
        Serial.begin(115200);
        for (int i = 0; i < 4; i++)
            serials[i]->begin(115200);
    }
    void SerialWrite(SoftwareSerial &serial, const char *str) { serial.print(str); }
    void SerialWrite(const char *str)
    {
        for (int i = 0; i < 4; i++)
            serials[i]->print(str);
    }

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

    // ! tft 相关函数

    void TftInit()
    {
        tft.initR(INITR_144GREENTAB);
        tft.setRotation(3);
        tft.fillScreen(ST7735_BLACK);
    }

} // namespace Handware