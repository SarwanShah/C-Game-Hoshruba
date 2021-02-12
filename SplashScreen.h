#include "Screen.h"
#include "Words.h"

class SplashScreen:public Screen
{
private:
    LTexture* StoryText;
public:
    SplashScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height);
    ~SplashScreen();
    bool LoadTextures();
    bool LoadAudio();
    void ScreenHandler();
};
