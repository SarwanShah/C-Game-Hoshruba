#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <fstream>

Map::Map()
{
    field = new Lane[9];    //Default map has 5 lanes bottom, 3 lanes top, 1 lane miners
    for (int i=0; i<9; i++)
    {
        field[i].SetLaneNo(i+1);
        field[i].SetPlayer(player);
        field[i].SetEnemy(enemy);
    }
    laneQty = 9;
}


void Map::SetField(int qty)      //Changes number of lanes
{
    if (field!=NULL)
        delete field;

    field = new Lane[qty];
    laneQty = qty;
}


Lane* Map::GetField()
{
    return field;
}


Map* Map::GetInstance()
{
    if (instance==NULL)
        instance = new Map;

    return instance;
}


void Map::UpdateMap()
{
    for (int i=0; i<laneQty; i++ )
    {
        field[i].UpdateLane();
    }
}


void Map::DrawMap(SDL_Renderer* gRenderer)
{
    for (int i=0; i<laneQty; i++)
    {
        field[i].DrawLane(gRenderer);
    }
}


 void Map::SetPlayer(Player* player)
{
    this->player = player;
}


void Map::SetEnemy(Enemy* enemy)
{
    this->enemy = enemy;
}


void Map::SetSides()
{
    for (int i=0; i<laneQty; i++)
    {
        field[i].SetPlayer(player);
        field[i].SetEnemy(enemy);
    }
}


void Map::SaveGame()
{
    ofstream file;
    file.open("Game.txt", fstream::app);
    file<<"Map"<<endl;
    for (int i=0; i<laneQty; i++)
    {
        file<<"Lane"<<endl;
        file<<i<<endl;
        field[i].SaveGame();
    }

    file.close();
}


void Map::LoadGame(int skip, SDL_Renderer* gRenderer)
{
    ifstream file;
    file.open("Game.txt", fstream::app);
    string line;
    getline(file,line);
    skip++; //accounts for map variable stored in file
    for (int i=0; i<skip; i++)
    {
        getline(file, line);
    }

    int skipCount = skip;
    for (int i=0; i<laneQty; i++)
    {
        field[i].LoadGame(skip, gRenderer);
        skipCount = 1;
        getline(file,line);
        while (line!="Lane")
        {
            skipCount++;
            getline(file,line);

            if (line=="")   //file iteration ends
                break;
        }
        skip = skip + skipCount;
    }

    file.close();
}
