#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "Buttons.h"
using namespace std;


Button::Button(string Text, LTexture* CharTexture, LTexture* Texture, SDL_Rect* Clip, SDL_Rect charRect, int FontRowSize, int textspacing, int x_pos, int y_pos, int x_size, int y_size)
{
    this->frame = 0;
    this->btnTexture = Texture;
    this->btnClip = Clip;
    BtnText = new Word(Text, CharTexture, charRect, x_pos+(x_size/2)-(Text.length()*33)/3-8, y_pos+(y_size/5)-2, FontRowSize, textspacing);
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->x_size = x_size;
    this->y_size = y_size;
}

Button::~Button()
{
    btnClip = NULL;
    btnTexture = NULL;
    delete BtnText;
    BtnText = NULL;
    cout << "Button Destructor Called!" << endl;
}


void Button::render(SDL_Renderer* gRenderer)
{
        btnTexture->render(x_pos, y_pos, gRenderer, &btnClip[frame], x_size, y_size);
        BtnText->render(gRenderer);
}


bool Button::Animation(SDL_Event* e, int mouse_x, int mouse_y, Mix_Chunk* sound)
{
    bool pressed = false;
    if ((mouse_x > x_pos && mouse_y > y_pos) && (mouse_x < x_pos + x_size && mouse_y < y_pos + y_size)){
        this->frame = 4;
        if ((*e).type == SDL_MOUSEBUTTONDOWN)   {   this->frame = 1; Mix_PlayChannel(-1, sound, 0);}
        if ((*e).type == SDL_MOUSEBUTTONUP)     {   this->frame = 4;   pressed = true;    }
    }
    else
        this->frame = 0;
    return pressed;
}
