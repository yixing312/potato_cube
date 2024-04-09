#include <Loop.hpp>

void Loop::Sleep() {}

void Loop::Awake()
{
    Handware::ServelInit();
    alice.setState(SHAKE_HAND);
}
void Loop::ShakeHand()
{
    JsonDocument doc;
    doc["ID"] = alice.getID();
    Handware::ServelWrite(doc.as<String>().c_str());
    Serial.println(doc.as<String>().c_str());
}

void Loop::Playing() {}