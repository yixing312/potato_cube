#include <Arduino.h>
#include <ArduinoJson.h>
#ifndef ALICE_HPP
#define ALICE_HPP

enum State
{
    SLEEP,      // 啥都不干 ，Alice 决定不理你了
    AWAKE,      // 睡醒了，Alice 找不到人说话
    SHAKE_HAND, // Alice 加入了游戏部
    PLAYING,    // Alice 正在玩游戏
};

struct node
{
    int ID;
    int Serial_ID;
    String getDirection()
    {
        if (Serial_ID == 1)
            return "LEFT";
        else if (Serial_ID == 2)
            return "RIGHT";
        else if (Serial_ID == 3)
            return "UP";
        else if (Serial_ID == 4)
            return "DOWN";
        else
            return "ERROR";
    }
};

class Alice
{
private:
    int ID;
    State state;
    node fa, sons[3];

public:
    Alice() : state(SLEEP) { ID = random(0, 1000327); }
    int getID() { return ID; }

    State getState() { return state; }
    void setState(State s) { state = s; }
    void setState(String s);

    JsonDocument getSons();
};

#endif // ALICE_HPP
