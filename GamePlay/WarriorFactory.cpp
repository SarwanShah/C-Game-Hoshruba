#include "WarriorFactory.h"
#include "PlayerSwordsman.h"
#include "EnemySwordsman.h"
#include "PlayerCavalry.h"
#include "EnemyCavalry.h"
#include "PlayerMyth.h"
#include "EnemyMyth.h"
#include "PlayerArcher.h"
#include "EnemyArcher.h"
#include "PlayerArrow.h"
#include "EnemyArrow.h"
#include "PlayerMiner.h"
#include "EnemyMiner.h"
#include "PlayerSabotage.h"
#include "EnemySabotage.h"
#include "PlayerGuard.h"
#include "EnemyGuard.h"
#include "Teleport.h"



WarriorFactory::WarriorFactory()
{
    gRenderer = NULL;

    player = NULL;
    enemy = NULL;
    warrior = NULL;
}


Warrior* WarriorFactory::GetWarrior(int type)
{
    if (type==1)
        warrior = new PlayerSwordsman;

    else if (type==2)
        warrior = new PlayerArcher;

    else if (type==3)
        warrior = new PlayerCavalry;

    else if (type==4)
        warrior = new PlayerMyth;

    else if (type==5)
    {
        warrior = new PlayerMiner;
        warrior->SetRenderer(gRenderer);
        warrior->EnterSprite();
    }

    else if (type==6)
        warrior = new PlayerSabotage;

    else if (type==7)
        warrior = new PlayerGuard;



    else if (type==8)
        warrior = new EnemySwordsman;

    else if (type==9)
        warrior = new EnemyArcher;

    else if (type==10)
        warrior = new EnemyCavalry;

    else if (type==11)
        warrior = new EnemyMyth;

    else if (type==12)
        warrior = new EnemyMiner;

    else if (type==13)
        warrior = new EnemySabotage;

    else if (type==14)
        warrior = new EnemyGuard;



    else if (type==15)
        warrior = new PlayerArrow;  //for saving/loading,
                                    ///consider if can be used in archer class or not
    else if (type==16)
        warrior = new EnemyArrow;


    else if (type==17)
        warrior = new Teleport;

    if (gRenderer==NULL)
        cout<<"ABDULLAH IS AN IDIOT"<<endl;
        warrior->SetRenderer(gRenderer);
        warrior->EnterSprite();
        warrior->SetWidth(warrior->GetSprite()[0].w);
    return warrior;

}


void WarriorFactory::SetPlayer(Player* player)
{
    this->player = player;
}


void WarriorFactory::SetEnemy(Enemy* enemy)
{
    this->enemy = enemy;
}

void WarriorFactory::SetRenderer(SDL_Renderer* gRenderer)
{
    this->gRenderer = gRenderer;
}
