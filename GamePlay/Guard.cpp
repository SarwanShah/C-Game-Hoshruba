#include "Guard.h"
#include <cstdlib>

Guard::Guard()
{
    SetDamage(25);
    SetSpeed(1);    //frame increments by 1.
    SetHealth(1000000000);
    SetHitChance(100);    ///check if random changing or not
    meleeUnit = true;
}


