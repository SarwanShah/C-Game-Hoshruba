#include "GamePlay.h"
#include <string>


GamePlay::GamePlay(Map* zone, SDL_Renderer* gRenderer)
{
    this->zone = zone;

    playerGuardLane = 2;
    enemyGuardLane = 2;
    lane1 = 3;
    lane2 = 3;

	player = new Player;
	enemy = new Enemy;

    zone->SetPlayer(player);
    zone->SetEnemy(enemy);
    zone->SetSides();   //assigns player/enemy to lanes

//    if (gRenderer==NULL)
//        cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
    warFactory.SetRenderer(gRenderer);
    warFactory.SetPlayer(player);
    warFactory.SetEnemy(enemy);
//    cout << "END" << endl;
}

GamePlay::~GamePlay()
{
    if (player!=NULL)
        delete player;

    if (enemy!=NULL)
        delete enemy;

    if (zone!=NULL)
        delete zone;

    player = NULL;
    enemy = NULL;
    zone = NULL;
}

void GamePlay::InitializeGuard()
{
    Warrior* war2=warFactory.GetWarrior(7);
    war2->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
    war2->SetLocation(2);       //initiated on middle lane
    (zone->GetField()[6])[0].Enqueue(war2);


    Warrior* war1=warFactory.GetWarrior(14);
    war1->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
    war1->SetLocation(2);
    (zone->GetField()[6])[1].Enqueue(war1);
}

void GamePlay::LaunchPlayerUnit(int unit2Index)
{
    if (CheckForSpacePlayerLane(lane2))
    {
        Warrior* war2=warFactory.GetWarrior(unit2Index);
        war2->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH); ///change x,y to make it mpore readbale
        war2->SetLocation(lane2);
        (zone->GetField()[lane2-1])[0].Enqueue(war2); //Note that index of field is lane-1
        cout<<"Enqueued "<<lane2<<endl;
    }

}

bool GamePlay::CheckForSpacePlayerLane(int lane)
{

//    cout<<"PLAYER QUE LENGTH: "<<zone->GetField()[lane-1][0].Length()<<endl;
    if (zone->GetField()[lane-1][0].Bottom()!=NULL)
    {
        if (zone->GetField()[lane-1][0].Bottom()->GetLocation().GetX() +
            (zone->GetField()[lane-1][0].Bottom()->GetWidth())/2 >= 0 )
            {
//                cout<<"GOES IN HERE WOW"<<endl;
//                cout<<zone->GetField()[lane-1][0].Bottom()->GetLocation().GetX() +
//            (zone->GetField()[lane-1][0].Bottom()->GetWidth())/2<<endl;
                return true;
            }
    }
    else
    {
//        cout<<"Nopes it went here bruh"<<endl;
        return true;
    }

    return false;
}


bool GamePlay::CheckForSpaceEnemyLane(int lane)
{
    if (zone->GetField()[lane-1][1].Bottom()!=NULL)
    {
        if (zone->GetField()[lane-1][1].Bottom()->GetLocation().GetX() +
            (zone->GetField()[lane-1][1].Bottom()->GetWidth())/2 <= zone->GetField()[lane-1][1].Bottom()->GetScreenWidth() )
            {
                return true;
            }
    }
    else
    {
        return true;
    }

    return false;
}

void GamePlay::LaunchEnemyUnit(int unit1Index)
{
    if (CheckForSpaceEnemyLane(lane1))
    {
        Warrior* war1=warFactory.GetWarrior(unit1Index);
        war1->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
        war1->SetLocation(lane1);
        (zone->GetField()[lane1-1][1].Enqueue(war1));
    }
}

void GamePlay::LaunchPlayerMiner()
{
    Warrior* war2=warFactory.GetWarrior(5);
    war2->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
    war2->SetLocation((zone->GetField()[8])[0].Length()+1);
    (zone->GetField()[8])[0].Enqueue(war2);
}

void GamePlay::LaunchEnemyMiner()
{
    Warrior* war1=warFactory.GetWarrior(12);
    war1->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
    war1->SetLocation((zone->GetField()[8])[1].Length()+1);
    (zone->GetField()[8])[1].Enqueue(war1);
}

void GamePlay::UpdateGamePlay()
{
    DeadMinerScoreIncrement();

    zone->UpdateMap();
}

void GamePlay::DrawGamePlay(SDL_Renderer* gRenderer)
{
    zone->DrawMap(gRenderer);
}

bool GamePlay::GeneratPlayerSabotage(bool playerSabotage)
{
    int random = rand()%3;
    if ((zone->GetField()[random + 5])[0].Length()<1)
    {
        playerSabotage = false; ///inside while loop to ensure that unit created only in an empty row

        Warrior* war2=warFactory.GetWarrior(6);
        cout<<SCREEN_HEIGHT<<" "<<SCREEN_WIDTH<<endl;
        war2->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
        war2->SetLocation(random + 1);

        (zone->GetField()[random + 5])[0].Enqueue(war2);
    }
    return playerSabotage;
}

bool GamePlay::GenerateEnemySabotage(bool enemySabotage)
{
    int random = rand()%3;

    if ((zone->GetField()[random + 5])[1].Length()<1)
    {
        enemySabotage = false;
        Warrior* war1=warFactory.GetWarrior(13);
        war1->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
        war1->SetLocation(random + 1);
        (zone->GetField()[random + 5])[1].Enqueue(war1);
    }
    return enemySabotage;
}

void GamePlay::RandomizePlayerGuard()
{
    int randomLane = rand()%3;

    if ((randomLane+1) != playerGuardLane && ((zone->GetField()[playerGuardLane + 4])[0].Length()>0))
    {
        if ((((zone->GetField()[playerGuardLane + 4])[0].Top()))->GetHealth() > 100)
        {
            Warrior* war1=warFactory.GetWarrior(17);    //origination teleport effect
            war1->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
            war1->SetLocation(playerGuardLane);       //initiated on middle lane
            (zone->GetField()[playerGuardLane + 4])[2].Enqueue(war1);


            (zone->GetField()[playerGuardLane + 4])[0].Dequeue();

            playerGuardLane = randomLane + 1;
            Warrior* war2=warFactory.GetWarrior(7);
            war2->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
            war2->SetLocation(randomLane+1);       //initiated on middle lane
            (zone->GetField()[randomLane + 5])[0].Enqueue(war2);
//
            Warrior* war=warFactory.GetWarrior(17); //destination teleportation effect
            war->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
            war->SetLocation(randomLane+1);       //initiated on middle lane
            (zone->GetField()[randomLane + 5])[2].Enqueue(war);
        }
    }
}

void GamePlay::RandomizeEnemyGuard()
{
    int randomLane = rand()%3;

    if ((randomLane+1) != enemyGuardLane && (((zone->GetField()[enemyGuardLane + 4])[1].Length()))>0)
    {
        if ((((zone->GetField()[enemyGuardLane + 4])[1].Top()))->GetHealth() > 100)
        {
            Warrior* war2=warFactory.GetWarrior(17);    //origination teleport effect
            war2->SetBoolPlayerUnit(false);
            war2->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
            war2->SetLocation(enemyGuardLane);       //initiated on middle lane
            (zone->GetField()[enemyGuardLane + 4])[3].Enqueue(war2);


            (zone->GetField()[enemyGuardLane + 4])[1].Dequeue();

            enemyGuardLane = randomLane + 1;
            Warrior* war1=warFactory.GetWarrior(14);
            war1->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
            war1->SetLocation(randomLane+1);
            (zone->GetField()[randomLane + 5])[1].Enqueue(war1);

            Warrior* war=warFactory.GetWarrior(17); //destination teleportation effect
            war->SetBoolPlayerUnit(false);
            war->SetScreenSize(SCREEN_HEIGHT,SCREEN_WIDTH);
            war->SetLocation(randomLane+1);       //initiated on middle lane
            (zone->GetField()[randomLane + 5])[3].Enqueue(war);

        }
    }
}

void GamePlay::DeadMinerScoreIncrement()
{
    for (int i=0; i <3; i++)
    {       //blow up enemy miners
        if ((zone->GetField()[i + 5])[0].Top()!=NULL)
        {
            if ((zone->GetField()[8])[1].Length() > 0)
            {
                if (((zone->GetField()[i + 5])[0].Top())->GetSabotage() == true)
                {
                    (zone->GetField()[8])[1].Dequeue();

                    player->IncrementScore(75);

                    (((zone->GetField()[i + 5])[0].Top())->SetSabotage(false));
                }
            }
        }

        if ((zone->GetField()[i + 5])[1].Top()!=NULL)
        {
        //                        blows up player miners
            if ((zone->GetField()[8])[0].Length() > 0)
            {
                if (((zone->GetField()[i + 5])[1].Top())->GetSabotage() == true)
                {
                    (zone->GetField()[8])[0].Dequeue();

                    enemy->IncrementScore(75);

                    ((zone->GetField()[i + 5])[1].Top())->SetSabotage(false);
                }
            }
        }
    }
}

void GamePlay::SaveGamePlay()
{
    ofstream file;
    file.open("Game.txt", fstream::app);

    file<<playerGuardLane<<endl;
    file<<enemyGuardLane<<endl;

    file<<lane1<<endl;
    file<<lane2<<endl;

    player->SaveGame();
    enemy->SaveGame();
    zone->SaveGame();

    file.close();
}

void GamePlay::LoadGamePlay(SDL_Renderer* gRenderer)
{
    ifstream file;
    string line;
    file.open("Game.txt", fstream::app);

    for (int i=0; i<14; i++)
    {
        getline(file,line);
    }

    getline(file, line);
    playerGuardLane = atoi(line.c_str());
//                        cout<<playerGuardLane<<endl;
    getline(file, line);
    enemyGuardLane = atoi(line.c_str());
//                        cout<<enemyGuardLane<<endl;

    getline(file, line);
    lane1 = atoi(line.c_str());
//                        cout<<lane1<<endl;
    getline(file, line);
    lane2 = atoi(line.c_str());
//                        cout<<lane2<<endl;

    player->LoadGame(18);
    enemy->LoadGame(22);
    zone->LoadGame(26, gRenderer);
}

void GamePlay::SetDimensions(int x, int y)
{
    SCREEN_WIDTH = x;
    SCREEN_HEIGHT = y;
}

bool GamePlay::Boolean(string val)
{
    if (val=="0")
        return false;

    if (val=="1")
        return true;
    return true;
}

Player* GamePlay::GetPlayer()
{
    return player;
}

Enemy* GamePlay::GetEnemy()
{
    return enemy;
}

int GamePlay::GetLane1()
{
    return lane1;
}

int GamePlay::GetLane2()
{
    return lane2;
}

void GamePlay::SetLane1(int lane1)
{
    this->lane1 = lane1;
}

void GamePlay::SetLane2(int lane2)
{
    this->lane2 = lane2;
}
