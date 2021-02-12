#include "AudioIcons.h"

AudioIcon::AudioIcon(LTexture* Texture, SDL_Rect* Clip, int frame, int x_pos, int y_pos, int x_size, int y_size)
{
    this->frame = frame;
    this->iconTexture = Texture;
    this->iconClip = Clip;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->x_size = x_size;
    this->y_size = y_size;
}

AudioIcon::~AudioIcon()
{
    iconClip = NULL;
    iconTexture = NULL;
    cout << "Audio Icon Destructor Called" << endl;
}

void AudioIcon::render(SDL_Renderer* gRenderer)
{
        iconTexture->render(x_pos, y_pos, gRenderer, &iconClip[frame], x_size, y_size);
}

void AudioIcon::Animation(SDL_Event* e, int mouse_x, int mouse_y, Mix_Chunk* Sound)
{
    if ((mouse_x > x_pos && mouse_y > y_pos) && (mouse_x < x_pos + x_size && mouse_y < y_pos + y_size)){
        if ((*e).type == SDL_MOUSEBUTTONDOWN)
        {
            Mix_PlayChannel(-1, Sound, 0);
            if (frame == 1)         {   this->frame = 0;    Mix_VolumeMusic(0);    Mix_Volume(-1, 0);   }
            else if (frame == 0)    {   this->frame = 1;    Mix_VolumeMusic(MIX_MAX_VOLUME);    Mix_Volume(-1, MIX_MAX_VOLUME); }
            else if (frame == 2)    {   this->frame = 3;    Mix_PauseMusic();   }
            else if (frame == 3)    {   this->frame = 2;    Mix_ResumeMusic();  }
        }
    }
}
