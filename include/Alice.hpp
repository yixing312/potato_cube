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

class Alice
{
private:
    int ID;
    State state;

public:
    Alice()
    {
        ID = random(0, 1000327);
        state = SLEEP;
    }
    int getID() { return ID; }
    State getState() { return state; }
    int setState(State s) { state = s; }
};

#endif // ALICE_HPP
