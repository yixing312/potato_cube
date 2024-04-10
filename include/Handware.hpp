#ifndef __HANDWARE_HPP
#define __HANDWARE_HPP

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#define SERIAL1_RX 6
#define SERIAL1_TX 7
#define SERIAL2_RX 8
#define SERIAL2_TX 9
#define SERIAL3_RX 10
#define SERIAL3_TX 11
#define SERIAL4_RX 12
#define SERIAL4_TX 13

namespace Handware
{

    extern SoftwareSerial serial1; // RX, TX for software serial 1
    extern SoftwareSerial serial2; // RX, TX for software serial 2
    extern SoftwareSerial serial3; // RX, TX for software serial 3
    extern SoftwareSerial serial4; // RX, TX for software serial 4

#define SERIAL(i) serial##i
#define SERIAL_RX(i) SERIAL##i##_RX
#define SERIAL_TX(i) SERIAL##i##_TX

    void SerialInit();
    void SerialWrite(SoftwareSerial &serial, const char *str);
    void SerialWrite(const char *str);
    void SerialWriteFather(const char *str);
    void SerialWriteSons(const char *str);

    JsonDocument SerialRead();
    JsonDocument SerialRead(SoftwareSerial &serial);

} // namespace Handware

#endif // __HANDWARE_HPP