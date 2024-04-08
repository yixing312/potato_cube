#include <HandFile.hpp>
#include <Alice.hpp>

extern class Alice alice;

void setup()
{
    alice.setState(AWAKE);
    // Initialize software serial communication
    SoftwareSerial serial1(10, 11); // RX, TX for software serial 1
    SoftwareSerial serial2(12, 13); // RX, TX for software serial 2
    SoftwareSerial serial3(14, 15); // RX, TX for software serial 3
    SoftwareSerial serial4(16, 17); // RX, TX for software serial 4

    // Set baud rate for each software serial instance
    serial1.begin(9600);
    serial2.begin(9600);
    serial3.begin(9600);
    serial4.begin(9600);
}

void loop()
{
    switch (alice.getState())
    {
    case SLEEP:
        break;
    case AWAKE:

        break;
    case SHAKE_HAND:
        break;
    case PLAYING:
        break;
    default:
        break;
    }
}
