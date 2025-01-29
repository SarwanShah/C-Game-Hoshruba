#include "EnemyMyth.h"
#include <time.h>
#include <cstdlib>

EnemyMyth::EnemyMyth()
{
    factoryIndex=11;
   // EnterSprite();  //Updates clip

    walkingFrames = 5;
    fightingFrames = 4;
    dyingFrames = 3;
    idleFrames = 3;
    idleFrameAddendum = 2;

    hitFrameMax = 7;

    playerUnit = false;

    width = sprite[0].w;
    height = sprite[0].h;
}


void EnemyMyth::EnterSprite()
{
        SetSpriteSheet("Sprites/Myth/Ogre.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips1 = GetSprite();

        int tempHeight = 75;
        int tempWidth = 70;

		gSpriteClips1[ 0 ].x =  150;
		gSpriteClips1[ 0 ].y = 0;
		gSpriteClips1[ 0 ].w = tempWidth;
		gSpriteClips1[ 0 ].h = tempHeight;

		gSpriteClips1[ 1 ].x =    150;
		gSpriteClips1[ 1 ].y =  tempHeight*1;
		gSpriteClips1[ 1 ].w =  tempWidth;
		gSpriteClips1[ 1 ].h = tempHeight;

		gSpriteClips1[ 2 ].x =  150;
		gSpriteClips1[ 2 ].y =  tempHeight*2;
		gSpriteClips1[ 2 ].w =  tempWidth;
		gSpriteClips1[ 2 ].h = tempHeight;

		gSpriteClips1[ 3 ].x =   150;
		gSpriteClips1[ 3 ].y =  tempHeight*3;
		gSpriteClips1[ 3 ].w =  tempWidth;
		gSpriteClips1[ 3 ].h = tempHeight;

		gSpriteClips1[ 4 ].x =   150;
		gSpriteClips1[ 4 ].y =  tempHeight*4;
		gSpriteClips1[ 4 ].w =  tempWidth;
		gSpriteClips1[ 4 ].h = tempHeight-10;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips1[ 5 ].x =  150;
		gSpriteClips1[ 5 ].y =  tempHeight*5-10;
		gSpriteClips1[ 5 ].w =  tempWidth;
		gSpriteClips1[ 5 ].h = tempHeight;

		gSpriteClips1[ 6 ].x =  150;
		gSpriteClips1[ 6 ].y =  440;
		gSpriteClips1[ 6 ].w =  tempWidth;
		gSpriteClips1[ 6 ].h = tempHeight-15;

		gSpriteClips1[ 7 ].x =  150;
		gSpriteClips1[ 7 ].y =  510;
		gSpriteClips1[ 7 ].w =  tempWidth;
		gSpriteClips1[ 7 ].h = tempHeight+5;

		gSpriteClips1[ 8 ].x =  150;
		gSpriteClips1[ 8 ].y = 590;
		gSpriteClips1[ 8 ].w =  tempWidth;
		gSpriteClips1[ 8 ].h = 67;
    ///DYING
		gSpriteClips1[ 9 ].x = 0;
		gSpriteClips1[ 9 ].y = 655;
		gSpriteClips1[ 9 ].w =  65;
		gSpriteClips1[ 9 ].h = 65;

		gSpriteClips1[ 10 ].x = 135;
		gSpriteClips1[ 10 ].y =  655;
		gSpriteClips1[ 10   ].w =  65;
		gSpriteClips1[ 10 ].h = 65;

		gSpriteClips1[ 11 ].x = 260;
		gSpriteClips1[ 11 ].y = 655;
		gSpriteClips1[ 11 ].w =  65;
		gSpriteClips1[ 11 ].h = 65;

		SetSprite(gSpriteClips1);
}

