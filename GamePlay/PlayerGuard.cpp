#include "PlayerGuard.h"
#include <time.h>
#include <cstdlib>

PlayerGuard::PlayerGuard()
{
    factoryIndex=7;
   // EnterSprite();

    hitFrameMax=3;

    idleFrames = 5;
    fightingFrames = 4;

    playerUnit = true;

    width = sprite[0].w;
    height = sprite[0].h;
}


void PlayerGuard::SetLocation(int lane)
{
    GetLocation().SetX(140+GetSprite()[0].w);
    GetLocation().SetY(GetScreenHeight()/10+lane*55-GetSprite()[0].h/2-55);
}


void PlayerGuard::UpdateLocation()
{
    int chance = rand()%100;
    if (GetCharacterState()==0 && chance<10)     //idle condition is at state 0 for this unit, Special case
    {
        frame++;
        if (frame/idleFrames >= idleFrames)
        {
            frame = 0;
        }

        UpdateClip(frame/idleFrames);
    }
    else if (GetCharacterState()==1)
    {

        frame++;
        if (frame/fightingFrames>=fightingFrames)
        {
            frame = 0;
            SetCharacterState(0);
        }

        UpdateClip(frame/fightingFrames);
    }
}

void PlayerGuard::EnterSprite()
{
        SetSpriteSheet("Sprites/Wizard.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();

		gSpriteClips[ 0 ].x =   160;
		gSpriteClips[ 0 ].y =   15;
		gSpriteClips[ 0 ].w =  60;
		gSpriteClips[ 0 ].h = 60;

		gSpriteClips[ 1 ].x =  160;
		gSpriteClips[ 1 ].y =   75;
		gSpriteClips[ 1 ].w =  60;
		gSpriteClips[ 1 ].h = 60;

		gSpriteClips[ 2 ].x =  160;
		gSpriteClips[ 2 ].y =   135;
		gSpriteClips[ 2 ].w =  60;
		gSpriteClips[ 2 ].h = 60;

		gSpriteClips[ 3 ].x =  160;
		gSpriteClips[ 3 ].y =   195;
		gSpriteClips[ 3 ].w = 60;
		gSpriteClips[ 3 ].h = 60;

		gSpriteClips[ 4 ].x =  160;
		gSpriteClips[ 4 ].y =   255;
		gSpriteClips[ 4 ].w =  60;
		gSpriteClips[ 4 ].h = 60;

		///End walking sprites, start attacking sprites

		gSpriteClips[ 5 ].x = 160;
		gSpriteClips[ 5 ].y =   315;
		gSpriteClips[ 5 ].w =  70;
		gSpriteClips[ 5 ].h = 55;

		gSpriteClips[ 6 ].x = 160;
		gSpriteClips[ 6 ].y =   475;
		gSpriteClips[ 6 ].w =  70;
		gSpriteClips[ 6 ].h = 55;

		gSpriteClips[ 7 ].x = 160;
		gSpriteClips[ 7 ].y =  430;
		gSpriteClips[ 7 ].w =  70;
		gSpriteClips[ 7 ].h =  65;

		gSpriteClips[ 8 ].x = 160;
		gSpriteClips[ 8 ].y =  495;
		gSpriteClips[ 8 ].w =  70;
		gSpriteClips[ 8 ].h = 60;

		SetSprite(gSpriteClips);
}




