#include "EnemySwordsman.h"
#include <time.h>
#include <cstdlib>
#include <fstream>

EnemySwordsman::EnemySwordsman()
{
    factoryIndex=8;

   // EnterSprite();  //Updates clip

    hitFrameMax=3;

    walkingFrames = 5;
    fightingFrames = 4;
    dyingFrames = 3;
    idleFrames = 3;
    idleFrameAddendum = 2;

    playerUnit = false;

    width = sprite[0].w;
    height = sprite[0].h;
}


void EnemySwordsman::EnterSprite()
{
        SetSpriteSheet("Sprites/Footman/Axeman.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips1 = GetSprite();

        int tempHeight = 50;
        int tempWidth = 76;

		gSpriteClips1[ 0 ].x =   152;
		gSpriteClips1[ 0 ].y = tempHeight*0+5;
		gSpriteClips1[ 0 ].w = tempWidth;
		gSpriteClips1[ 0 ].h = tempHeight+5;

		gSpriteClips1[ 1 ].x =   152;
		gSpriteClips1[ 1 ].y =  tempHeight*1+5;
		gSpriteClips1[ 1 ].w =  tempWidth;
		gSpriteClips1[ 1 ].h = tempHeight+5;

		gSpriteClips1[ 2 ].x = 152;
		gSpriteClips1[ 2 ].y =  tempHeight*2+5*2;
		gSpriteClips1[ 2 ].w =  tempWidth;
		gSpriteClips1[ 2 ].h = tempHeight+5;

		gSpriteClips1[ 3 ].x =  152;
		gSpriteClips1[ 3 ].y =  tempHeight*3+5*3;
		gSpriteClips1[ 3 ].w =  tempWidth;
		gSpriteClips1[ 3 ].h = tempHeight+5;

		gSpriteClips1[ 4 ].x =  152;
		gSpriteClips1[ 4 ].y =  tempHeight*4+5*4;
		gSpriteClips1[ 4 ].w =  tempWidth;
		gSpriteClips1[ 4 ].h = tempHeight;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips1[ 5 ].x = 152;
		gSpriteClips1[ 5 ].y =  tempHeight*5+5*4;
		gSpriteClips1[ 5 ].w =  tempWidth;
		gSpriteClips1[ 5 ].h = tempHeight+5;

		gSpriteClips1[ 6 ].x = 152;
		gSpriteClips1[ 6 ].y =  tempHeight*6+5*5;
		gSpriteClips1[ 6 ].w =  tempWidth;
		gSpriteClips1[ 6 ].h = tempHeight+5;

		gSpriteClips1[ 7 ].x = 152;
		gSpriteClips1[ 7 ].y =  tempHeight*7+5*6;
		gSpriteClips1[ 7 ].w =  tempWidth;
		gSpriteClips1[ 7 ].h = tempHeight+10;

		gSpriteClips1[ 8 ].x = 152;
		gSpriteClips1[ 8 ].y = tempHeight*8+5*9;
		gSpriteClips1[ 8 ].w =  tempWidth;
		gSpriteClips1[ 8 ].h = tempHeight;

		///Death Sprites
		gSpriteClips1[ 9 ].x = 76;
		gSpriteClips1[ 9 ].y =  tempHeight*10;
		gSpriteClips1[ 9 ].w =  tempWidth;
		gSpriteClips1[ 9 ].h = tempHeight+25;

		gSpriteClips1[ 10 ].x = 76*3;
		gSpriteClips1[ 10 ].y =  tempHeight*10;
		gSpriteClips1[ 10 ].w =  tempWidth;
		gSpriteClips1[ 10 ].h = tempHeight+25;

		gSpriteClips1[ 11 ].x = 0;
		gSpriteClips1[ 11 ].y = tempHeight*11+5*2;
		gSpriteClips1[ 11 ].w =  tempWidth;
		gSpriteClips1[ 11 ].h = tempHeight+10 ;
		SetSprite(gSpriteClips1);

}


