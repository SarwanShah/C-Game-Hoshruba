#pragma once
#include "Buttons.h"
#include "Screen.h"
#include "AudioIcons.h"

class QuitScreen: public Screen
{
private:
    LTexture ButtonTextureSheet;
    LTexture AudioIconTextureSheet;
    SDL_Rect* ButtonTextureClips;
    SDL_Rect* AudioIconTextureClips;
    Mix_Chunk* ButtonClickSound;
    Mix_Chunk* AudioIconClickSound;
    LTexture GameOverText;
    int closingstatus;
    enum ButtonPressed
    {
        Retry,
        Quit
    };

public:
    QuitScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height);
    ~QuitScreen();
    bool LoadTextures();
    bool LoadAudio();
    void ScreenHandler();
    int getClosingStatus();
};

