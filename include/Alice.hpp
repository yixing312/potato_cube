#include <Arduino.h>
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
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    } direction;
};

class Alice
{
private:
    int ID;
    State state;
    node fa;
    node sons[3];

public:
    Alice()
    {
        ID = random(0, 1000327);
        state = SLEEP;
    }
    int getID() { return ID; }

    State getState() { return state; }
    void setState(State s) { state = s; }
    void setState(String s)
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
};

#endif // ALICE_HPP
