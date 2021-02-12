#pragma once
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "LTexture.h"
#include "SDL_mixer.h"
using namespace std;

class AudioIcon
{
public:
    AudioIcon(LTexture* Texture, SDL_Rect* Clip, int frame, int x_pos, int y_pos, int x_size = 0, int y_size = 0);
    ~AudioIcon();
    void render(SDL_Renderer* gRenderer);
    void Animation(SDL_Event* e, int mouse_x, int mouse_y, Mix_Chunk* Sound);
private:
    SDL_Rect* iconClip;
    LTexture* iconTexture;
    int frame;
    int x_pos;
    int y_pos;
    int x_size;
    int y_size;
};
