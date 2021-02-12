#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "Characters.h"

Character::Character()
{
    CharTexture = NULL;
}


Character::Character(LTexture* gSpriteSheetTexture, char c, SDL_Rect charRect, int x_pos, int y_pos, int FontRowSize)
{
    this->shownChar = c;
    this->CharTexture = gSpriteSheetTexture;
    this->charRect.w =  charRect.w;
    this->charRect.h =  charRect.h;
    this->setPosition(x_pos, y_pos);
    this->setChar(c, FontRowSize);
    this->CharTexture->setHeight(0);
    this->CharTexture->setWidth(0);
}


void Character::setTexture(char c, LTexture* gSpriteSheetTexture, SDL_Rect charRect, int x_pos, int y_pos, int FontRowSize)
{
    this->shownChar = c;
    this->CharTexture = gSpriteSheetTexture;
    this->charRect.w = charRect.w;
    this->charRect.h = charRect.h;
    this->setPosition(x_pos, y_pos);
    this->setChar(c, FontRowSize);
    this->CharTexture->setHeight(0);
    this->CharTexture->setWidth(0);
}



void Character::setPosition(int x , int y)
{
    this->x = x;
    this->y = y;
}


void Character::render(SDL_Renderer* gRenderer)
{
    CharTexture->render(this->x, this->y, gRenderer, &charRect);
}


void Character::setChar(char c, int FontRowSize)
{
    int ascii = c;
    if (ascii <= 90 && ascii >= 65)
    {
        ascii-=65;
        this->charRect.x = (ascii%FontRowSize)*charRect.w;
        this->charRect.y = ((int)(ascii/FontRowSize))*charRect.h;
    }
    else if (ascii == 46)
    {
        ascii += 6;
        this->charRect.x = (ascii%FontRowSize)*charRect.w;
        this->charRect.y = ((int)(ascii/FontRowSize))*charRect.h;
    }

}

Character::~Character()
{
    CharTexture = NULL;
    cout << "Character Destructor Called!" << endl;
}
