#pragma once
#include <fstream>

class Enemy
{
private:
    int money;
    int health;
    int score;

public:
    Enemy();
    void SetMoney(int);
    void SetHealth(int);
    void IncrementScore(int);       //score increment when player unit killed, player territory breached, player miners blown up
    void SetScore(int);
    int GetScore();
    int GetMoney();
    int GetHealth();
    bool CheckAffordability(int);   //inputs unit type and tells if it can afford it.
    void IncrementMoney(int);       //money incremented depending on miner number
    void DecrementHealth();         //health decremented when player unit passes into enemy territory
    void SaveGame();
    void LoadGame(int);

};

