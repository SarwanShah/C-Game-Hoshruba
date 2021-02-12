#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "LTexture.h"

using namespace std;

class OnScreenTexture
{
protected:
    SDL_Rect* textureRect;
    LTexture* textureSheet;
    int x_pos;
    int y_pos;
    int x_size;
    int y_size;
public:
    OnScreenTexture();
    OnScreenTexture(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int size_x = 0, int size_y = 0);
    ~OnScreenTexture();
    void setTexture(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int size_x = 0, int size_y = 0);
    virtual void render(SDL_Renderer* mRenderer);
};

