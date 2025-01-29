#pragma once
#include "Miner.h"
#include "Warrior.h"

class PlayerMiner: public Miner
{
private:
    void SetLocation(int);

public:
    PlayerMiner();
};


