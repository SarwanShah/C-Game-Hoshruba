#include "EnemySabotage.h"
#include <time.h>
#include <cstdlib>

EnemySabotage::EnemySabotage()
{
    factoryIndex=13;
    //EnterSprite();  //Updates clip

    hitFrameMax=3;

    walkingFrames = 6;
    fightingFrames = 2;
    dyingFrames = 7;

    playerUnit = false;

    width = sprite[0].w;
    height = sprite[0].h;
}


void EnemySabotage::SetLocation(int lane)
{
    GetLocation().SetX(GetScreenWidth()-230);        ///30 ADDED TO INCREASE DELAY IN OBJECT COMING TO SCREEN.
    GetLocation().SetY(GetScreenHeight()/10+lane*55-GetSprite()[0].h/2-55);
}


void EnemySabotage::UpdateLocation()
{
    if (GetCharacterState()==0)
    {
        frame++;
        if (frame/walkingFrames >= walkingFrames)
        {
            frame = 0;
        }
        int pt = GetLocation().GetX();
        pt--;
        GetLocation().SetX(pt);
        UpdateClip(frame/walkingFrames);


        if (this->GetLocation().GetX()+this->GetSprite()[0].w  <  100)
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

        UpdateClip(frame/fightingFrames + walkingFrames);
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


void EnemySabotage::EnterSprite()
{
        SetSpriteSheet("Sprites/Squad/GoblinSappers.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips1 = GetSprite();

        int tempHeight = 45;
        int tempWidth = 50;

		gSpriteClips1[ 0 ].x =   120;
		gSpriteClips1[ 0 ].y = 0;
		gSpriteClips1[ 0 ].w = tempWidth;
		gSpriteClips1[ 0 ].h = tempHeight;

		gSpriteClips1[ 1 ].x =   120;
		gSpriteClips1[ 1 ].y =  45;
		gSpriteClips1[ 1 ].w =  tempWidth;
		gSpriteClips1[ 1 ].h = tempHeight;

		gSpriteClips1[ 2 ].x = 120;
		gSpriteClips1[ 2 ].y =  130;    //130
		gSpriteClips1[ 2 ].w =  tempWidth;
		gSpriteClips1[ 2 ].h = tempHeight;

		gSpriteClips1[ 3 ].x =  120;
		gSpriteClips1[ 3 ].y =  225;
		gSpriteClips1[ 3 ].w =  tempWidth;
		gSpriteClips1[ 3 ].h = tempHeight;

		gSpriteClips1[ 4 ].x =  120;
		gSpriteClips1[ 4 ].y =  310;
		gSpriteClips1[ 4 ].w =  tempWidth;
		gSpriteClips1[ 4 ].h = tempHeight;

		gSpriteClips1[ 5 ].x =  120;
		gSpriteClips1[ 5 ].y =  350;
		gSpriteClips1[ 5 ].w =  tempWidth;
		gSpriteClips1[ 5 ].h = tempHeight;

		///End walking sprites, start stop walking to engage in battle


		gSpriteClips1[ 6 ].x = 0;
		gSpriteClips1[ 6 ].y =  395;
		gSpriteClips1[ 6 ].w =  50;
		gSpriteClips1[ 6 ].h = 50;

		gSpriteClips1[ 7 ].x = 50;
		gSpriteClips1[ 7 ].y =   395;
		gSpriteClips1[ 7 ].w =  55;
		gSpriteClips1[ 7 ].h = 50;

		gSpriteClips1[ 8 ].x = 105;
		gSpriteClips1[ 8 ].y =  395;
		gSpriteClips1[ 8 ].w =  50;
		gSpriteClips1[ 8 ].h = 50;

		gSpriteClips1[ 9 ].x = 165;
		gSpriteClips1[ 9 ].y =   395;
		gSpriteClips1[ 9 ].w =  65;
		gSpriteClips1[ 9 ].h = 50;

		gSpriteClips1[ 10 ].x = 235;
		gSpriteClips1[ 10 ].y =   395;
		gSpriteClips1[ 10 ].w =  55;
		gSpriteClips1[ 10 ].h = 50;

		gSpriteClips1[ 11 ].x = 0;
		gSpriteClips1[ 11 ].y =  440;
		gSpriteClips1[ 11 ].w =  70;
		gSpriteClips1[ 11 ].h = 50 ;

		gSpriteClips1[ 12 ].x = 0;
		gSpriteClips1[ 12 ].y = 0;
		gSpriteClips1[ 12 ].w = 0;
		gSpriteClips1[ 12 ].h = 0 ;

}

