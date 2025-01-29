#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GTexture.h"
#include "Node.h"
#include "Point.h"
#include <time.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class Warrior
{

protected:
    SDL_Renderer* gRenderer;
    int health;
    int damage;
    int hitchance;

    int factoryIndex;   //index of unit in warrior factory

    Warrior* projectile;
    bool fireProjectile;
    int frame;          //used to assign clip number to the objects

    Point location;     //Keeps track of warrior location on field

    int state;          //0 = walking, 1 = fighting, 2 = dying , 3 = idle, 4 = dead
                        //(Can use ENUM for better functionality too)

    SDL_Rect sprite[25];     //Stores sprites

    bool playerUnit;    //true if unit belongs to L.H.S player
    bool meleeUnit;     //true if unit is melee

    int walkingFrames;
    int fightingFrames;
    int idleFrames;             //frame count when unit is idle
    int idleFrameAddendum;      //constant value added to frame count when setting unit on idle
    int dyingFrames;            //frame count as unit is dying

    int hitFrameCount;      //delay in fighting motions
    int hitFrameMax;        //maximum counter for hitFrameCount

    int fireProjectileCount; //Maintains count after which ranged unit launches projectile
    int speed;

    bool sabotage; //true when sabotage blows up a miner.

    int width;
    int height;

    int projectileDelay;    //delay in projectile movement on screen

    int SCREEN_HEIGHT;
    int SCREEN_WIDTH;

private:

    GTexture spriteSheet;

    SDL_Rect* currentClip;

public:

    Warrior();
    ~Warrior();

    virtual void SetLocation(int);        //Sets initial location
    virtual void UpdateLocation();        //Updates location as game progresses and warrior moves
    virtual void Draw(SDL_Renderer*);
    virtual void EnterSprite()=0;         //assigns sprites to unit
    virtual Warrior* FireProjectile();    //returns projectile if unit is firing

    void SaveGame();
    int LoadGame(int);

    void SetX(int);
    void SetY(int);
    void SetSpeed(int);
    void SetHealth(int);
    void SetDamage(int);
    void SetHitChance(int);
    void SetFrame(int);
    void SetProjectile(Warrior*);
    void SetProjectileDelay(int);
    void SetSabotage(bool);
    void SetProjectileBool(bool);
    void SetSpriteSheet(string);
    void SetSprite(SDL_Rect*);
    void SetCharacterState(int);        //Sets character state i.e. walking/fighting/idle/dying
    void SetBoolPlayerUnit(bool);
    void SetScreenSize(int,int);
    void SetBoolMeleeUnit(bool);

    Warrior* GetProjectile();
    int GetFrame();
    int GetSpeed();
    int GetHealth();
    int GetDamage();
    int GetHitChance();
    int GetWidth();
    int GetHeight();
    Point& GetPoint();
    int GetProjectileDelay();
    bool GetSabotage();
    bool GetProjectileBool();
    Point& GetLocation();
    GTexture& GetSpriteSheet();
    SDL_Rect* GetSprite();
    SDL_Rect* GetClip();
    int GetScreenWidth();
    int GetScreenHeight();
    int GetCharacterState();
    bool GetBoolMeleeUnit();
    void SetRenderer(SDL_Renderer* gRenderer);
    void SetWidth(int);



    void UpdateClip(int);       //Updates sprite clip depending on frame

    bool Boolean(string);       //converts string to bool
};
