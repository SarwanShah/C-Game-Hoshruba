#pragma once
#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include "WarriorFactory.h"

using namespace std;

template<typename T, typename t=int>
class Queue
{
private:
    Node<T>* head;       //Keeps track of latest element added to Queue
    Node<T>* tail;       //Points towards the oldest element in Queue
    int length;

public:
    Queue()
    {
        head=tail=NULL;
        length = 0;
    }


    ~Queue()
    {
        Node<T>* temp = tail;

//        while (head!=NULL)
//        {
//            temp = head;
//            head = head->next;
//            delete temp;
//        }
        while(temp!=NULL)
        {
            delete temp;
            temp = temp->next;
        }
        tail = NULL;
    }


    void Enqueue(T val)
    {
        if (head==NULL)
        {
            head = new Node<T>;
            head->next = NULL;
            head->data = val;
            tail = head;
        }
        else
        {
            Node<T>* temp = head;
            head = new Node<T>;
            head->next = NULL;
            temp->next = head;
            head->data = val;
        }

        length++;
    }


    void Dequeue()
    {
        length--;
        Node<T>* temp = tail;
        if (tail!=NULL)
        {
            if (head==tail)
                head = NULL;
            tail = tail->next;
            delete temp;
        }
    }


    T Extract()    //Similar to top in that it returns top values, and removes them from the queue but does not delete node
    {
        Node<T>* temp = tail;   ///T& return type changed to T see if any errors
        length--;
        T val = NULL;

        if (tail!=NULL)
        {
            if (head==tail)
                head = NULL;
            tail = tail->next;
            val = temp->data;
            return val;
        }
        return val;
    }


    void InsideCollision(bool pQue) //True if we are considering pQue
    {
        Node<T>* temp1 = tail;    //The unit that's ahead
        Node<T>* temp2 = NULL;    //The unit that's behind on screen but ahead in queue

        while (temp1!=NULL && (temp1->next)!=NULL)
        {
            temp2 = temp1->next;

            if (pQue)
            {
                if (temp2->data->GetLocation().GetX()+temp2->data->GetSprite()[0].w  >=  temp1->data->GetLocation().GetX() &&
                    (temp2->data->GetCharacterState()==0)
                    && (temp1->data->GetCharacterState()==1 || temp1->data->GetCharacterState()==3 || temp1->data->GetCharacterState()==0))
                {
                    temp2->data->SetCharacterState(3);  //set to idle //checks for idle melee units in waiting or idle/attacking ranged units.
                }

                else if (temp2->data->GetLocation().GetX() + (round(float(float(temp2->data->GetSpeed())
                    /float(temp1->data->GetSpeed()))))*temp1->data->GetSprite()[0].w <= temp1->data->
                         GetLocation().GetX() && (( temp2->data->GetCharacterState()==3)))
                {
                    temp2->data->SetCharacterState(0);  //keeps unit moving
                }
            }

            else    ///does the same but data->for enemy que.
            {
                if (temp2->data->GetLocation().GetX()-temp2->data->GetSprite()[0].w  <=  temp1->data->GetLocation().GetX() &&
                    (temp2->data->GetCharacterState()==0) &&
                    (temp1->data->GetCharacterState()==1 || temp1->data->GetCharacterState()==3 || temp1->data->GetCharacterState()==0))
                {
                    temp2->data->SetCharacterState(3);  //set to idle
                }

                else if (temp2->data->GetLocation().GetX() - (round(float(float(temp2->data->GetSpeed())/float(temp1->data->GetSpeed()))))*temp1->data->GetSprite()[0].w  >= temp1->data->GetLocation().GetX() && ((temp2->data->GetCharacterState()==3)))
                {
                    temp2->data->SetCharacterState(0);
                }
            }
            if (temp2->data->GetBoolMeleeUnit() && temp2->data->GetCharacterState()==3 && temp1->data->
                GetCharacterState()==2)    //moves melee fwd after ranged dies
            {
                temp2->data->SetCharacterState(0);
            }
            temp1 = temp2;
        }
    }


    void UpdateQueue()  //Updates each units location
    {
        Node<T>* temp = tail;

        while (temp!=NULL)
        {
            temp->data->UpdateLocation();
            temp = temp->next;
        }
    }


    void DrawQue(SDL_Renderer* gRenderer)
    {
        Node<T>* temp = tail;
        while (temp!=NULL && temp->data!=NULL)
        {
            temp->data->Draw(gRenderer);
            temp = temp->next;
        }
    }


    void Show()
    {
        Node<T>* temp = tail;

        while (temp!=NULL)
        {
            temp = tail->next;
        }
    }


    T Top()        //Returns earliest element added to Queue
    {
        if (tail!=NULL)
            return tail->data;

        T returnVal = NULL;
        return returnVal;
    }


    T Bottom()      //Returns latest element added to Queue
    {
        if (head!=NULL)
            return head->data;

        T returnVal = NULL;
        return returnVal;
    }


    int Length()
    {
        return this->length;
    }


    T& operator[](int index)
    {
        int i = 0;
        Node<T>* temp = tail;
        while(i<index && temp->next!=NULL)
        {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }


    void SaveGame()
    {
        ofstream file;
        file.open("Game.txt", fstream::app);

        file<<length<<endl;

        Node<T>* temp = tail;

        while (temp!=NULL)
        {
            temp->data->SaveGame();
            temp = temp->next;
        }
    }


    int LoadGame(int skip)
    {
        ifstream file;
        file.open("Game.txt");
        string line;
        int tempSkip=0; ///keeps track of everything withing the queue stored in file.
        WarriorFactory warFactory;
        for (int i=0; i<skip; i++)
        {
            getline(file,line);
        }

        skip++;
        getline(file,line);

        int temp = (atoi(line.c_str()));

        for (int i=0; i  < temp ; i++)  //runs for length of queue
        {
//            cout<<"i " <<i<<" " <<temp<<endl;
            skip = skip+2;
            getline(file,line); //accounts for W
//            cout<<line<<endl;
            getline(file,line); //gets warrior factory index
//            cout<<line<<endl;
            int unitIndex = atoi(line.c_str());
            this->Enqueue(warFactory.GetWarrior(unitIndex));
            tempSkip = ((*this)[i])->LoadGame(skip) - skip; //moves stuff onto that index of the queue
            for (int j=0; j<tempSkip; j++)
            {
                skip++;
                getline(file,line);
            }
        }

        file.close();

        return skip;
    }
};
