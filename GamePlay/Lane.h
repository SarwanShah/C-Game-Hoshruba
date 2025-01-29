#pragma once
#include "Warrior.h"
#include "Queue.h"
#include "Player.h"
#include "Enemy.h"
#include <fstream>

class Lane      //9 Lanes exist in a map, each storing 5 queues.
{
private:
    Player* player;
    Enemy* enemy;

    Queue<Warrior*> playerQue;          //Stores player units in a given lane
    Queue<Warrior*> enemyQue;           //Stores enemy units
    Queue<Warrior*> deadQue;            //Stores dead bodies
    Queue<Warrior*> playerObjectQue;    //Stores player objects e.g. projectiles and teleportation effect
    Queue<Warrior*> enemyObjectQue;     //Stores enemy object e.g. projectiles and teleportation effect

    int laneNo;                     //Stores lane number
    int y;                          //Stores y coordinate of the lane
public:
    Lane();
    Lane(int);
    void SetLaneNo(int);
    void UpdateLane();
    void DrawLane(SDL_Renderer*);

    void CheckState();
    void CheckPlayerOnly();             //Checks Lane when only Player Unit exists
    void CheckEnemyOnly();
    void CheckTeleportState();          //Checks and includes teleportation event if necesasry
    void MeleeVersusMelee(bool, bool);  //Regulates unit fighting
    void MeleeVersusRanged(bool, bool); //Regulates unit fighting
    void RangedVerusRest();             //Regulates unit fighting
    bool RemoveDeadUnits();             //Cleans up screen
    void MaintainUnitMovement();        //Moves Units after fight is over

    void SetPlayer(Player*);
    void SetEnemy(Enemy*);
    void SaveGame();
    void LoadGame(int,SDL_Renderer* gRenderer);

    Queue<Warrior*>& operator[](int);   //Operator overloading utilized to get the 5 queues stored in lane
};
