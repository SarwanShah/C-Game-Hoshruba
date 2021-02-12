#pragma once
#include "Buttons.h"
#include "Screen.h"
#include "AudioIcons.h"

class MenuScreen: public Screen
{
private:
    LTexture ButtonTextureSheet;
    LTexture AudioIconTextureSheet;
    LTexture GameTitleText;
    SDL_Rect* ButtonTextureClips;
    SDL_Rect* AudioIconTextureClips;
    Mix_Chunk* ButtonClickSound;
    Mix_Chunk* AudioIconClickSound;
    int closingstatus;
    enum ButtonPressed
    {
        Start,
        Load,
        Quit
    };

public:
    MenuScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height);
    ~MenuScreen();
    bool LoadTextures();
    bool LoadAudio();
    void ScreenHandler();
    int getClosingStatus();
};
