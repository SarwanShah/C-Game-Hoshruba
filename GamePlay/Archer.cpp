#include "Archer.h"
#include <time.h>
#include <cstdlib>

Archer::Archer()
{
    SetProjectileDelay(100);
    SetDamage(5);
    SetSpeed(1);        //frame increments by 2
    SetHealth(150);
    SetHitChance(rand()%50+30);    ///check if random changing or not
    meleeUnit = false;
}

