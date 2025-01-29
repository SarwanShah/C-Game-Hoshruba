#include "PlayerMyth.h"
#include <time.h>
#include <cstdlib>


PlayerMyth::PlayerMyth()
{
    factoryIndex = 4;
    //EnterSprite();

    walkingFrames = 4;
    fightingFrames = 3;
    dyingFrames = 5;
    idleFrames = 3;
    idleFrameAddendum = 1;

    hitFrameMax = 7;

    playerUnit = true;

    width = sprite[0].w;
    height = sprite[0].h;
}


void PlayerMyth::EnterSprite()
{
        SetSpriteSheet("Sprites/Myth/GryphonRider.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();

		gSpriteClips[ 0 ].x =   164;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  86;
		gSpriteClips[ 0 ].h = 85;

		gSpriteClips[ 1 ].x =   164;
		gSpriteClips[ 1 ].y =  85;
		gSpriteClips[ 1 ].w =  86;
		gSpriteClips[ 1 ].h = 75;

		gSpriteClips[ 2 ].x =   164;
		gSpriteClips[ 2 ].y =   160;
		gSpriteClips[ 2 ].w =  86;
		gSpriteClips[ 2 ].h = 85;

		gSpriteClips[ 3 ].x =  164;
		gSpriteClips[ 3 ].y =   245;
		gSpriteClips[ 3 ].w =  86;
		gSpriteClips[ 3 ].h = 90;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips[ 4 ].x =   164;
		gSpriteClips[ 4 ].y =   335;
		gSpriteClips[ 4 ].w =  86;
		gSpriteClips[ 4 ].h = 75;

		gSpriteClips[ 5 ].x =  164;
		gSpriteClips[ 5 ].y =   410;
		gSpriteClips[ 5 ].w = 86;
		gSpriteClips[ 5 ].h = 90;

		gSpriteClips[ 6 ].x = 164;
		gSpriteClips[ 6 ].y =   500;
		gSpriteClips[ 6 ].w =  86;
		gSpriteClips[ 6 ].h = 85;

		///DYING

		gSpriteClips[ 7 ].x = 0;
		gSpriteClips[ 7 ].y =   580;
		gSpriteClips[ 7 ].w =  85;
		gSpriteClips[ 7 ].h = 75;

		gSpriteClips[ 8 ].x = 85;
		gSpriteClips[ 8 ].y =  580;
		gSpriteClips[ 8 ].w =  75;
		gSpriteClips[ 8 ].h = 75;

		gSpriteClips[ 9 ].x = 160;
		gSpriteClips[ 9 ].y =   580;
		gSpriteClips[ 9 ].w =  85;
		gSpriteClips[ 9 ].h = 75;

		gSpriteClips[ 10 ].x = 245;
		gSpriteClips[ 10 ].y =    580;
		gSpriteClips[ 10 ].w =  75;
		gSpriteClips[ 10 ].h = 75;

		gSpriteClips[ 11 ].x = 320;
		gSpriteClips[ 11 ].y =  580;
		gSpriteClips[ 11 ].w =  80;
		gSpriteClips[ 11 ].h = 75;

		SetSprite(gSpriteClips);
}


