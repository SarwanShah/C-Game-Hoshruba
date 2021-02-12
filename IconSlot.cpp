#include "IconSlot.h"

IconSlot::IconSlot(){}

IconSlot::IconSlot(LTexture* textureSheet, SDL_Rect* textureRect, int x_pos, int y_pos, int x_size, int y_size):OnScreenTexture(textureSheet, textureRect, x_pos, y_pos, x_size, y_size)
{
    cout << "Icon Slot Bar Constructor Called" << endl;
}

void IconSlot::setTexture(LTexture* textureSheet, LTexture* UnitIconSheet, SDL_Rect* UnitIconRect, SDL_Rect* textureRect, int frame, int adjust, int x_pos, int y_pos, int x_size, int y_size)
{
    this->textureSheet = textureSheet;
    this->textureRect = textureRect;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->x_size = x_size;
    this->y_size = y_size;
    this->frame = frame;
    this->select = false;
    Icon = new UnitIcon(UnitIconSheet, UnitIconRect, x_pos+(textureRect->w/3)+(UnitIconRect->w/3)+adjust, y_pos+10, (textureRect->w/1.5), UnitIconRect->h);
}

void IconSlot::render(SDL_Renderer* gRenderer)
{
    textureSheet->render(x_pos, y_pos,  gRenderer, &textureRect[frame], x_size, y_size);
    Icon->render(gRenderer);
}


void IconSlot::setSelect(bool select)
{
    this->select = select;
}


void IconSlot::KeyboardAnimation()
{
    if (select)
    {
        if (frame < 3)
            frame += 6;
    }
    else
    {
        if(frame > 2)
            frame -= 6;
    }

}


