#include "Arrow.h"
#include "PlayerArrow.h"
#include <time.h>
#include <cstdlib>


PlayerArrow::PlayerArrow()
{
    factoryIndex = 15;
   // EnterSprite();
    playerUnit = true;

    width = sprite[0].w;
    height = sprite[0].h;

}


void PlayerArrow::UpdateLocation()
{
    SetFrame(0);
    UpdateClip(this->GetFrame());

    int pt = GetLocation().GetX();
    pt=pt+this->GetSpeed();
    GetLocation().SetX(pt);
}


void PlayerArrow::EnterSprite()
{
        SetSpriteSheet("Sprites/Arrow.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();

		gSpriteClips[ 0 ].x =   460;
		gSpriteClips[ 0 ].y =   720;
		gSpriteClips[ 0 ].w =  35;
		gSpriteClips[ 0 ].h = 15;

		SetSprite(gSpriteClips);
}


