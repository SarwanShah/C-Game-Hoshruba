#pragma once
#include <string>
#include <cstdlib>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Warrior.h"
#include <fstream>
#include <cstdlib>

using namespace std;

class GamePlay
{
private:
    Player* player;
    Enemy* enemy;
    WarriorFactory warFactory;

    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;

    Map* zone;      //stores singleton map class

    int playerGuardLane;    //stores lane where player guard is positioned
    int enemyGuardLane;     //stores lane where enemy guard is positioned

    int lane1;      //Arrow points to middle lane by default, player1
    int lane2;      //arrow points to middle lane by default, player2

public:
    GamePlay(Map*, SDL_Renderer* gRenderer);
    void InitializeGuard();         //guard's position initialized automatically
    void LaunchPlayerUnit(int);     //player created unit on lower map
    void LaunchEnemyUnit(int);      //enemy creates unit on lower map
    void LaunchPlayerMiner();
    void LaunchEnemyMiner();
    void DeadMinerScoreIncrement();     //Score increases when miner is killed
    bool CheckForSpacePlayerLane(int);  //Checks if additional player unit can be enqueued in a given lane
    bool CheckForSpaceEnemyLane(int);
    void UpdateGamePlay();              //Updates map, score etc.
    bool GeneratPlayerSabotage(bool);   //Generates sabotage unit
    bool GenerateEnemySabotage(bool);
    void RandomizePlayerGuard();        //Randomly move guard between lanes
    void RandomizeEnemyGuard();
    void SetDimensions(int,int);
    void SaveGamePlay();
    void LoadGamePlay(SDL_Renderer* gRenderer);
    int GetLane1();
    int GetLane2();
    void SetLane1(int);
    void SetLane2(int);

    bool Boolean(string);           //converts string to bool
    Player* GetPlayer();
    Enemy* GetEnemy();

    void DrawGamePlay(SDL_Renderer*);   //draws game
    ~GamePlay();    //deallocates player, enemy and map
};

