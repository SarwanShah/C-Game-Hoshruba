#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "Characters.h"
#include "LTexture.h"
using namespace std;

class Character
{
    public:
        Character();
        Character(LTexture* gSpriteSheetTexture, char c, SDL_Rect charRect, int x_pos, int y_pos, int FontRowSize);
        void render(SDL_Renderer* gRenderer);
        void setPosition(int x, int y);
        void setChar(char c, int FontRowSize);
        void setTexture(char c, LTexture* gSpriteSheetTexture, SDL_Rect charRect, int x_pos, int y_pos, int FontRowSize);
        ~Character();
    private:
        int x,y;
        SDL_Rect charRect;
        char shownChar;
        LTexture* CharTexture;
};
