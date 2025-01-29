#pragma once
#include <fstream>

class Player
{
private:
    int money;
    int health;
    int score;
public:
    Player();
    void SetMoney(int);
    void SetHealth(int);
    void IncrementScore(int);   //Score incremented when enemy unit killed, player unit passes into enemy territory
                                //and when player unit blow up enemy miners
    void SetScore(int);
    int GetScore();
    int GetMoney();
    int GetHealth();
    bool CheckAffordability(int);   //takes unit type as input and tells if it can afford it.
    void IncrementMoney(int);   //increments money depending on miner
    void DecrementHealth();     //health decremented when enemy units pass into player territory
    void SaveGame();
    void LoadGame(int);
};
