#pragma once
#include "Sabotage.h"

class PlayerSabotage: public Sabotage
{
private:
    void SetLocation(int);
    void UpdateLocation();

public:
    PlayerSabotage();
    void EnterSprite();
};


