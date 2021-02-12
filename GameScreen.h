#pragma once
#include "Screen.h"
#include "OnScreenObject.h"
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include "UI_Bar.h"
#include "UserInterface.h"
#include "Buttons.h"

#include <fstream>
#include <string>

#include "GamePlay/Node.h"
#include "GamePlay/Queue.h"
#include "GamePlay/Map.h"
#include "GamePlay/GTexture.h"
#include "GamePlay/WarriorFactory.h"
#include "GamePlay/Player.h"
#include "GamePlay/Enemy.h"
#include "GamePlay/GamePlay.h"
#undef main //Takes care of an issue



class GameScreen:public Screen
{
private:
    LTexture ButtonTextureSheet;
    LTexture MiscSpriteSheet;
    LTexture BuildingSpriteSheet;
    LTexture UItextureSheet;
    LTexture UnitIconSheet;
    LTexture PauseTextTexture;
    SDL_Rect MineRect;
    SDL_Rect* ButtonTextureClips;
    SDL_Rect* BuildingRect;
    SDL_Rect* UIBarRect;
    SDL_Rect* IconSlotRect;
    SDL_Rect* UnitIconRect;
    Mix_Chunk* ButtonClickSound;
    bool newGame;
    bool load;
public:
    GameScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height);
    ~GameScreen();
    bool LoadTextures();
    bool LoadAudio();
    void ScreenHandler();
    void setInitialState(int i);
};
