#include "EnemyCavalry.h"
#include <time.h>
#include <cstdlib>

EnemyCavalry::EnemyCavalry()
{
    factoryIndex=10;
    //EnterSprite();  //Updates clip

    walkingFrames = 5;
    fightingFrames = 4;
    dyingFrames = 3;
    idleFrames = 3;
    idleFrameAddendum = 2;

    playerUnit = false;

}


void EnemyCavalry::EnterSprite()
{
        SetSpriteSheet("Sprites/Cavalry/EnemyKnight.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips1 = GetSprite();

        int tempHeight = 65;
        int tempWidth = 70;

		gSpriteClips1[ 0 ].x =   135;
		gSpriteClips1[ 0 ].y = 0;
		gSpriteClips1[ 0 ].w = tempWidth;
		gSpriteClips1[ 0 ].h = tempHeight;

		gSpriteClips1[ 1 ].x =   135;
		gSpriteClips1[ 1 ].y =  tempHeight*1;
		gSpriteClips1[ 1 ].w =  tempWidth;
		gSpriteClips1[ 1 ].h = tempHeight;

		gSpriteClips1[ 2 ].x = 135;
		gSpriteClips1[ 2 ].y =  tempHeight*2;
		gSpriteClips1[ 2 ].w =  tempWidth;
		gSpriteClips1[ 2 ].h = tempHeight;

		gSpriteClips1[ 3 ].x =  135;
		gSpriteClips1[ 3 ].y =  tempHeight*3;
		gSpriteClips1[ 3 ].w =  tempWidth;
		gSpriteClips1[ 3 ].h = tempHeight+5;

		gSpriteClips1[ 4 ].x =  135;
		gSpriteClips1[ 4 ].y =  265;
		gSpriteClips1[ 4 ].w =  tempWidth;
		gSpriteClips1[ 4 ].h = tempHeight+5;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips1[ 5 ].x = 135;
		gSpriteClips1[ 5 ].y =  tempHeight*5+5*2;
		gSpriteClips1[ 5 ].w =  tempWidth;
		gSpriteClips1[ 5 ].h = tempHeight;

		gSpriteClips1[ 6 ].x = 135;
		gSpriteClips1[ 6 ].y =  tempHeight*6+5*2;
		gSpriteClips1[ 6 ].w =  tempWidth;
		gSpriteClips1[ 6 ].h = tempHeight+5;

		gSpriteClips1[ 7 ].x = 135;
		gSpriteClips1[ 7 ].y =  tempHeight*7+5*3;
		gSpriteClips1[ 7 ].w =  tempWidth;
		gSpriteClips1[ 7 ].h = tempHeight;

		gSpriteClips1[ 8 ].x = 135;
		gSpriteClips1[ 8 ].y = tempHeight*8+5*3;
		gSpriteClips1[ 8 ].w =  tempWidth;
		gSpriteClips1[ 8 ].h = tempHeight-5;

    ///DYING
		gSpriteClips1[ 9 ].x = 135;
		gSpriteClips1[ 9 ].y = 600;
		gSpriteClips1[ 9 ].w =  70;
		gSpriteClips1[ 9 ].h = 65;

		gSpriteClips1[ 10 ].x = 0;
		gSpriteClips1[ 10 ].y =  600;
		gSpriteClips1[ 10   ].w =  70;
		gSpriteClips1[ 10 ].h = 65;

		gSpriteClips1[ 11 ].x = 215;
		gSpriteClips1[ 11 ].y = 600;
		gSpriteClips1[ 11 ].w =  65;
		gSpriteClips1[ 11 ].h = 65;

		SetSprite(gSpriteClips1);

}


