#pragma once
#include "Arrow.h"


class EnemyArrow: public Arrow
{
private:
    void UpdateLocation();
public:
    EnemyArrow();
    void EnterSprite();

};

