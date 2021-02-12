#include "OnScreenObject.h"

OnScreenTexture::OnScreenTexture()
{
    textureRect = NULL;
    textureSheet = NULL;
}



OnScreenTexture::OnScreenTexture(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size, int y_size)
{
    this->textureSheet = textureSheet;
    this->textureRect = textureRect;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->x_size = x_size;
    this->y_size = y_size;
}

void OnScreenTexture::setTexture(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size, int y_size)
{
    this->textureSheet = textureSheet;
    this->textureRect = textureRect;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->x_size = x_size;
    this->y_size = y_size;
}

OnScreenTexture::~OnScreenTexture()
{
    textureSheet = NULL;
    textureRect = NULL;
}

void OnScreenTexture::render(SDL_Renderer* mRenderer)
{
    textureSheet->render(x_pos, y_pos,  mRenderer, textureRect, x_size, y_size);
}

