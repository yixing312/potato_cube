#include <Alice.hpp>
#include <Handware.hpp>

Alice alice;

void Alice::setState(String s)
{
    if (s == "SLEEP")
        state = SLEEP;
    else if (s == "AWAKE")
        state = AWAKE;
    else if (s == "SHAKE_HAND")
        state = SHAKE_HAND;
    else if (s == "PLAYING")
        state = PLAYING;
}

JsonDocument Alice::getSons()
{
    JsonDocument doc, command;
    command["command"] = "getSons";
    Handware::SerialWriteSons(command.as<String>().c_str());

    return doc;
}