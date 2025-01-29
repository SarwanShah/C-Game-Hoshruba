#include "EnemyGuard.h"
#include <time.h>
#include <cstdlib>

EnemyGuard::EnemyGuard()
{
    factoryIndex=14;
    //EnterSprite();  //Updates clip

    hitFrameMax=3;

    idleFrames = 5;
    fightingFrames = 4;

    playerUnit = false;

    width = sprite[0].w;
    height = sprite[0].h;
}

void EnemyGuard::SetLocation(int lane)
{
    GetLocation().SetX(GetScreenWidth()-240);        ///30 ADDED TO INCREASE DELAY IN OBJECT COMING TO SCREEN.
    GetLocation().SetY(GetScreenHeight()/10+lane*55-height/2-80);

}


void EnemyGuard::UpdateLocation()
{
    int chance = rand()%100;
    if (GetCharacterState()==0 && chance<10)
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
        }

        UpdateClip(frame/fightingFrames + walkingFrames);
    }
}

void EnemyGuard::EnterSprite()
{
        SetSpriteSheet("Sprites/Peasant/Peon.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips1 = GetSprite();

        int tempWidth = 40;

		gSpriteClips1[ 0 ].x =   110;
		gSpriteClips1[ 0 ].y = 0;
		gSpriteClips1[ 0 ].w = tempWidth;
		gSpriteClips1[ 0 ].h = 37;

		gSpriteClips1[ 1 ].x =   110;
		gSpriteClips1[ 1 ].y =  35;
		gSpriteClips1[ 1 ].w =  tempWidth;
		gSpriteClips1[ 1 ].h = 40;

		gSpriteClips1[ 2 ].x = 110;
		gSpriteClips1[ 2 ].y =  75;
		gSpriteClips1[ 2 ].w =  tempWidth;
		gSpriteClips1[ 2 ].h = 40;

		gSpriteClips1[ 3 ].x =  110;
		gSpriteClips1[ 3 ].y =  115;
		gSpriteClips1[ 3 ].w =  tempWidth;
		gSpriteClips1[ 3 ].h = 40;

		gSpriteClips1[ 4 ].x = 110;
		gSpriteClips1[ 4 ].y =  155;
		gSpriteClips1[ 4 ].w =  tempWidth;
		gSpriteClips1[ 4 ].h = 40;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips1[ 5 ].x = 100;
		gSpriteClips1[ 5 ].y = 200;
		gSpriteClips1[ 5 ].w =  60;
		gSpriteClips1[ 5 ].h = 55;

		gSpriteClips1[ 6 ].x = 100;
		gSpriteClips1[ 6 ].y =  255;
		gSpriteClips1[ 6 ].w =  60;
		gSpriteClips1[ 6 ].h = 45;

		gSpriteClips1[ 7 ].x = 100;
		gSpriteClips1[ 7 ].y =  300;
		gSpriteClips1[ 7 ].w =  60;
		gSpriteClips1[ 7 ].h = 55;

		gSpriteClips1[ 8 ].x = 100;
		gSpriteClips1[ 8 ].y = 360;
		gSpriteClips1[ 8 ].w =  60;
		gSpriteClips1[ 8 ].h = 45;

}


