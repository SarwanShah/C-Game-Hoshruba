#include "Arrow.h"
#include "EnemyArrow.h"
#include <time.h>
#include <cstdlib>


EnemyArrow::EnemyArrow()
{
    factoryIndex = 16;
    EnterSprite();
    playerUnit = true;  ///made true simply for the sake of rendering though base class draw function.
    width = sprite[0].w;
    height = sprite[0].h;
}



void EnemyArrow::UpdateLocation()
{
    this->SetFrame(0);
    UpdateClip(frame);
    int pt = GetLocation().GetX();
    pt=pt-this->GetSpeed();
    GetLocation().SetX(pt);

}




void EnemyArrow::EnterSprite()
{
        SetSpriteSheet("Sprites/Axe.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();

		gSpriteClips[ 0 ].x =   31;
		gSpriteClips[ 0 ].y =   78;
		gSpriteClips[ 0 ].w =  35;
		gSpriteClips[ 0 ].h = 22;

		SetSprite(gSpriteClips);

}



