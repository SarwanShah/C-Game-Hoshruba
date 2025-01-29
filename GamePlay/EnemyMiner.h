#pragma once
#include "Miner.h"
#include "Warrior.h"

class EnemyMiner: public Miner
{
private:
    void SetLocation(int);

public:
    EnemyMiner();
};


