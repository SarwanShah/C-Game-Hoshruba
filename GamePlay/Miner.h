#pragma once
#include "Miner.h"
#include "Warrior.h"

class Miner: public Warrior
{
private:
    bool turnBack;
    bool walkingUp;
    void UpdateLocation();

public:
    void EnterSprite();
    Miner();
};

