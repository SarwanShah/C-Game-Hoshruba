#include "Myth.h"
#include <time.h>
#include <cstdlib>

Myth::Myth()
{
    SetDamage(10);
    SetSpeed(2);
    SetHealth(600);
    SetHitChance(rand()%20+10);

    meleeUnit = true;
}


