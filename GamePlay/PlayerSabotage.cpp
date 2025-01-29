#include "PlayerSabotage.h"
#include <time.h>
#include <cstdlib>

PlayerSabotage::PlayerSabotage()
{
    factoryIndex =6;
    //EnterSprite();

    hitFrameMax=3;

    walkingFrames = 6;
    fightingFrames = 2;///overlapping with walking frames
    dyingFrames = 6;

    playerUnit = true;

    width = sprite[0].w;
    height = sprite[0].h;
}

void PlayerSabotage::SetLocation(int lane)
{
    GetLocation().SetX(130+GetSprite()[0].w);
    GetLocation().SetY(GetScreenHeight()/10+lane*55-GetSprite()[0].h/2-55);
}


void PlayerSabotage::UpdateLocation()
{
    if (GetCharacterState()==0)
    {
        frame++;
        if (frame/walkingFrames >= walkingFrames)
        {
            frame = 0;
        }
        int pt = GetLocation().GetX();
        pt++;
        GetLocation().SetX(pt);
        UpdateClip(frame/walkingFrames);

        if (this->GetLocation().GetX()+this->GetSprite()[0].w  >  this->GetScreenWidth() - 50)
        {
            this->sabotage = true;
            this->SetCharacterState(1);
        }
    }
    else if (GetCharacterState()==1)
    {

        frame++;
        if (frame/fightingFrames>=fightingFrames)
        {
            frame = 0;
            SetCharacterState(2);
        }

        UpdateClip(frame/fightingFrames);
    }
    else if (GetCharacterState()==2)
    {
        frame++;
        if (frame/dyingFrames >= dyingFrames)
        {
            SetCharacterState(4);
        }
        UpdateClip(frame/dyingFrames+walkingFrames);
    }

}

void PlayerSabotage::EnterSprite()
{
        SetSpriteSheet("Sprites/Squad/DwarveBombSquad.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();


		gSpriteClips[ 0 ].x =   115;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  60;
		gSpriteClips[ 0 ].h = 50;

		gSpriteClips[ 1 ].x =   115;
		gSpriteClips[ 1 ].y =   50;
		gSpriteClips[ 1 ].w =  60;
		gSpriteClips[ 1 ].h = 50;

		gSpriteClips[ 2 ].x =  115;
		gSpriteClips[ 2 ].y =   100;
		gSpriteClips[ 2 ].w =  60;
		gSpriteClips[ 2 ].h = 50;

		gSpriteClips[ 3 ].x =  115;
		gSpriteClips[ 3 ].y =   150;
		gSpriteClips[ 3 ].w = 60;
		gSpriteClips[ 3 ].h = 50;

		gSpriteClips[ 4 ].x = 115;
		gSpriteClips[ 4 ].y =   250;
		gSpriteClips[ 4 ].w =  60;
		gSpriteClips[ 4 ].h = 50;

		gSpriteClips[ 5 ].x = 115;
		gSpriteClips[ 5 ].y =   360;
		gSpriteClips[ 5 ].w =  60;
		gSpriteClips[ 5 ].h = 50;

		///End walking sprites, start stop walking to engage in battle
		gSpriteClips[ 6 ].x = 0;
		gSpriteClips[ 6 ].y =   410;
		gSpriteClips[ 6 ].w =  60;
		gSpriteClips[ 6 ].h = 55;

		gSpriteClips[ 7 ].x = 60;
		gSpriteClips[ 7 ].y =   410;
		gSpriteClips[ 7 ].w =  60;
		gSpriteClips[ 7 ].h = 55;

		gSpriteClips[ 8 ].x = 120;
		gSpriteClips[ 8 ].y =  410;
		gSpriteClips[ 8 ].w =  57;
		gSpriteClips[ 8 ].h = 50;

		gSpriteClips[ 9 ].x = 177;
		gSpriteClips[ 9 ].y = 407;
		gSpriteClips[ 9 ].w = 59;
		gSpriteClips[ 9 ].h = 56;

		gSpriteClips[ 10 ].x = 235;
		gSpriteClips[ 10 ].y =  407;
		gSpriteClips[ 10 ].w =  65;
		gSpriteClips[ 10 ].h = 56;

		gSpriteClips[ 11 ].x = 0;
		gSpriteClips[ 11 ].y =  0;
		gSpriteClips[ 11 ].w =  0;
		gSpriteClips[ 11 ].h = 0;

		SetSprite(gSpriteClips);
}

