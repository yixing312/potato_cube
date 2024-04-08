#include <Arduino.h>
#ifndef ALICE_HPP
#define ALICE_HPP

class Alice
{
private:
    int ID;

public:
    Alice() { ID = random(0, 1000327); }
    int getID() { return ID; }
};

#endif // ALICE_HPP
