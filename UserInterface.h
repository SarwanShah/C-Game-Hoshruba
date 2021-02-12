#pragma once
#include "UI_Bar.h"
#include "IconSlot.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>
#include "stdlib.h"
class UserInterface
{
 private:
    SDL_Renderer* mRenderer;
    TTF_Font* mFont;
    LTexture* UItextureSheet;
    LTexture* UnitIconSheet;
    SDL_Rect* UIBarRect;
    SDL_Rect* IconSlotRect;
    SDL_Rect* IconRect;
    UIBar* Bar;
    IconSlot* P1_Slots;
    IconSlot* P2_Slots;
    void GenerateObjects();
    LTexture TimerText;
    LTexture Time;
    LTexture P1_StatsText;
    LTexture P2_StatsText;
    LTexture MoneyText;
    LTexture P1_MoneyValue;
    LTexture P2_MoneyValue;
    LTexture HealthText;
    LTexture P1_HealthValue;
    LTexture P2_HealthValue;
    LTexture ScoreText;
    LTexture P1_ScoreValue;
    LTexture P2_ScoreValue;
    int P1_keyselect;
    int P2_keyselect;
    string P1_Money;
    string P2_Money;
    string P1_Health;
    string P2_Health;
    string P1_Score;
    string P2_Score;
 public:
    UserInterface(LTexture* textureSheet, LTexture* UnitIconSheet, SDL_Rect* UIBarRect, SDL_Rect* IconSlotRect, SDL_Rect* IconRect, TTF_Font* gFont, SDL_Renderer* gRenderer);
    ~UserInterface();
    void render(SDL_Renderer* gRenderer);
    void EventHandler(SDL_Event* e,int mouse_x, int mouse_y);
    void P1_UpdateHealth(int h);
    void P1_UpdateMoney(int m);
    void P1_UpdateScore(int s);
    void P2_UpdateHealth(int h);
    void P2_UpdateMoney(int m);
    void P2_UpdateScore(int s);

};


