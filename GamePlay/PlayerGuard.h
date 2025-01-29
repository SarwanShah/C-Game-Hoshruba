#pragma once
#include "Guard.h"

class PlayerGuard: public Guard
{
private:
    void SetLocation(int);
    void UpdateLocation();

public:
    PlayerGuard();
    void EnterSprite();
};


