#include "Sabotage.h"
#include <cstdlib>

Sabotage::Sabotage()
{
    SetDamage(25);
    SetSpeed(1);    //frame increments by 1.
    SetHealth(100);
    SetHitChance(100);    ///check if random changing or not
    meleeUnit = true;
}

