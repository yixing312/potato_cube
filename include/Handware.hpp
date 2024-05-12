#ifndef __HANDWARE_HPP
#define __HANDWARE_HPP

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include "Adafruit_miniTFTWing.h"

#define SERIAL1_RX 2
#define SERIAL1_TX 3
#define SERIAL2_RX 4
#define SERIAL2_TX 5
#define SERIAL3_RX 6
#define SERIAL3_TX 7
#define SERIAL4_RX A0
#define SERIAL4_TX A1

#define TFT_CS 10
#define TFT_DC 9
#define TFT_MOSI 11
#define TFT_SCLK 13
#define TFT_RST 8

struct STRN_SYS_TIMER
{
    u16 bTag10us : 1;
    u16 bTag20us : 1;
    u16 bTag50us : 1;
    u16 bTag100us : 1;
    u16 bTag1ms : 1;
    u16 bTag5ms : 1;
    u16 bTag10ms : 1;
    u16 bTag20ms : 1;
    u16 bTag25ms : 1;
    u16 bTag50ms : 1;
    u16 bTag100ms : 1;
    u16 bTag200ms : 1;
    u16 bTag500ms : 1;
    u16 bTag1s : 1;
    u16 bTag1D1s : 1;
    u16 bTag2s : 1;
    u16 bTag2D5s : 1;
};

namespace Handware
{
    extern SoftwareSerial serial_1; // RX, TX for software serial 1
    extern SoftwareSerial serial_2; // RX, TX for software serial 2
    extern SoftwareSerial serial_3; // RX, TX for software serial 3
    extern SoftwareSerial serial_4; // RX, TX for software serial 4
    extern Adafruit_ST7735 tft;     // TFT screen
    extern STRN_SYS_TIMER sys_timer;
    extern unsigned long sys_start;
    extern unsigned long sys_count;

#define SERIAL(i) serial_##i
#define SERIAL_RX(i) SERIAL##i##_RX
#define SERIAL_TX(i) SERIAL##i##_TX

    void HardwareInit();
    // ! Serial 相关函数
    void SerialInit();
    void SerialWrite(SoftwareSerial &serial, const char *str);
    void SerialWrite(const char *str);

    JsonDocument SerialRead();
    JsonDocument SerialRead(SoftwareSerial &serial);

    // ! tft 相关函数
    void TftInit();

} // namespace Handware

#endif // __HANDWARE_HPP