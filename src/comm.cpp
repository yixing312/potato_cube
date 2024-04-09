#include <comm.hpp>

extern class Alice alice;

void Readjson(JsonDocument &doc)
{
    if (doc.containsKey("setState"))
    {
        JsonDocument setStatedoc = doc["setState"].as<JsonObject>();
        if (setStatedoc["ID"].as<int>() == alice.getID())
            alice.setState(setStatedoc["state"].as<String>());
    }
}