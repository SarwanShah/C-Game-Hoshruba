#include "EnemyMiner.h"

EnemyMiner::EnemyMiner()
{
    factoryIndex=12;
    playerUnit = false;
}

void EnemyMiner::SetLocation(int pos)
{
    GetLocation().SetX(this->GetScreenWidth() + 10 - 3*pos*width/2);
    GetLocation().SetY(GetScreenHeight()/8+pos*10-height/2);
}


