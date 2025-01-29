#include "Player.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Player::Player()
{
    money = 100;
    health = 20;
    score = 0;
}


void Player::SetMoney(int money)
{
    this->money = money;
}


void Player::SetHealth(int health)
{
    this->health = health;
}


int Player::GetMoney()
{
    return money;
}


int Player::GetHealth()
{
    return health;
}


bool Player::CheckAffordability(int type)
{
    if (type==1)
    {
        if (money>50)
        {
            money = money - 50;
            return true;
        }
    }
    else if (type==2)
    {
        if (money>75)
        {
            money = money - 75;
            return true;
        }
    }
    else if (type==3)
    {
        if (money>125)
        {
            money = money - 125;
            return true;
        }
    }
    else if (type==4)
    {
        if (money>200)
        {
            money = money - 200;
            return true;
        }
    }
    else if (type==5)   //miner
    {
        if (money>250)
        {
            money = money - 250;
            return true;
        }
    }
    else if (type==6)   //sabotage
    {
        if (money>150)
        {
            money = money - 150;
            return true;
        }
    }

    return false;
}


void Player::IncrementMoney(int minerQty)
{
    money = money + 20*minerQty;
}


void Player::DecrementHealth()
{
    health--;
}

void Player::IncrementScore(int score)
{
    this->score = this->score + score;
}


void Player::SetScore(int score)
{
    this->score = score;
}

int Player::GetScore()
{
    return score;
}


void Player::SaveGame()
{
    ofstream file;
    file.open("Game.txt", fstream::app);

    file<<"P"<<endl;
    file<<money<<endl;
    file<<health<<endl;
    file<<score<<endl;

    file.close();
}


void Player::LoadGame(int skip)
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
