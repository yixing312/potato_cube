#include <HeadFile.hpp>
#include <Loop.hpp>

extern class Alice alice;

void setup()
{
    alice.setState(AWAKE);
    // Initialize software serial communication
    Handware::HardwareInit();
    Handware::sys_start = millis();
}

void loop()
{
    Handware::sys_count = (millis() - Handware::sys_start);
    Handware::sys_timer.bTag1ms = true;
    if (Handware::sys_count % 9 == 0)
        Handware::sys_timer.bTag10ms = true;
    if (Handware::sys_count % 19 == 0)
        Handware::sys_timer.bTag20ms = true;
    if (Handware::sys_count % 99 == 0)
        Handware::sys_timer.bTag100ms = true;
    if (Handware::sys_count % 999 == 0)
        Handware::sys_timer.bTag1s = true;

    switch (alice.getState())
    {
    case SLEEP:
        Loop::Sleep();
        break;
    case AWAKE:
        Loop::Awake();
        break;
    case SHAKE_HAND:
        Loop::ShakeHand();
        break;
    case PLAYING:
        Loop::Playing();
        break;
    case SUNDAY:
        Loop::Sunday();
        break;
    default:
        break;
    }
}
