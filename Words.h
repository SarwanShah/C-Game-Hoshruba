#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "Words.h"
#include "LTexture.h"
#include "Characters.h"
using namespace std;

class Word
{
    public:
        Word();
        Word(string str ,LTexture* gSpriteSheetTexture, SDL_Rect charRect, int x, int y, int FontRowSize, int spacing);
        void render(SDL_Renderer* gRenderer);
        void setText(string str, SDL_Rect charRect, int FontRowSize, int spacing);
        int getTextLength();
        ~Word();
    private:
        int x_pos, y_pos;
        string renderWord;
        LTexture* charTexture;
        Character* characters;
};
