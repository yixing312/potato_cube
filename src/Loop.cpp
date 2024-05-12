#include <Loop.hpp>
#include <Handware.hpp>
#include <Face.hpp>

void Loop::Sleep() { alice.setState(AWAKE); }

void Loop::Awake()
{
    // 绘制开机动画，期间不接受一切信息
    print_face(6);
    delay(2000);
    display_face(6);
    print_face(5);
    delay(1000);
    display_face(5);
    alice.setState(SHAKE_HAND);
}
void Loop::ShakeHand()
{
    // 此时只有一个节点，寻找父亲和兄弟节点，检查硬件串口和软件串口是否收到信息
    if (Serial.available())
    {
        String receivedData = Serial.readString();
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, receivedData);
        if (error)
        {
            Serial.println("Error parsing JSON");
            return;
        }

        if (doc.containsKey("cube") && doc["cube"] == "Sunday")
        {
            alice.setState(SUNDAY);
            Handware::tft.fillScreen(ST77XX_BLACK);
            if (doc.containsKey("time"))
                alice.sunday_data.time_string = doc["time"].as<const char *>();
        }
    }

    static int face_count = 1;
    if (Handware::sys_timer.bTag1s)
    {
        // 向硬件串口发送自己的 ID
        JsonDocument doc;
        doc["ID"] = alice.getID();
        Handware::SerialWrite(doc.as<String>().c_str());
        Serial.println(doc.as<String>().c_str());

        // 绘制土豆头动画
        print_face(face_count);
        face_count >= 4 ? face_count = 1 : face_count++;

        Handware::sys_timer.bTag1s = false;
    }
}

void Loop::Sunday()
{
    // 星期天，此时只有一个节点，寻找父亲和兄弟节点，检查硬件串口和软件串口是否收到信息
    if (Serial.available())
    {
    }

    if (Handware::sys_timer.bTag1s)
    {
        print_face(7);
        Handware::sys_timer.bTag1s = false;
    }
}

void Loop::Playing() {}
