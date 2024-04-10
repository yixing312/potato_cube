#include <HeadFile.hpp>
#include <Loop.hpp>

extern class Alice alice;

void setup()
{
    alice.setState(AWAKE);
    // Initialize software serial communication
    Handware::SerialInit();
}

void loop()
{
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
    default:
        break;
    }
}
