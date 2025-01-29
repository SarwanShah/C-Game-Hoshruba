#include "PlayerCavalry.h"
#include <time.h>
#include <cstdlib>

PlayerCavalry::PlayerCavalry()
{
    factoryIndex =3;
   // EnterSprite();

    walkingFrames = 5;
    fightingFrames = 4;
    dyingFrames = 2;
    idleFrames = 3;
    idleFrameAddendum = 2;

    playerUnit = true;

        width = 60;
//    width = sprite[0].w;
//    height = sprite[0].h;
}

void PlayerCavalry::EnterSprite()
{
        SetSpriteSheet("Sprites/Cavalry/Knight.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();

		gSpriteClips[ 0 ].x =   148;
		gSpriteClips[ 0 ].y =   10;
		gSpriteClips[ 0 ].w =  74;
		gSpriteClips[ 0 ].h = 70;

		gSpriteClips[ 1 ].x =   148;
		gSpriteClips[ 1 ].y =  70;
		gSpriteClips[ 1 ].w =  74;
		gSpriteClips[ 1 ].h = 80;

		gSpriteClips[ 2 ].x =  148;
		gSpriteClips[ 2 ].y =   150;
		gSpriteClips[ 2 ].w =  74;
		gSpriteClips[ 2 ].h = 70;

		gSpriteClips[ 3 ].x =  148;
		gSpriteClips[ 3 ].y =   220;
		gSpriteClips[ 3 ].w =  74;
		gSpriteClips[ 3 ].h = 80;

		gSpriteClips[ 4 ].x =  148;
		gSpriteClips[ 4 ].y =   300;
		gSpriteClips[ 4 ].w =  74;
		gSpriteClips[ 4 ].h = 70;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips[ 5 ].x = 148;
		gSpriteClips[ 5 ].y =   370;
		gSpriteClips[ 5 ].w =  74;
		gSpriteClips[ 5 ].h = 70;

		gSpriteClips[ 6 ].x = 148;
		gSpriteClips[ 6 ].y =   440;
		gSpriteClips[ 6 ].w =  74;
		gSpriteClips[ 6 ].h = 80;

		gSpriteClips[ 7 ].x = 148;
		gSpriteClips[ 7 ].y =   520;
		gSpriteClips[ 7 ].w =  74;
		gSpriteClips[ 7 ].h = 80;

		gSpriteClips[ 8 ].x = 148;
		gSpriteClips[ 8 ].y = 600;
		gSpriteClips[ 8 ].w =  74;
		gSpriteClips[ 8 ].h = 70;

		/////DEATH

		gSpriteClips[ 9 ].x = 148;
		gSpriteClips[ 9 ].y =   670;
		gSpriteClips[ 9 ].w =  74;
		gSpriteClips[ 9 ].h = 75;

		gSpriteClips[ 10 ].x = 0;
		gSpriteClips[ 10 ].y =   745;
		gSpriteClips[ 10 ].w =  80;
		gSpriteClips[ 10 ].h = 60;


		SetSprite(gSpriteClips);

}



