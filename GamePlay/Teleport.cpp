#include "Teleport.h"

Teleport::Teleport()
{
    //EnterSprite();
    walkingFrames = 15;
    state = 0;
    playerUnit = true; //made true for rendering function //default


    GetLocation().SetX(150);
    GetLocation().SetY(75);

    width = sprite[0].w;
    height = sprite[0].h;
}


void Teleport::SetLocation(int lane)
{
    if (playerUnit)
    {
        GetLocation().SetX(145+GetSprite()[0].w);
        GetLocation().SetY(GetScreenHeight()/10+lane*55-GetSprite()[0].h/2-75);
    }
    else
    {
        GetLocation().SetX(GetScreenWidth()-245);        ///30 ADDED TO INCREASE DELAY IN OBJECT COMING TO SCREEN.
        GetLocation().SetY(GetScreenHeight()/10+lane*55-GetSprite()[0].h/2-80);
    }

}

void Teleport::UpdateLocation()
{
    if (state==4)
    {
        cout<<frame<<endl;
    }
    if (state!=4)
    {
        frame++;
        if (frame/6>=6) //5
        {
            UpdateClip(15);
            frame = 15;
            state = 4;
        }
        UpdateClip(frame/6+5);
    }

}


void Teleport::EnterSprite()
{
        SetSpriteSheet("Sprites/teleport.png");        ///ADD ADDITIONAL CONDITION TO CHECK IF IAMGE DOESN'T EXIT

        SDL_Rect* gSpriteClips = GetSprite();


		gSpriteClips[ 0 ].x =   75;
		gSpriteClips[ 0 ].y =   4;
		gSpriteClips[ 0 ].w =  50;
		gSpriteClips[ 0 ].h = 80;

		gSpriteClips[ 1 ].x =   140;
		gSpriteClips[ 1 ].y =   4;
		gSpriteClips[ 1 ].w =  60;
		gSpriteClips[ 1 ].h = 80;

		gSpriteClips[ 2 ].x = 200;
		gSpriteClips[ 2 ].y =   4;
		gSpriteClips[ 2 ].w =  60;
		gSpriteClips[ 2 ].h = 80;

		gSpriteClips[ 3 ].x =  260;
		gSpriteClips[ 3 ].y =   4;
		gSpriteClips[ 3 ].w = 50;
		gSpriteClips[ 3 ].h = 80;

		gSpriteClips[ 4 ].x = 320;
		gSpriteClips[ 4 ].y =   4;
		gSpriteClips[ 4 ].w =  48;
		gSpriteClips[ 4 ].h = 80;

		gSpriteClips[ 5 ].x = 380;
		gSpriteClips[ 5 ].y =   4;
		gSpriteClips[ 5 ].w =  55;
		gSpriteClips[ 5 ].h = 80;

		gSpriteClips[ 6 ].x = 445;
		gSpriteClips[ 6 ].y =   4;
		gSpriteClips[ 6 ].w =  60;
		gSpriteClips[ 6 ].h = 80;

		gSpriteClips[ 7 ].x = 505;
		gSpriteClips[ 7 ].y =  4;
		gSpriteClips[ 7 ].w =  55;
		gSpriteClips[ 7 ].h = 80;

		gSpriteClips[ 8 ].x = 560;
		gSpriteClips[ 8 ].y = 4;
		gSpriteClips[ 8 ].w = 60;
		gSpriteClips[ 8 ].h = 80;

		gSpriteClips[ 9 ].x = 625;
		gSpriteClips[ 9 ].y =  4;
		gSpriteClips[ 9 ].w =  55;
		gSpriteClips[ 9 ].h = 80;

		gSpriteClips[ 10 ].x = 688;
		gSpriteClips[ 10 ].y =  4;
		gSpriteClips[ 10 ].w =  55;
		gSpriteClips[ 10 ].h = 80;

		gSpriteClips[ 11 ].x = 750;
		gSpriteClips[ 11 ].y =  4;
		gSpriteClips[ 11 ].w =  56;
		gSpriteClips[ 11 ].h = 80;

		gSpriteClips[ 12 ].x = 810;
		gSpriteClips[ 12 ].y =  4;
		gSpriteClips[ 12 ].w =  60;
		gSpriteClips[ 12 ].h = 80;

		gSpriteClips[ 13 ].x = 870;
		gSpriteClips[ 13 ].y =  4;
		gSpriteClips[ 13 ].w =  60;
		gSpriteClips[ 13 ].h = 80;

		gSpriteClips[ 14 ].x = 930;
		gSpriteClips[ 14 ].y =  4;
		gSpriteClips[ 14 ].w =  50;
		gSpriteClips[ 14 ].h = 80;


		gSpriteClips[ 15 ].x = 0;
		gSpriteClips[ 15 ].y = 0;
		gSpriteClips[ 15 ].w = 0;
		gSpriteClips[ 15 ].h = 0;

		SetSprite(gSpriteClips);
}

void Teleport::Draw(SDL_Renderer* gRenderer)
{
    if (GetClip()!=NULL)
    {
        (GetSpriteSheet()).render(GetLocation().GetX(), (GetLocation().GetY() - (GetClip()->h)/10), gRenderer, GetClip() );

    }
}
