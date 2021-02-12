#pragma once
#include "OnScreenObject.h"
#include "UnitIcon.h"

class IconSlot:public OnScreenTexture
{
private:
    int frame;
    UnitIcon* Icon;
    bool select;
public:
    IconSlot();
    IconSlot(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size = 0, int y_size = 0);
    void render(SDL_Renderer* gRenderer);
    void setTexture(LTexture* textureSheet, LTexture* UnitIconSheet, SDL_Rect* UnitIconRect, SDL_Rect* textureRect, int frame, int adjust, int x_pos, int y_pos, int x_size = 0, int y_size = 0);
    void KeyboardAnimation();
    void setSelect(bool select);
};
