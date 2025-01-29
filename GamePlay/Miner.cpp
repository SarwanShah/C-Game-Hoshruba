#include "Miner.h"

Miner::Miner()
{
    SetSpeed(1);
    turnBack = false;
    walkingUp = true;
//    EnterSprite();

    width = sprite[0].w;
    height = sprite[0].h;
}


void Miner::EnterSprite()
{
        SetSpriteSheet("Sprites/Peasant/Peasant.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();
        ///Moving Up
		gSpriteClips[ 0 ].x =   10;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  40;
		gSpriteClips[ 0 ].h = 38;

		gSpriteClips[ 1 ].x =   10;
		gSpriteClips[ 1 ].y =   38*1;
		gSpriteClips[ 1 ].w = 40;
		gSpriteClips[ 1 ].h = 38;


		gSpriteClips[ 2 ].x =  10;
		gSpriteClips[ 2 ].y =   38*2;
		gSpriteClips[ 2 ].w =  40;
		gSpriteClips[ 2 ].h = 38;


		gSpriteClips[ 3 ].x =  10;
		gSpriteClips[ 3 ].y =   38*3;
		gSpriteClips[ 3 ].w =40;
		gSpriteClips[ 3 ].h = 38;


		gSpriteClips[ 4 ].x = 10;
		gSpriteClips[ 4 ].y =   38*4;
		gSpriteClips[ 4 ].w =  40;
		gSpriteClips[ 4 ].h = 38;


		///End walking up, turn around to face down.

		gSpriteClips[ 5 ].x = 50;
		gSpriteClips[ 5 ].y =  0;
		gSpriteClips[ 5 ].w =  35;
		gSpriteClips[ 5 ].h = 38;

		gSpriteClips[ 6 ].x = 90;
		gSpriteClips[ 6 ].y =  0;
		gSpriteClips[ 6 ].w =  30;
		gSpriteClips[ 6 ].h = 38;

		gSpriteClips[ 7 ].x = 120;
		gSpriteClips[ 7 ].y = 0;
		gSpriteClips[ 7 ].w =  40;
		gSpriteClips[ 7 ].h = 38;

		        ///walking down now

		gSpriteClips[ 8 ].x = 155;
		gSpriteClips[ 8 ].y = 480;
		gSpriteClips[ 8 ].w =  35;
		gSpriteClips[ 8 ].h = 42;

		gSpriteClips[ 9 ].x = 155;
		gSpriteClips[ 9 ].y =522;
		gSpriteClips[ 9 ].w =  35;
		gSpriteClips[ 9 ].h = 42;

		gSpriteClips[ 10 ].x = 155;
		gSpriteClips[ 10 ].y = 566;
		gSpriteClips[ 10 ].w =  35;
		gSpriteClips[ 10 ].h = 44;

		gSpriteClips[ 11 ].x = 155;
		gSpriteClips[ 11 ].y = 610;
		gSpriteClips[ 11 ].w =  35;
		gSpriteClips[ 11 ].h = 42;

		gSpriteClips[ 12 ].x = 155;
		gSpriteClips[ 12 ].y = 652;
		gSpriteClips[ 12 ].w =  35;
		gSpriteClips[ 12 ].h = 43;



		SetSprite(gSpriteClips);

}


void Miner::UpdateLocation()
{
    if (this->GetLocation().GetY()-10<0 && walkingUp == true)    //reaches max height.
    {
        turnBack = true;
        walkingUp = false;
    }

    if (this->GetLocation().GetY() + GetSprite()[0].h >  GetScreenHeight()/8 + 100) ///change if/when playerminer starting y coordinates are changed??
    {
        walkingUp = true;
        turnBack = false;
    }

    frame++;

    if (walkingUp==true && turnBack==false)
    {
        this->SetY(GetLocation().GetY()-speed);
        if (frame/5>=5)
        {
            frame = 0;
        }
        UpdateClip(frame/5);
    }
    else if (walkingUp == false)
    {
        this->SetY(GetLocation().GetY()+speed);
        if (frame/5>=5)
        {
            frame = 0;
        }
        UpdateClip(frame/5 + 4 + 4);
    }
    else if (turnBack == true)
    {
        if (frame/4>=4)
        {
            frame = 0;
            turnBack = false;
            walkingUp = false;
        }
        UpdateClip(frame/4+5);
    }
}


