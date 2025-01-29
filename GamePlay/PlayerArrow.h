#pragma once
#include "Arrow.h"

class PlayerArrow: public Arrow
{
public:
    PlayerArrow();
private:
    void UpdateLocation();
    void EnterSprite();
};


