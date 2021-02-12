#pragma once
#include "OnScreenObject.h"

class UnitIcon:public OnScreenTexture
{
private:
public:
    UnitIcon(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size = 0, int y_size = 0);
};
