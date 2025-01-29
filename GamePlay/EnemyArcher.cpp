#include "EnemyArcher.h"
#include <time.h>
#include <cstdlib>

EnemyArcher::EnemyArcher()
{
    factoryIndex=9;
    EnterSprite();

//    SetCharacterState(0);

    playerUnit = false;

    walkingFrames = 5;
    fightingFrames = 4;
    dyingFrames = 3;
    idleFrames = 4;
    idleFrameAddendum = 0;

    hitFrameMax = 5;

    fireProjectileCount = 5;

    width = sprite[0].w;
    height = sprite[0].h;
}


Warrior* EnemyArcher::FireProjectile()
{
    if (fireProjectile)
    {
        projectile = new EnemyArrow;
        projectile->SetX(this->GetLocation().GetX());

        projectile->SetY(this->GetLocation().GetY()+15);
        projectile->SetScreenSize(this->GetScreenHeight() , this->GetScreenWidth());
        projectile->SetRenderer(gRenderer);
        projectile->EnterSprite();
        projectile->SetWidth(projectile->GetSprite()[0].w);
    }
    return projectile;
}

void EnemyArcher::EnterSprite()
{

        SetSpriteSheet("Sprites/Archer/Axethrower.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips1 = GetSprite();

        int tempHeight = 50;
        int tempWidth = 50;

		gSpriteClips1[ 0 ].x =   140;
		gSpriteClips1[ 0 ].y = 10;
		gSpriteClips1[ 0 ].w = tempWidth;
		gSpriteClips1[ 0 ].h = tempHeight;

		gSpriteClips1[ 1 ].x =   140;
		gSpriteClips1[ 1 ].y =  tempHeight*1+10;
		gSpriteClips1[ 1 ].w =  tempWidth;
		gSpriteClips1[ 1 ].h = tempHeight;

		gSpriteClips1[ 2 ].x = 140;
		gSpriteClips1[ 2 ].y =  tempHeight*2+5*2;
		gSpriteClips1[ 2 ].w =  tempWidth;
		gSpriteClips1[ 2 ].h = tempHeight;

		gSpriteClips1[ 3 ].x =  140;
		gSpriteClips1[ 3 ].y =  tempHeight*3+5*2;
		gSpriteClips1[ 3 ].w =  tempWidth;
		gSpriteClips1[ 3 ].h = tempHeight+5;

		gSpriteClips1[ 4 ].x =  140;
		gSpriteClips1[ 4 ].y =  tempHeight*4+5*3;
		gSpriteClips1[ 4 ].w =  tempWidth;
		gSpriteClips1[ 4 ].h = tempHeight+5;

		///End walking sprites, start stop walking to engage in battle

		gSpriteClips1[ 5 ].x = 130;
		gSpriteClips1[ 5 ].y =  265;
		gSpriteClips1[ 5 ].w =  60;
		gSpriteClips1[ 5 ].h = 65;

		gSpriteClips1[ 6 ].x = 120;
		gSpriteClips1[ 6 ].y =  330;
		gSpriteClips1[ 6 ].w =  70;
		gSpriteClips1[ 6 ].h = 60;

		gSpriteClips1[ 7 ].x = 130;
		gSpriteClips1[ 7 ].y =  390;
		gSpriteClips1[ 7 ].w =  60;
		gSpriteClips1[ 7 ].h = 60;

		gSpriteClips1[ 8 ].x = 130;
		gSpriteClips1[ 8 ].y = 450;
		gSpriteClips1[ 8 ].w =  60;
		gSpriteClips1[ 8 ].h = 60;

		///Death Sprites
		gSpriteClips1[ 9 ].x = 70;
		gSpriteClips1[ 9 ].y =  503;
		gSpriteClips1[ 9 ].w =  60;
		gSpriteClips1[ 9 ].h = 62;

		gSpriteClips1[ 10 ].x = 190;
		gSpriteClips1[ 10 ].y =  503;
		gSpriteClips1[ 10 ].w =  60;
		gSpriteClips1[ 10 ].h = 63;

		gSpriteClips1[ 11 ].x = 0;
		gSpriteClips1[ 11 ].y = 560;
		gSpriteClips1[ 11 ].w =  70;
		gSpriteClips1[ 11 ].h = 64 ;


		SetSprite(gSpriteClips1);

}
