#pragma once
#include "Lane.h"

class Map             //Singleton Class
{
private:
    Lane* field;
    static Map* instance;       //Singleton variable
    Map();
    int laneQty;
    Player* player;
    Enemy* enemy;

public:
    void SetSides();            //Assigns player and enemy pointers to each lane
    void SetPlayer(Player*);
    void SetEnemy(Enemy*);
    Lane* GetField();           //Returns Lane Array stored in Map
    void SetField(int);
    static Map* GetInstance();  //Special function for singleton
    void UpdateMap();
    void DrawMap(SDL_Renderer*);
    void SaveGame();
    void LoadGame(int,SDL_Renderer* gRenderer);
};
