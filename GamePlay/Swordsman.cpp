#include "Swordsman.h"
#include <time.h>
#include <cstdlib>

Swordsman::Swordsman()
{
    SetDamage(4);
    SetSpeed(1);    //frame increments by 1.
    SetHealth(250);
    SetHitChance(rand()%10+10);    ///check if random changing or not
    meleeUnit = true;
}

