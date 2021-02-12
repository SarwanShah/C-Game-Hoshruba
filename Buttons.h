#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "Words.h"
#include "Characters.h"
#include "LTexture.h"
#include "SDL_mixer.h"

using namespace std;


class Button
{
    public:
        Button(string Text, LTexture* CharTexture, LTexture* Texture, SDL_Rect* Clip, SDL_Rect charRect, int FontRowSize, int textspacing, int x_pos, int y_pos, int x_size = 0, int y_size = 0);
        void render(SDL_Renderer* gRenderer);
        bool Animation(SDL_Event* e, int mouse_x, int mouse_y, Mix_Chunk* sound);
        ~Button();
    private:
        SDL_Rect* btnClip;
        LTexture* btnTexture;
        Word* BtnText;
        int frame;
        int x_pos;
        int y_pos;
        int x_size;
        int y_size;
};
