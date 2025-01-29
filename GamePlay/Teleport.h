#pragma once
#include "Warrior.h"

class Teleport: public Warrior  //Teleport effect when player and enemy guards switch lanes
{
private:
    void UpdateLocation();
public:
    Teleport();
    void Draw(SDL_Renderer*);
    void SetLocation(int lane);
    void EnterSprite();
};
