#pragma once
#include "Warrior.h"
#include "Player.h"
#include "Enemy.h"


class WarriorFactory
{
private:
    SDL_Renderer* gRenderer;
    Warrior* warrior;
    Player* player;
    Enemy* enemy;
public:
    void SetPlayer(Player*);
    void SetEnemy(Enemy*);
    WarriorFactory();
    Warrior* GetWarrior(int);   //Returns warrior depending on index passed
    void SetRenderer(SDL_Renderer* gRenderer);
};
