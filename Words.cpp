#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "Words.h"

Word::Word()
{
    charTexture = NULL;
    characters = NULL;
}

Word::Word(string str, LTexture* gSpriteSheetTexture, SDL_Rect charRect, int x, int y, int FontRowSize, int spacing)
{
    this->charTexture = gSpriteSheetTexture;
    this->renderWord = str;
    this->x_pos = x;
    this->y_pos = y;
    this->setText(renderWord, charRect, FontRowSize, spacing);
}

int Word::getTextLength()
{
    return this->renderWord.length();
}

void Word::render(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < this->renderWord.length(); i++)
    {
        characters[i].render(gRenderer);
    }
}

void Word::setText(string str, SDL_Rect charRect, int FontRowSize, int spacing)
{
    characters = new Character[this->renderWord.length()];
    for (int i = 0; i < this->renderWord.length(); i++)
    {
        characters[i].setTexture(str[i], this->charTexture, charRect, x_pos+(spacing*i), y_pos, FontRowSize);
    }
}

Word::~Word()
{
    charTexture = NULL;
    characters = NULL;
}
