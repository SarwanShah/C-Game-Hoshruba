#pragma once
#include "Sabotage.h"
#include "Warrior.h"

class EnemySabotage: public Sabotage
{
private:
    void SetLocation(int);
    void UpdateLocation();
public:
    EnemySabotage();
    void EnterSprite();

};


