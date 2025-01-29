#pragma once
#include "Guard.h"
#include "Warrior.h"

class EnemyGuard: public Guard
{
private:
    void SetLocation(int);
    void UpdateLocation();

public:
    EnemyGuard();
    void EnterSprite();
};



