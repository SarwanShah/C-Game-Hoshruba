#pragma once
#include "Archer.h"
#include "EnemyArrow.h"

class EnemyArcher: public Archer
{
private:
    Warrior* FireProjectile();

public:
    EnemyArcher();
    void EnterSprite();
};


