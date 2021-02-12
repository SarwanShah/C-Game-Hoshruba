#pragma once
#include "OnScreenObject.h"

class UIBar:public OnScreenTexture
{
private:
public:
    UIBar(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size = 0, int y_size = 0);
    ~UIBar();
    void render(SDL_Renderer* gRenderer);

};
