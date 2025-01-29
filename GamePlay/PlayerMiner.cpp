#include "PlayerMiner.h"

PlayerMiner::PlayerMiner()
{
    factoryIndex = 5;
    playerUnit = true;
}

void PlayerMiner::SetLocation(int pos)
{
    GetLocation().SetX((3*pos*GetSprite()[0].w/2-40));
    GetLocation().SetY(GetScreenHeight()/8+pos*10-GetSprite()[0].h/2);
}

