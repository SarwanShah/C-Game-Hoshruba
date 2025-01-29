#include "Cavalry.h"
#include <time.h>
#include <cstdlib>

Cavalry::Cavalry()
{
    SetDamage(7);
    SetSpeed(2);        //frame increments by 2
    SetHealth(400);
    SetHitChance(rand()%20+20);    ///check if random changing or not
    meleeUnit = true;
}


