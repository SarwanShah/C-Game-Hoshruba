#include "Lane.h"
#include <cstdlib>
#include "Point.h"
#include <time.h>
#include "Queue.h"
#include "PlayerArrow.h"
#include "fstream"

Lane::Lane()
{
    laneNo = 0;
    y = 0;
}


Lane::Lane(int temp)
{
    laneNo = temp;
    y = laneNo*50;
}


void Lane::SetLaneNo(int temp)
{
    laneNo = temp;
    y = laneNo*50;
}


void Lane::SetPlayer(Player* player)
{
    this->player = player;
}


void Lane::SetEnemy(Enemy* enemy)
{
    this->enemy = enemy;
}


void Lane::UpdateLane()
{
//    cout<<"UDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<endl;
    CheckState();


    playerQue.InsideCollision(true);    ///checks for inside collision
    enemyQue.InsideCollision(false);
    playerObjectQue.UpdateQueue();
    enemyObjectQue.UpdateQueue();
    playerQue.UpdateQueue();
    enemyQue.UpdateQueue();


    Warrior* node = deadQue.Top();
    if (node!=NULL)
    {
        node->SetFrame(node->GetFrame()+1);
        if (node->GetFrame()>50) ///body disappears after 50 frames
        {
            deadQue.Dequeue();
        }
    }

    Warrior* playerObject = playerObjectQue.Top();

    if (playerObject!=NULL)
    {
        if (playerObject->GetLocation().GetX()  >  playerObject->GetScreenWidth())
        {
            playerObjectQue.Dequeue();  //Extract
        }
    }

    Warrior* enemyObject = enemyObjectQue.Top();
    if (enemyObject!=NULL)
    {
        if (enemyObject->GetLocation().GetX()  <  0)
        {
            enemyObjectQue.Dequeue(); //extract
        }
    }
}

void Lane::DrawLane(SDL_Renderer* gRenderer)
{

    deadQue.DrawQue(gRenderer);
    playerQue.DrawQue(gRenderer);
    enemyQue.DrawQue(gRenderer);
    playerObjectQue.DrawQue(gRenderer);
    enemyObjectQue.DrawQue(gRenderer);
}


void Lane::CheckTeleportState()
{
    if (playerObjectQue.Length()>0) //Done to remove the teleportation sprite
    {
        if ((playerObjectQue.Top())->GetCharacterState()==4)
        {
            playerObjectQue.Dequeue();
        }
    }

    if (enemyObjectQue.Length()>0)
    {
        if ((enemyObjectQue.Top())->GetCharacterState()==4)
        {
            enemyObjectQue.Dequeue();
        }
    }
}


void Lane::CheckPlayerOnly() //only player unit exists
{
    Warrior* NodeP = playerQue.Top();

    if (NodeP!=NULL)
    {

        if (enemyObjectQue.Top()!=NULL)
        {

            if ((enemyObjectQue.Top())->GetLocation().GetX() <
                NodeP->GetLocation().GetX() + 3*(NodeP->GetWidth())/4)
            {   ///Checks for object collision with 3/4th of unit width
                int tempPlayerHealth = NodeP->GetHealth();

                int tempEHitChance = rand()%100;

                if (tempEHitChance  <  (enemyObjectQue.Top())->GetHitChance())
                {
                    NodeP->SetHealth(tempPlayerHealth - (enemyObjectQue.Top())->GetDamage());
                }

                enemyObjectQue.Dequeue();
            }
        }

        if (NodeP->GetLocation().GetX()  >=   NodeP->GetScreenWidth())
        {
            enemy->DecrementHealth();   //player unit passes into enemy basee
            playerQue.Dequeue();
            player->IncrementScore(100);
        }
    }
}


void Lane::CheckEnemyOnly()
{
    Warrior* NodeE = enemyQue.Top();

    if (NodeE!=NULL)
    {
        if ((NodeE->GetLocation().GetX()  +  NodeE->GetWidth() )  <=  (0))
        {
            player->DecrementHealth();  //enemy unit passes into player base
            enemyQue.Dequeue();
            enemy->IncrementScore(100);
        }

        //kills enemy when no other player i think?
        if (playerObjectQue.Top()!=NULL)       ///NOT ACCURATE STATEMENT : Note that condition to ensure it's within limits of objevt has been removed. add back if creates prorblems.
        {
            if ((((playerObjectQue.Top())->GetLocation().GetX()+3*((playerObjectQue.Top())->GetWidth())/4)  >
                  (NodeE->GetLocation().GetX())) &&  ((playerObjectQue.Top())->GetLocation().GetX() <
                   NodeE->GetLocation().GetX() + NodeE->GetWidth())) ///condition for walking/fighting removed
            {   ///Checks for object collision with 3/4th of unit width
                int tempEnemyHealth = NodeE->GetHealth();

                int tempPHitChance = rand()%100;

                if (tempPHitChance  <  (playerObjectQue.Top())->GetHitChance())
                {
                    NodeE->SetHealth(tempEnemyHealth - (playerObjectQue.Top())->GetDamage());
                }

                playerObjectQue.Dequeue();
            }
        }
    }
}


bool Lane::RemoveDeadUnits()
{
    Warrior* NodeP = playerQue.Top();
    Warrior* NodeE = enemyQue.Top();


    if (NodeP->GetCharacterState()==4 && NodeE->GetCharacterState()==4)
    {
        Warrior* node = playerQue.Extract();
        if (node!=NULL)
        {
            deadQue.Enqueue(node);
        }
        node = enemyQue.Extract();

        if (node!=NULL)
        {
            deadQue.Enqueue(node);
        }
        return false;
    }
    if (NodeP->GetCharacterState()==4 )
    {
        Warrior* node = playerQue.Extract();
        if (node!=NULL)
        {
            deadQue.Enqueue(node);
        }

        return false;
    }
    if (NodeE->GetCharacterState()==4)
    {
        Warrior* node = enemyQue.Extract();
        if (node!=NULL)
        {
            deadQue.Enqueue(node);
        }
            return false;
    }

    return true;
}


void Lane::MeleeVersusMelee(bool withinBound, bool bothAlive)
{
    Warrior* NodeP = playerQue.Top();
    Warrior* NodeE = enemyQue.Top();
    if (NodeP->GetDamage()==8)
    {
        cout<<withinBound<<endl;
        cout<<bothAlive<<endl;
    }

    if (withinBound && bothAlive &&    NodeP->GetDamage()==8 )
    cout<<"Reaches here"<<endl;
    if (((NodeP->GetLocation().GetX()+3*NodeP->GetWidth()/4)>(NodeE->GetLocation().GetX())) &&
        bothAlive && withinBound && NodeP->GetBoolMeleeUnit() && NodeE->GetBoolMeleeUnit())
    {   ///Checks for object collision with 3/4th of unit width
        NodeP->SetCharacterState(1);
        cout<<"IN HERE"<<endl;
        NodeE->SetCharacterState(1);
        int temp1,temp2;
        temp1 = NodeP->GetHealth();
        temp2 = NodeE->GetHealth();

        int temphit1 = rand()%100;
        int temphit2 = rand()%100;

        if (temphit1  <  NodeE->GetHitChance())
            NodeP->SetHealth(temp1-NodeE->GetDamage()); //P health decrements by E damage.

        if (temphit2  <  NodeP->GetHitChance())
            NodeE->SetHealth(temp2-NodeP->GetDamage());
    }
}


void Lane::MeleeVersusRanged(bool withinBound, bool bothAlive)
{
    Warrior* NodeP = playerQue.Top();
    Warrior* NodeE = enemyQue.Top();


    ///TWO LOOPS BELOW DEFINE MELEE UNITS ATTACKING RANGED UNITS.
    if (((NodeP->GetLocation().GetX()+3*NodeP->GetWidth()/4)>(NodeE->GetLocation().GetX()))
         && bothAlive && withinBound && NodeP->GetBoolMeleeUnit() && !NodeE->GetBoolMeleeUnit())
    {   ///Checks for object collision with 3/4th of unit width
        NodeP->SetCharacterState(1);

        int temp1 = NodeE->GetHealth();

        int temphit1 = rand()%100;

        if (temphit1  <  NodeP->GetHitChance())
            NodeE->SetHealth(temp1-NodeP->GetDamage());
    }

    if (((NodeP->GetLocation().GetX()+3*NodeP->GetWidth()/4)>(NodeE->GetLocation().GetX())) &&
        bothAlive && withinBound && NodeE->GetBoolMeleeUnit() && !NodeP->GetBoolMeleeUnit())
    {   ///Checks for object collision with 3/4th of unit width
        NodeE->SetCharacterState(1);

        int temp1 = NodeP->GetHealth();

        int temphit1 = rand()%100;

        if (temphit1  <  NodeE->GetHitChance())
            NodeP->SetHealth(temp1-NodeE->GetDamage());
    }

}


void Lane::RangedVerusRest()
{

    Warrior* NodeP = playerQue.Top();
    Warrior* NodeE = enemyQue.Top();
    ///TWO LOOPS BELOW DEFINE RANGED UNITS ATTACKING other UNITS.

    for (int i = 0 ; i < playerQue.Length(); i++)
    {
        if (!playerQue[i]->GetBoolMeleeUnit())
        {
            Warrior* Parcher = playerQue[i];
            if (((Parcher->GetLocation().GetX()+7*Parcher->GetWidth())>
                    (NodeE->GetLocation().GetX())) && Parcher->GetHealth()>0 && NodeE->GetHealth()>0
                )
            {
                if (Parcher->GetProjectileDelay()>= 100)
                {   //projectiledelay for NodeP->date set to zero inside update location function in player archer
                    Parcher->SetCharacterState(1);

                    Warrior* object = Parcher->FireProjectile();
                    if (object!=NULL  && Parcher->GetProjectileBool()==true)
                    {
                        Parcher->SetProjectileBool(false);
                        playerObjectQue.Enqueue(object);
                        Parcher->SetProjectileDelay(0);
                    }
                }
                Parcher->SetProjectileDelay((Parcher->GetProjectileDelay())+1);
            }
        }

    }


    for (int i = 0 ; i < enemyQue.Length(); i++)
    {
        if (!(enemyQue[i]->GetBoolMeleeUnit()))
        {
            Warrior* Earcher = enemyQue[i];
            if (((Earcher->GetLocation().GetX()-7*Earcher->GetWidth())<(
            NodeP->GetLocation().GetX()))  &&  Earcher->GetHealth()>0 && NodeP->GetHealth()>0)
            {
                if (Earcher->GetProjectileDelay()>= 100)
                {   //projectiledelay for NodeP->date set to zero inside update location function in player archer
                    Earcher->SetCharacterState(1);

                    Warrior* object = Earcher->FireProjectile();
                    if (object!=NULL && Earcher->GetProjectileBool()==true)
                    {
                        Earcher->SetProjectileBool(false);
                        enemyObjectQue.Enqueue(object);
                        Earcher->SetProjectileDelay(0);
                    }
                }
                Earcher->SetProjectileDelay((Earcher->GetProjectileDelay())+1);
            }
        }
    }
}


void Lane::MaintainUnitMovement()
{
    Warrior* NodeP = playerQue.Top();
    Warrior* NodeE = enemyQue.Top();
///THREE LOOPS BELOW CHANGE STATE OVER TO DYING FROM FIGHTING AFTER HEALTH FALLS MUCH.
    if ((NodeP->GetHealth()<=0)&& (NodeE->GetHealth()<=0) && NodeP->GetCharacterState()!=2 && NodeE->GetCharacterState()!=2)
    {

        NodeP->SetFrame(0);
        NodeP->SetCharacterState(2);  //dying
        NodeE->SetFrame(0);
        NodeE->SetCharacterState(2);  //dying

    }

    if ((NodeP->GetHealth()<=0) && (NodeE->GetHealth()>0) && NodeP->GetCharacterState()!=2)    ///CHECK SEQUENCE OF IF CONDITIONS WHICH IS BEST
    {
        NodeP->SetFrame(0);
        NodeP->SetCharacterState(2);  //dying

        enemy->IncrementScore(10); //increases score when player unit is killed

        if (NodeE->GetBoolMeleeUnit())
        {
//               cout<<"melee enemy fwd"<<endl;
            NodeE->SetFrame(0);
            NodeE->SetCharacterState(0);      //walking
        }
        else    ///enemy unit is ranged
        {
            if (NodeE->GetLocation().GetX()-7*NodeE->GetWidth() < NodeP->GetLocation().GetX())
            {
                NodeE->SetFrame(0);
                NodeE->SetCharacterState(0);      //walking
            }
            else
            {
                NodeE->SetFrame(0);
                NodeE->SetCharacterState(1);      //firing
            }
        }
    }

    if ((NodeE->GetHealth()<=0) && (NodeP->GetHealth()>0) && NodeE->GetCharacterState()!=2)
    {
//            cout<<"Goes in third loop: Move player fwd"<<endl;
        NodeE->SetFrame(0);
        NodeE->SetCharacterState(2);  //dying

        player->IncrementScore(10); //increases player score when any unit kills another

        if (NodeP->GetBoolMeleeUnit())
        {
            NodeP->SetFrame(0);
            NodeP->SetCharacterState(0);
        }
        else    ///player unit is ranged
        {
            if (NodeP->GetLocation().GetX()+7*NodeP->GetWidth() > NodeE->GetLocation().GetX())
            {
                NodeP->SetFrame(0);
                NodeP->SetCharacterState(0);      //walking
            }
            else
            {
                NodeP->SetFrame(0);
                NodeP->SetCharacterState(1);      //firing arrows
            }
        }
    }
}


void Lane::CheckState()
{

    Warrior* NodeP = playerQue.Top();
    Warrior* NodeE = enemyQue.Top();

    CheckTeleportState();

    CheckPlayerOnly();

    CheckEnemyOnly();

    if (NodeP!=NULL && NodeE!=NULL)
    {
//            if (NodeP->GetDamage()==7 && NodeE->GetDamage()==7)
//            {
//                cout<<"NODE P "<<NodeP->GetLocation().GetX()<<endl;
//                cout<<"NODE E "<<NodeE->GetLocation().GetX()<<endl;
//                cout<<NodeP->GetCharacterState()<<endl;
//                cout<<NodeE->GetCharacterState()<<endl;
//            }


        if (!RemoveDeadUnits())
        {
            return; //exits function when unit is removed
        }

        bool bothAlive = (NodeP->GetHealth()>0) && NodeE->GetHealth()>0;    ///Loop only entered if both objects alive and clashing

        bool withinBound = NodeP->GetLocation().GetX() < NodeE->GetLocation().GetX() + NodeE->GetWidth();   ///checks if both objects are within bound of eachother


//        if (bothAlive && withinBound)
//        {
//            cout<<"WTF"<<endl;
//        }
        MeleeVersusMelee(withinBound, bothAlive);
        MeleeVersusRanged(withinBound, bothAlive);

        RangedVerusRest();

        MaintainUnitMovement();

    }
}


void Lane::SaveGame()
{
    ofstream file;
    file.open("Game.txt", fstream::app);

    file<<"Q1"<<endl;
    playerQue.SaveGame();
    file<<"Q2"<<endl;
    enemyQue.SaveGame();
    file<<"Q3"<<endl;
    playerObjectQue.SaveGame();
    file<<"Q4"<<endl;
    enemyObjectQue.SaveGame();
    file<<"Q5"<<endl;
    deadQue.SaveGame();

    file.close();
}


void Lane::LoadGame(int skip,SDL_Renderer* gRenderer)
{
    skip=skip+2; //accounts for lane variable and lane index
    ifstream file;
    file.open("Game.txt");
    string line;
    int tempSkip = 0;
    for (int i=0; i<skip; i++)
    {
        getline(file,line);
    }

    getline(file,line);
    skip++;
    cout<<line<<endl;
    getline(file,line);
    if ((atoi(line.c_str())) != 0)  //if queue is not empty
    {
        cout<<"Goes In"<<endl;
        tempSkip = playerQue.LoadGame(skip,gRenderer)-skip-1;
        cout<<"Comes Out"<<endl;
        for (int i=0; i<tempSkip; i++)
        {
            getline(file,line);
    //        cout<<line<<endl;
            skip++;
        }
    }


    getline(file,line);
    skip++;
//    cout<<line<<endl;
    getline(file,line);
    skip++;
//    cout<<line<<endl;
//    cout<<"SKIP"<<skip<<endl;
    if ((atoi(line.c_str())) != 0)  //if queue is not empty
    {
        cout<<"Goes in Enemy Que"<<endl;
        tempSkip = enemyQue.LoadGame(skip,gRenderer)-skip-1;

        for (int i=0; i<tempSkip; i++)
        {
            getline(file,line);
    //        cout<<line<<endl;
            skip++;
        }
    }


    getline(file,line);
//    cout<<line<<endl;
    getline(file,line);
    skip = skip + 2;
    if ((atoi(line.c_str())) != 0)  //if queue is not empty
    {
        cout<<"Goes in P object Que"<<endl;
        tempSkip = playerObjectQue.LoadGame(skip,gRenderer)-skip-1;

        for (int i=0; i<tempSkip; i++)
        {
            getline(file,line);
    //        cout<<line<<endl;
            skip++;
        }
    }


//    cout<<"MOVING ON TO OBJECT"<<endl;
    getline(file,line);
//    cout<<line<<endl;
    getline(file,line);
    skip = skip + 2;
    if ((atoi(line.c_str())) != 0)  //if queue is not empty
    {
        cout<<"Goes in E object Que"<<endl;

        tempSkip = enemyObjectQue.LoadGame(skip,gRenderer)-skip-1;

        for (int i=0; i<tempSkip; i++)
        {
            getline(file,line);
    //        cout<<line<<endl;
            skip++;
        }
    }

    getline(file,line);
//    cout<<line<<endl;
    skip = skip+2;
    getline(file,line);
    if ((atoi(line.c_str())) != 0)  //if queue is not empty
    {
        cout<<"Goes in dead Que"<<endl;

        tempSkip = deadQue.LoadGame(skip,gRenderer)-skip-1;

        for (int i=0; i<tempSkip; i++)
        {
            getline(file,line);
//            cout<<line<<endl;
            skip++;
        }

    }
//    getline(file,line);
//    cout<<line<<endl;

    file.close();

}


Queue<Warrior*>& Lane::operator[](int index)
{
    if (index==0)
        return playerQue;
    else if (index==1)
        return enemyQue;
    else if (index==2)
        return playerObjectQue;
    else if (index==3)
        return enemyObjectQue;
    else
        return deadQue;
}
