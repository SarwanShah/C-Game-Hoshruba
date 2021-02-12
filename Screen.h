#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "LTexture.h"
#include "iostream"
#include "string"
#include "SDL_ttf.h"
using namespace std;


class Screen
{
protected:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Surface* mScreenSurface;
    SDL_Surface* mBackgroundSurface;
    SDL_Texture* bgTexture;
    Mix_Music* bgMusic;
    TTF_Font* mFont;
    LTexture FontTextureSheet;
    SDL_Surface* loadSurface( string path );
    SDL_Texture* GenerateBackground();
public:
    Screen();
    Screen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height);
    ~Screen();
    virtual bool LoadTextures() = 0;
    virtual bool LoadAudio() = 0;
    virtual void ScreenHandler() = 0;
};
