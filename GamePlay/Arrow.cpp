#include "Arrow.h"
#include <time.h>
#include <cstdlib>

Arrow::Arrow()
{
    hitFrameCount=0;
    SetDamage(25);
    SetSpeed(8);        //frame increments by 2
    SetHitChance(rand()%20+30);    ///check if random changing or not
    meleeUnit = false;
}



