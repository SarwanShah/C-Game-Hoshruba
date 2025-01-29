#include "PlayerSwordsman.h"
#include <time.h>
#include <cstdlib>

PlayerSwordsman::PlayerSwordsman()
{
    factoryIndex = 1;
    //EnterSprite();

    hitFrameMax=3;

    walkingFrames = 5;
    fightingFrames = 4;
    dyingFrames = 3;
    idleFrames = 3;
    idleFrameAddendum = 2;

    playerUnit = true;

    width = sprite[0].w;
    height = sprite[0].h;
}


void PlayerSwordsman::EnterSprite()
{
        SetSpriteSheet("Sprites/Footman/Swordsman.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();
		gSpriteClips[ 0 ].x =   148;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  74;
		gSpriteClips[ 0 ].h = 56.7;

		gSpriteClips[ 1 ].x =   148;
		gSpriteClips[ 1 ].y =   56.7;
		gSpriteClips[ 1 ].w =  74;
		gSpriteClips[ 1 ].h = 56.7;

		gSpriteClips[ 2 ].x =  148;
		gSpriteClips[ 2 ].y =   113.4;
		gSpriteClips[ 2 ].w =  74;
		gSpriteClips[ 2 ].h = 56.7;

		gSpriteClips[ 3 ].x =  148;
		gSpriteClips[ 3 ].y =   170;
		gSpriteClips[ 3 ].w =  74;
		gSpriteClips[ 3 ].h = 50;

		gSpriteClips[ 4 ].x =  148;
		gSpriteClips[ 4 ].y =   220;
		gSpriteClips[ 4 ].w =  74;
		gSpriteClips[ 4 ].h = 50;

		///End walking sprites, character stop walking to engage in battle

		gSpriteClips[ 5 ].x = 148;
		gSpriteClips[ 5 ].y =   270;
		gSpriteClips[ 5 ].w =  74;
		gSpriteClips[ 5 ].h = 60;

		gSpriteClips[ 6 ].x = 148;
		gSpriteClips[ 6 ].y =   330;
		gSpriteClips[ 6 ].w =  74;
		gSpriteClips[ 6 ].h = 60;

		gSpriteClips[ 7 ].x = 148;
		gSpriteClips[ 7 ].y =   390;
		gSpriteClips[ 7 ].w =  74;
		gSpriteClips[ 7 ].h = 60;

		gSpriteClips[ 8 ].x = 148;
		gSpriteClips[ 8 ].y = 450;
		gSpriteClips[ 8 ].w =  74;
		gSpriteClips[ 8 ].h = 60;

        ///DEATH

		int tempHeight=50;
		int tempWidth=76;

		gSpriteClips[ 9 ].x = 76;
		gSpriteClips[ 9 ].y =  tempHeight*10+5*3;
		gSpriteClips[ 9 ].w =  tempWidth;
		gSpriteClips[ 9 ].h = tempHeight+20;

		gSpriteClips[ 10 ].x = 76*3;
		gSpriteClips[ 10 ].y =  tempHeight*10+5*3;
		gSpriteClips[ 10 ].w =  tempWidth;
		gSpriteClips[ 10 ].h = tempHeight+20;

		gSpriteClips[ 11 ].x = 0;
		gSpriteClips[ 11 ].y = tempHeight*11+5*5;
		gSpriteClips[ 11 ].w =  tempWidth;
		gSpriteClips[ 11 ].h = tempHeight;


		SetSprite(gSpriteClips);
}

