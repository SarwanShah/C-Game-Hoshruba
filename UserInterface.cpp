#pragma once
#include "UserInterface.h"
#include <string>
#include "stdlib.h"
#include <cstdlib>
#include "stdlib.h"

UserInterface::UserInterface(LTexture* UItextureSheet, LTexture* UnitIconSheet, SDL_Rect* UIBarRect, SDL_Rect* IconSlotRect, SDL_Rect* IconRect, TTF_Font* gFont, SDL_Renderer* gRenderer)
{

    this->UItextureSheet = UItextureSheet;
    this->UnitIconSheet = UnitIconSheet;
    this->UIBarRect = UIBarRect;
    this->IconSlotRect = IconSlotRect;
    this->IconRect = IconRect;
    mFont = gFont;
    mRenderer = gRenderer;
    P1_keyselect = 0;
    P2_keyselect = 0;
    P1_Money = "0";
    P2_Money = "0";
    P1_Health ="0";
    P2_Health ="0";
    P1_Score = "0";
    P2_Score = "0";

    Bar = new UIBar(UItextureSheet, UIBarRect, 50, 600, 32*3, 64*3);
    P1_Slots = new IconSlot[6];

    P1_Slots[0].setTexture(UItextureSheet, UnitIconSheet, &IconRect[2], IconSlotRect,0,5, 155, 630, IconSlotRect[0].w*1.7, IconSlotRect[0].h*1.7);
    P1_Slots[1].setTexture(UItextureSheet, UnitIconSheet, &IconRect[0], IconSlotRect,1,-4, 251, 630, IconSlotRect[1].w*1.7, IconSlotRect[1].h*1.7);
    P1_Slots[2].setTexture(UItextureSheet, UnitIconSheet, &IconRect[1], IconSlotRect,2,-4, 330, 630, IconSlotRect[2].w*1.7, IconSlotRect[2].h*1.7);

    P1_Slots[3].setTexture(UItextureSheet, UnitIconSheet, &IconRect[3], IconSlotRect,0,5, 155, 697, IconSlotRect[0].w*1.7, IconSlotRect[0].h*1.7);
    P1_Slots[4].setTexture(UItextureSheet, UnitIconSheet, &IconRect[4], IconSlotRect,1,-5, 251, 697, IconSlotRect[1].w*1.7, IconSlotRect[1].h*1.7);
    P1_Slots[5].setTexture(UItextureSheet, UnitIconSheet, &IconRect[5], IconSlotRect,2,-6, 330, 697, IconSlotRect[2].w*1.7, IconSlotRect[2].h*1.7);

    P2_Slots = new IconSlot[6];

    P2_Slots[0].setTexture(UItextureSheet, UnitIconSheet,&IconRect[8], IconSlotRect,0,5, 155+962, 630, IconSlotRect[0].w*1.7, IconSlotRect[0].h*1.7);
    P2_Slots[1].setTexture(UItextureSheet, UnitIconSheet,&IconRect[6], IconSlotRect,1,-6, 251+962, 630, IconSlotRect[1].w*1.7, IconSlotRect[1].h*1.7);
    P2_Slots[2].setTexture(UItextureSheet, UnitIconSheet,&IconRect[7], IconSlotRect,2,-8, 330+962, 630, IconSlotRect[2].w*1.7, IconSlotRect[2].h*1.7);

    P2_Slots[3].setTexture(UItextureSheet, UnitIconSheet,&IconRect[9], IconSlotRect,0,5, 155+962, 697, IconSlotRect[0].w*1.7, IconSlotRect[0].h*1.7);
    P2_Slots[4].setTexture(UItextureSheet, UnitIconSheet,&IconRect[4], IconSlotRect,1,-6, 251+962, 697, IconSlotRect[1].w*1.7, IconSlotRect[1].h*1.7);
    P2_Slots[5].setTexture(UItextureSheet, UnitIconSheet,&IconRect[11], IconSlotRect,2,-8, 330+962, 697, IconSlotRect[2].w*1.7, IconSlotRect[2].h*1.7);
    cout << "User Interface Constructor Called!" << endl;
}


void UserInterface::GenerateObjects()
{

    P1_StatsText.loadFromRenderedText("Player 1 Stats:", {255,197, 19, 255}, mFont, mRenderer);
    P2_StatsText.loadFromRenderedText("Player 2 Stats:", {255,197, 19, 255}, mFont, mRenderer);

    MoneyText.loadFromRenderedText("Money: $", {255,197, 19, 255}, mFont, mRenderer);
    HealthText.loadFromRenderedText("Health: ", {255,197, 19, 255}, mFont ,mRenderer);
    ScoreText.loadFromRenderedText("Score: ", {255,197, 19, 255}, mFont, mRenderer);
    TimerText.loadFromRenderedText("HOSHRUBA", {255, 255, 255, 255}, mFont, mRenderer);



    P1_MoneyValue.loadFromRenderedText(P1_Money, {0,255, 27, 255}, mFont, mRenderer);
    P2_MoneyValue.loadFromRenderedText(P2_Money, {0,255, 27, 255}, mFont, mRenderer);

    P1_HealthValue.loadFromRenderedText(P1_Health, {0, 78, 255, 255}, mFont, mRenderer);
    P2_HealthValue.loadFromRenderedText(P2_Health, {255, 7, 0, 255}, mFont, mRenderer);

    P1_ScoreValue.loadFromRenderedText(P1_Score, {221, 255, 255}, mFont, mRenderer);
    P2_ScoreValue.loadFromRenderedText(P2_Score, {6, 221, 255, 255}, mFont, mRenderer);

}

UserInterface::~UserInterface()
{
    UItextureSheet = NULL;
    UnitIconSheet = NULL;
    UIBarRect = NULL;
    IconSlotRect = NULL;
    IconRect = NULL;

    if (Bar != NULL)
        delete Bar;
    if (P1_Slots != NULL)
        delete[] P1_Slots;
    if (P2_Slots != NULL)
        delete[] P2_Slots;

    Bar = NULL;
    P1_Slots = NULL;
    P2_Slots = NULL;
}


void UserInterface::render(SDL_Renderer* gRenderer)
{
    GenerateObjects();
    Bar->render(gRenderer);
    for (int i = 0; i < 6; i++)
    {
        P1_Slots[i].render(gRenderer);
        P2_Slots[i].render(gRenderer);
    }
    MoneyText.render(450, 670, mRenderer, NULL, 75, 25);
    MoneyText.render(930, 670, mRenderer, NULL, 75, 25);
    HealthText.render(450, 700, mRenderer, NULL, 75, 25);
    HealthText.render(930, 700, mRenderer, NULL, 75, 25);
    ScoreText.render(450, 730, mRenderer, NULL, 75, 25);
    ScoreText.render(930, 730, mRenderer, NULL, 75, 25);
    TimerText.render(680, 640, mRenderer, NULL, 150, 40);

    P1_StatsText.render(450, 640, mRenderer, NULL, 150, 25);
    P1_MoneyValue.render(530, 670, mRenderer, NULL, 30, 25);
    P1_HealthValue.render(530, 700, mRenderer, NULL, 30, 25);
    P1_ScoreValue.render(530, 730, mRenderer, NULL, 30, 25);

    P2_StatsText.render(930, 640, mRenderer, NULL, 150, 25);
    P2_MoneyValue.render(1020, 670, mRenderer, NULL, 30, 25);
    P2_HealthValue.render(1020, 700, mRenderer, NULL, 30, 25);
    P2_ScoreValue.render(1020, 730, mRenderer, NULL, 30, 25);

}

void UserInterface::EventHandler(SDL_Event* e, int  mouse_x,int  mouse_y)
{
    P1_Slots[P1_keyselect].setSelect(true);
    P2_Slots[P2_keyselect].setSelect(true);
    for (int i = 0; i < 6; i++)
    {
        P1_Slots[i].KeyboardAnimation();
        P2_Slots[i].KeyboardAnimation();
    }

    if (e->type == SDL_KEYDOWN)
    {
        switch(e->key.keysym.sym)
        {

            case SDLK_RIGHT:
                if (P2_keyselect < 3)
                {
                    P2_Slots[P2_keyselect].setSelect(false);
                    P2_keyselect += 1;
                }
                else
                    P2_Slots[P2_keyselect].setSelect(true);
                break;

            case SDLK_LEFT:
                if (P2_keyselect > 0)
                {
                    P2_Slots[P2_keyselect].setSelect(false);
                    P2_keyselect -= 1;
                }
                else
                    P2_Slots[P2_keyselect].setSelect(true);
                break;

            case SDLK_d:
                if (P1_keyselect < 3)
                {
                    P1_Slots[P1_keyselect].setSelect(false);
                    P1_keyselect += 1;
                }
                else
                    P1_Slots[P1_keyselect].setSelect(true);
                break;

            case SDLK_a:
                if (P1_keyselect > 0)
                {
                    P1_Slots[P1_keyselect].setSelect(false);
                    P1_keyselect -= 1;
                }
                else
                    P1_Slots[P1_keyselect].setSelect(true);
                break;
            default:
                break;



        }
    }





}

void UserInterface::P1_UpdateHealth(int h)
{
    std::string s = std::to_string(h);
    P1_Health = s;
}
void UserInterface::P1_UpdateMoney(int m)
{
    std::string s = std::to_string(m);
    P1_Money = s;
}
void UserInterface::P1_UpdateScore(int s1){
    std::string s = std::to_string(s1);
    P1_Score = s;
    }
void UserInterface::P2_UpdateHealth(int h){
    std::string s = std::to_string(h);
    P2_Health = s;
    }
void UserInterface::P2_UpdateMoney(int m){
    std::string s = std::to_string(m);
    P2_Money = s;
    }
void UserInterface::P2_UpdateScore(int s1){
    std::string s = std::to_string(s1);
    P2_Score = s;
    }
