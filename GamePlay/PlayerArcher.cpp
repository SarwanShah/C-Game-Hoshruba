#include "PlayerArcher.h"
#include <time.h>
#include <cstdlib>

PlayerArcher::PlayerArcher()
{
    factoryIndex=2;
  //  EnterSprite();

    playerUnit = true;

    walkingFrames = 5;
    fightingFrames = 2;
    dyingFrames = 3;
    idleFrames = 3;
    idleFrameAddendum = 2;

    hitFrameMax = 10;

    fireProjectileCount = 6;

    width = sprite[0].w;
    height = sprite[0].h;
}


Warrior* PlayerArcher::FireProjectile()
{
    if (fireProjectile)
    {
        projectile = new PlayerArrow;
        projectile->UpdateLocation();

        projectile->SetX(this->GetLocation().GetX());
            projectile->SetY(this->GetLocation().GetY()+15);

        projectile->SetScreenSize(this->GetScreenHeight() , this->GetScreenWidth());
        projectile->SetRenderer(gRenderer);
            projectile->EnterSprite();
        projectile->SetWidth(projectile->GetSprite()[0].w);

    }
    return projectile;
}


void PlayerArcher::EnterSprite()
{
        SetSpriteSheet("Sprites/Archer/Archer.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();

		gSpriteClips[ 0 ].x =   120;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  60;
		gSpriteClips[ 0 ].h = 70;

		gSpriteClips[ 1 ].x =   120;
		gSpriteClips[ 1 ].y =   70;
		gSpriteClips[ 1 ].w =  60;
		gSpriteClips[ 1 ].h = 80;

		gSpriteClips[ 2 ].x =  120;
		gSpriteClips[ 2 ].y =   150;
		gSpriteClips[ 2 ].w =  60;
		gSpriteClips[ 2 ].h = 70;

		gSpriteClips[ 3 ].x =  120;
		gSpriteClips[ 3 ].y =   220;
		gSpriteClips[ 3 ].w = 60;
		gSpriteClips[ 3 ].h = 70;

		gSpriteClips[ 4 ].x =  120;
		gSpriteClips[ 4 ].y =   290;
		gSpriteClips[ 4 ].w =  60;
		gSpriteClips[ 4 ].h = 70;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips[ 5 ].x = 120;
		gSpriteClips[ 5 ].y =   370;
		gSpriteClips[ 5 ].w =  60;
		gSpriteClips[ 5 ].h = 60;

		gSpriteClips[ 6 ].x = 120;
		gSpriteClips[ 6 ].y =   445;
		gSpriteClips[ 6 ].w =  60;
		gSpriteClips[ 6 ].h = 60;

		///DEATH

        int tempHeight=50;
		int tempWidth=55;

		gSpriteClips[ 7 ].x = 60;
		gSpriteClips[ 7 ].y =  tempHeight*10+5*3;
		gSpriteClips[ 7 ].w =  tempWidth;
		gSpriteClips[ 7 ].h = tempHeight+20;

		gSpriteClips[ 8 ].x = 175;
		gSpriteClips[ 8 ].y =  tempHeight*10+5*3;
		gSpriteClips[ 8 ].w =  tempWidth;
		gSpriteClips[ 8 ].h = tempHeight+20;

		gSpriteClips[ 9 ].x = 0;
		gSpriteClips[ 9 ].y = tempHeight*11+5*5;
		gSpriteClips[ 9 ].w =  tempWidth+5;
		gSpriteClips[ 9 ].h = tempHeight;

		SetSprite(gSpriteClips);

}



