#pragma once
#include "Archer.h"
#include "PlayerArrow.h"


class PlayerArcher: public Archer
{
public:
    PlayerArcher();

private:
    void EnterSprite();
    Warrior* FireProjectile();
};


