#include "Enemy.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Enemy::Enemy()
{
    money = 100;
    health = 20;
    score = 0;
}


void Enemy::SetMoney(int money)
{
    this->money = money;
}


void Enemy::SetHealth(int health)
{
    this->health = health;
}


void Enemy::SetScore(int score)
{
    this->score = score;
}


int Enemy::GetScore()
{
    return score;
}


int Enemy::GetMoney()
{
    return money;
}


int Enemy::GetHealth()
{
    return health;
}


bool Enemy::CheckAffordability(int type)
{
    if (type==8)
    {
        if (money>50)
        {
            money = money - 50;
            return true;
        }
    }
    else if (type==9)
    {
        if (money>75)
        {
            money = money - 75;
            return true;
        }
    }
    else if (type==10)
    {
        if (money>125)
        {
            money = money - 125;
            return true;
        }
    }
    else if (type==11)
    {
        if (money>200)
        {
            money = money - 200;
            return true;
        }
    }
    else if (type==12)   //miner
    {
        if (money>250)
        {
            money = money - 250;
            return true;
        }
    }
    else if (type==13)   //sabotage
    {
        if (money>150)
        {
            money = money - 150;
            return true;
        }
    }

    return false;
}


void Enemy::IncrementMoney(int minerQty)
{
    money = money + 20*minerQty;
}


void Enemy::DecrementHealth()
{
    health--;
}


void Enemy::IncrementScore(int score)
{
    this->score = this->score + score;
}


void Enemy::SaveGame()
{
    ofstream file;
    file.open("Game.txt", fstream::app);

    file<<"E"<<endl;
    file<<money<<endl;
    file<<health<<endl;
    file<<score<<endl;

    file.close();
}


void Enemy::LoadGame(int skip)
{
    ifstream file;
    string line;
    file.open("Game.txt");

    for (int i=0; i<=skip; i++)
    {
        getline(file,line);
    }

    getline(file,line);
    money = atoi(line.c_str());
    getline(file,line);
    health = atoi(line.c_str());
    getline(file,line);
    score = atoi(line.c_str());
}
