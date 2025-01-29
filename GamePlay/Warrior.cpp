#include "Warrior.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <time.h>

Warrior::Warrior()
{
    hitFrameCount=0;
    hitFrameMax=1;
    frame = 0;
    projectile = NULL;
    fireProjectile = true;
    currentClip = NULL;

    width = height = 0;

    state = 0;

    sabotage = false;

    playerUnit=false;
    meleeUnit=false;

    walkingFrames=-1;
    fightingFrames=-1;
    idleFrames=-1;
    idleFrameAddendum=-1;
    dyingFrames=-1;

    fireProjectileCount=-1;
    speed=-1;

    sabotage = false;

    health=-1;
    damage=-1;
    hitchance=-1;

    projectileDelay=-1;

    SCREEN_HEIGHT=-1;
    SCREEN_WIDTH=-1;

    gRenderer = NULL;
}


void Warrior::SetWidth(int w)
{
    width = w;
}


void Warrior::UpdateLocation()
{
    if (state==0)
    {
        frame++;
        if (frame/walkingFrames>=walkingFrames)
        {
            frame = 0;
        }

        int pt = location.GetX();

        if (playerUnit)
            pt = pt + speed;
        else
            pt = pt - speed;

//        if (damage == 7 && !playerUnit)
//            cout<<location.GetX()<<endl;
        location.SetX(pt);
        UpdateClip(frame/walkingFrames);
    }

    else if (state==1)
    {
        frame++;
        hitFrameCount++;
        if (frame/fightingFrames >=fightingFrames)
        {
            frame = 0;

            if (meleeUnit == false)
            {
                state=3;
            }
        }

        if (hitFrameCount == hitFrameMax)
        {
            hitFrameCount = 0;
            UpdateClip(frame/fightingFrames + walkingFrames);

            if (meleeUnit==false)
            {
                if (frame/fightingFrames + walkingFrames == fireProjectileCount)
                {
                    fireProjectile = true;
                }
            }
        }
    }

    else if (state==2)
    {
        frame++;
        if (frame/dyingFrames >= dyingFrames)
        {
            state=4;
        }
        if (state!=4)
            UpdateClip(frame/dyingFrames + walkingFrames + fightingFrames);
    }

    else if (state==3)
    {
        frame++;
        int chance = rand()%100;
        if ( chance<10)
        {
            if (frame/idleFrames>=idleFrames)
            {
                frame = 0;
            }
            UpdateClip(frame/idleFrames  +  idleFrameAddendum);
        }
    }
}


Warrior::~Warrior()
{
    spriteSheet.free();
}


void Warrior::SetFrame(int val)
{

    frame = val;
}


int Warrior::GetFrame()
{
    return frame;
}


void Warrior::SetSpeed(int val)
{
    speed = val;
}


void Warrior::SetHealth(int val)
{
    health = val;
}


void Warrior::SetDamage(int val)
{
    damage = val;
}


void Warrior::SetHitChance(int val)
{
    hitchance = val;
}


int Warrior::GetSpeed()
{
    return speed;
}


int Warrior::GetHealth()
{
    return health;
}


int Warrior::GetDamage()
{
    return damage;
}


int Warrior::GetHitChance()
{
    return hitchance;
}


void Warrior::SetSpriteSheet(string val)
{
    if (gRenderer==NULL)
        cout<<"OOPS"<<endl;
    else
        spriteSheet.loadFromFile( val, gRenderer );
}


GTexture& Warrior::GetSpriteSheet()
{
    return spriteSheet;
}


void Warrior::SetSprite(SDL_Rect* temp)
{
    for (int i=0; i<50; i++)
    {
        sprite[i] = temp[i];
    }
}


SDL_Rect* Warrior::GetSprite()
{
    return sprite;
}


void Warrior::UpdateClip(int temp)
{
    currentClip = &sprite[temp];
}


Point& Warrior::GetLocation()
{
    return location;
}


void Warrior::SetScreenSize(int x,int y)
{
    SCREEN_HEIGHT = x;
    SCREEN_WIDTH = y;
}


int  Warrior::GetScreenWidth()
{
    return SCREEN_WIDTH;
}


int  Warrior::GetScreenHeight()
{
    return SCREEN_HEIGHT;
}


SDL_Rect* Warrior::GetClip()
{
    return currentClip;
}


void Warrior::SetCharacterState(int t)
{
    state = t;
}


int Warrior::GetCharacterState()
{
    return state;
}


void Warrior::SetProjectile(Warrior* object)
{
    projectile = object;
}


Warrior* Warrior::GetProjectile()
{
    return projectile;
}


void Warrior::SetX(int x)
{
    location.SetX(x);
}


void Warrior::SetProjectileDelay(int p)
{
    projectileDelay = p;
}


int Warrior::GetProjectileDelay()
{
    return projectileDelay;
}


void Warrior::SetY(int y )
{
    location.SetY(y);
}


Warrior* Warrior::FireProjectile()
{
    return projectile;  //returns null for most objects other than archer
}


void Warrior::SetProjectileBool(bool temp)
{
    fireProjectile = temp;
}


bool Warrior::GetProjectileBool()
{
    return fireProjectile;
}


void Warrior::SetLocation(int lane)
{
    if (playerUnit)

        GetLocation().SetX(0-GetSprite()[0].w);
    else
        GetLocation().SetX(GetScreenWidth());


//        cout<<playerUnit<<"   "<< GetLocation().GetX()<<endl;
    GetLocation().SetY(GetScreenHeight()/10-GetSprite()[0].h/2+lane*55+200);
}


bool Warrior::GetSabotage()
{
    return sabotage;
}


void Warrior::SetSabotage(bool temp)
{
    sabotage = temp;
}


void Warrior::Draw(SDL_Renderer* gRenderer)
{
    if (GetClip()!=NULL)
    {
        if (playerUnit)
        {
            (GetSpriteSheet()).render(GetLocation().GetX(), (GetLocation().GetY() - (GetClip()->h)/10), gRenderer, GetClip() );
        }
        else
        {
            (GetSpriteSheet()).render(GetLocation().GetX(), (GetLocation().GetY() - (GetClip()->h)/10), gRenderer, GetClip(), SDL_FLIP_HORIZONTAL );
        }
    }
}


void Warrior::SaveGame()
{
    ofstream file;
    file.open("Game.txt", fstream::app);

    file<<"W"<<endl;

    file<<factoryIndex<<endl;

    file<<location.GetX()<<endl;
    file<<location.GetY()<<endl;

    file<<hitFrameCount<<endl;
    file<<hitFrameMax<<endl;
    file<<frame<<endl;
    file<<fireProjectile<<endl;

    file<<state<<endl;

    file<<width<<endl;
    file<<height<<endl;

    file<<fireProjectileCount<<endl;
    file<<speed<<endl;

    file<<sabotage<<endl;

    file<<health<<endl;
    file<<damage<<endl;
    file<<hitchance<<endl;

    file<<projectileDelay<<endl;

    file<<SCREEN_HEIGHT<<endl;
    file<<SCREEN_WIDTH<<endl;

    file.close();
}


int Warrior::LoadGame(int skip)
{
    ifstream file;
    file.open("Game.txt");
    string line;

    for (int i=0; i<skip; i++)
    {
        getline(file,line);
    }

    getline(file,line);
    location.SetX(atoi(line.c_str()));
    getline(file,line);
    location.SetY(atoi(line.c_str()));

    getline(file,line);
    hitFrameCount = atoi(line.c_str());
    getline(file,line);
    hitFrameMax = atoi(line.c_str());
    getline(file,line);
    frame = atoi(line.c_str());
    getline(file,line);
    fireProjectile<<Boolean(line);

    getline(file,line);
    state = atoi(line.c_str());

    getline(file,line);
    width = atoi(line.c_str());
    getline(file,line);
    height = atoi(line.c_str());

    getline(file,line);
    fireProjectileCount = atoi(line.c_str());
    getline(file,line);
    speed = atoi(line.c_str());

    getline(file,line);
    sabotage<<Boolean(line);

    getline(file,line);
    health = atoi(line.c_str());
    getline(file,line);
    damage = atoi(line.c_str());
    getline(file,line);
    hitchance = atoi(line.c_str());

    getline(file,line);
    projectileDelay = atoi(line.c_str());

    getline(file,line);
    SCREEN_HEIGHT = atoi(line.c_str());
    getline(file,line);
    SCREEN_WIDTH = atoi(line.c_str());

    skip = skip + 18;

    file.close();

    return skip;
}


void Warrior::SetBoolPlayerUnit(bool boolean)
{
    playerUnit = boolean;
}


bool Warrior::Boolean(string val)
{
    if (val=="0")
        return false;

    if (val=="1")
        return true;

    return false;
}


int Warrior::GetWidth()
{
    return width;
}


int Warrior::GetHeight()
{
    return height;
}


void Warrior::SetBoolMeleeUnit(bool meleeUnit)
{
    this->meleeUnit = meleeUnit;
}


bool Warrior::GetBoolMeleeUnit()
{
    return meleeUnit;
}

void Warrior::SetRenderer(SDL_Renderer* gRenderer)
{
    this->gRenderer = gRenderer;

    if (this->gRenderer==NULL)
    {
        cout<<"IDIOT"<<endl;
    }
}
