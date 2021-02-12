#include "UI_Bar.h"

UIBar::UIBar(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size, int y_size):OnScreenTexture(textureSheet, textureRect, x_pos, y_pos, x_size, y_size)
{
    cout << "UI Bar Constructor Called" << endl;
}

UIBar::~UIBar()
{
    cout << "UI Bar Destructor Called" << endl;
}

void UIBar::render(SDL_Renderer* gRenderer)
{
    textureSheet->render(x_pos, y_pos,  gRenderer, &textureRect[0], x_size, y_size);
    for (int i = 0; i < 13; i++)
    {
        textureSheet->render(x_pos+(x_size*(i+1)), y_pos, gRenderer, &textureRect[1], x_size, y_size);

    }
    textureSheet->render(x_pos+(x_size*(13+1)), y_pos,  gRenderer, &textureRect[2], x_size, y_size);
}

