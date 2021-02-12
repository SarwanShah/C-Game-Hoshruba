#include "GameScreen.h"
#include "IconSlot.h"
#include "GamePlay/GTexture.h"

//SDL_Renderer* Renderer = NULL;
Map* Map::instance = NULL;      /// SETS MAP TO NULL AT START


GameScreen::GameScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height):Screen(gRenderer, gWindow, gScreenSurface, width, height)
{
    ButtonTextureClips = new SDL_Rect[5];
    UIBarRect = new SDL_Rect[3];
    IconSlotRect = new SDL_Rect[9];
    UnitIconRect = new SDL_Rect[12];
    BuildingRect = new SDL_Rect[2];
    newGame = false;
    load = false;

    cout << "GameScreen Constructor Called!" << endl;
}

GameScreen::~GameScreen()
{
    MiscSpriteSheet.free();
    BuildingSpriteSheet.free();
    if (UIBarRect != NULL)
        delete[] UIBarRect;
    UIBarRect = NULL;
    if (IconSlotRect != NULL)
        delete[] IconSlotRect;
    IconSlotRect =  NULL;
    if (UnitIconRect != NULL)
        delete[] UnitIconRect;
    UnitIconRect = NULL;
    if (ButtonTextureClips != NULL)
        delete[] ButtonTextureClips;
    ButtonTextureClips = NULL;
    ButtonTextureSheet.free();
    cout << "GameScreen Destructor Called!" << endl;
}

bool GameScreen::LoadTextures()
{
	//Loading success flag
	bool success = true;

    if( !ButtonTextureSheet.loadFromFile( "graphics/MenuScreen/ButtonTexture.png", mRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
    {
        ButtonTextureClips[0].x = 2;
        ButtonTextureClips[0].y = 3;
        ButtonTextureClips[0].w = 296;
        ButtonTextureClips[0].h = 45;

        ButtonTextureClips[1].x = 2;
        ButtonTextureClips[1].y = 54;
        ButtonTextureClips[1].w = 296;
        ButtonTextureClips[1].h = 45;

        ButtonTextureClips[2].x = 2;
        ButtonTextureClips[2].y = 105;
        ButtonTextureClips[2].w = 296;
        ButtonTextureClips[2].h = 45;

        ButtonTextureClips[3].x = 2;
        ButtonTextureClips[3].y = 156;
        ButtonTextureClips[3].w = 296;
        ButtonTextureClips[3].h = 45;

        ButtonTextureClips[4].x = 2;
        ButtonTextureClips[4].y = 258;
        ButtonTextureClips[4].w = 296;
        ButtonTextureClips[4].h = 45;

    }

    ButtonClickSound = Mix_LoadWAV("audio/MenuScreen/switch6.wav");
    if( ButtonClickSound == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }


	mBackgroundSurface = loadSurface("graphics/GameScreen/Map.png");
    if (mBackgroundSurface == NULL)
    {
        printf("loadSurface: Could not load background screen!");
        success = false;
    }
    if( !FontTextureSheet.loadFromFile( "graphics/MenuScreen/fonts1.png", mRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}


	if (!MiscSpriteSheet.loadFromFile("graphics/GameScreen/Misc.png", mRenderer))
    {
        printf("loadSurface: Could not load Misc.png!");
        success = false;
    }
    else
    {
        MineRect.x = 210;
        MineRect.y = 105;
        MineRect.w = 102;
        MineRect.h = 90;
    }

    if (!UItextureSheet.loadFromFile("graphics/GameScreen/IconBox.png", mRenderer))
    {
       printf("loadSurface: Coud not load IconBox.png");
       success = false;
    }
    else
    {
        UIBarRect[0].x = 16;
        UIBarRect[0].y = 184;
        UIBarRect[0].w = 32;
        UIBarRect[0].h = 64;

        UIBarRect[1].x = 49;
        UIBarRect[1].y = 184;
        UIBarRect[1].w = 32;
        UIBarRect[1].h = 64;

        UIBarRect[2].x = 82;
        UIBarRect[2].y = 184;
        UIBarRect[2].w = 32;
        UIBarRect[2].h = 64;

        IconSlotRect[0].x = 16;
        IconSlotRect[0].y = 288;
        IconSlotRect[0].w = 54;
        IconSlotRect[0].h = 40;

        IconSlotRect[1].x = 71;
        IconSlotRect[1].y = 288;
        IconSlotRect[1].w = 44;
        IconSlotRect[1].h = 40;

        IconSlotRect[2].x = 116;
        IconSlotRect[2].y = 288;
        IconSlotRect[2].w = 58;
        IconSlotRect[2].h = 40;

        IconSlotRect[3].x = 16;
        IconSlotRect[3].y = 329;
        IconSlotRect[3].w = 54;
        IconSlotRect[3].h = 40;

        IconSlotRect[4].x = 71;
        IconSlotRect[4].y = 329;
        IconSlotRect[4].w = 44;
        IconSlotRect[4].h = 40;

        IconSlotRect[5].x = 116;
        IconSlotRect[5].y = 329;
        IconSlotRect[5].w = 58;
        IconSlotRect[5].h = 40;

        IconSlotRect[6].x = 16;
        IconSlotRect[6].y = 370;
        IconSlotRect[6].w = 54;
        IconSlotRect[6].h = 40;

        IconSlotRect[7].x = 71;
        IconSlotRect[7].y = 370;
        IconSlotRect[7].w = 44;
        IconSlotRect[7].h = 40;

        IconSlotRect[8].x = 116;
        IconSlotRect[8].y = 370;
        IconSlotRect[8].w = 58;
        IconSlotRect[8].h = 40;

    }

    if (!UnitIconSheet.loadFromFile("graphics/GameScreen/UnitIcons.png", mRenderer))
    {
        printf("loadSurface: Could not load UnitIcons.png");
        success = false;
    }
    else
    {
        UnitIconRect[0].x = 21;
        UnitIconRect[0].y = 109;
        UnitIconRect[0].w = 46;
        UnitIconRect[0].h = 44;

        UnitIconRect[1].x = 115;
        UnitIconRect[1].y = 103;
        UnitIconRect[1].w = 36;
        UnitIconRect[1].h = 54;

        UnitIconRect[2].x = 214;
        UnitIconRect[2].y = 110;
        UnitIconRect[2].w = 34;
        UnitIconRect[2].h = 48;

        UnitIconRect[3].x = 290;
        UnitIconRect[3].y = 99;
        UnitIconRect[3].w = 34;
        UnitIconRect[3].h = 48;

        UnitIconRect[4].x = 387;
        UnitIconRect[4].y = 27;
        UnitIconRect[4].w = 24;
        UnitIconRect[4].h = 37;

        UnitIconRect[5].x = 457;
        UnitIconRect[5].y = 109;
        UnitIconRect[5].w = 36;
        UnitIconRect[5].h = 44;

        UnitIconRect[6].x = 30;
        UnitIconRect[6].y = 22;
        UnitIconRect[6].w = 36;
        UnitIconRect[6].h = 46;

        UnitIconRect[7].x = 120;
        UnitIconRect[7].y = 21;
        UnitIconRect[7].w = 38;
        UnitIconRect[7].h = 54;

        UnitIconRect[8].x = 214;
        UnitIconRect[8].y = 26;
        UnitIconRect[8].w = 40;
        UnitIconRect[8].h = 38;

        UnitIconRect[9].x = 294;
        UnitIconRect[9].y = 20;
        UnitIconRect[9].w = 48;
        UnitIconRect[9].h = 45;

        UnitIconRect[10].x = 382;
        UnitIconRect[10].y = 110;
        UnitIconRect[10].w = 30;
        UnitIconRect[10].h = 36;

        UnitIconRect[11].x = 451;
        UnitIconRect[11].y = 24;
        UnitIconRect[11].w = 49;
        UnitIconRect[11].h = 48;
    }

	if (!BuildingSpriteSheet.loadFromFile("graphics/GameScreen/Buildings.png", mRenderer))
    {
        printf("loadSurface: Could not load Buildings.png!");
        success = false;
    }
    else
    {
        BuildingRect[0].x = 9;
        BuildingRect[0].y = 21;
        BuildingRect[0].w = 196;
        BuildingRect[0].h = 79;

        BuildingRect[1].x = 436;
        BuildingRect[1].y = 23;
        BuildingRect[1].w = 193;
        BuildingRect[1].h = 80;

    }

    mFont = TTF_OpenFont( "graphics/GameScreen/LifeCraft_Font.ttf", 28 );
	if( mFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}

	PauseTextTexture.loadFromRenderedText("PAUSED!", {255, 122, 0, 255}, mFont, mRenderer);


    return success;
}

bool GameScreen::LoadAudio()
{

}




void GameScreen::ScreenHandler()

{
    //Renderer = SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED );
    bool quit = false;
    SDL_Event e;
    bgTexture = GenerateBackground();

    OnScreenTexture MineA(&MiscSpriteSheet, &MineRect, -4, -40, 75, 75);
    OnScreenTexture MineB(&MiscSpriteSheet, &MineRect, 58, -40, 75, 75);
    OnScreenTexture MineC(&MiscSpriteSheet, &MineRect, 120, -40, 75, 75);
    OnScreenTexture MineD(&MiscSpriteSheet, &MineRect, 1491, -40, 75, 75);
    OnScreenTexture MineE(&MiscSpriteSheet, &MineRect, 1416, -40, 75, 75);
    OnScreenTexture MineF(&MiscSpriteSheet, &MineRect, 1341, -40, 75, 75);
    OnScreenTexture BuildingA(&BuildingSpriteSheet, &BuildingRect[0], -10, 165, 200, 70);
    OnScreenTexture BuildingB(&BuildingSpriteSheet, &BuildingRect[1], 1352, 165, 200, 70);
    SDL_Rect charRect; charRect.x = 0; charRect.y = 0; charRect.w = 33; charRect.h = 41;
    int FontRowSize = 15;

    Button resumebutton("RESUME", &FontTextureSheet, &ButtonTextureSheet, ButtonTextureClips, charRect, FontRowSize, 25, SCREEN_WIDTH/2-200, SCREEN_HEIGHT/4+75, 400, 60);
    Button savebutton("SAVE", &FontTextureSheet, &ButtonTextureSheet, ButtonTextureClips, charRect, FontRowSize, 25, SCREEN_WIDTH/2-200, SCREEN_HEIGHT/4+75+90, 400, 60);
    Button quitbutton("QUIT",&FontTextureSheet, &ButtonTextureSheet, ButtonTextureClips, charRect, FontRowSize, 25, SCREEN_WIDTH/2-200, SCREEN_HEIGHT/4+75+90+90, 400, 60);



    UserInterface UI(&UItextureSheet, &UnitIconSheet, UIBarRect, IconSlotRect, UnitIconRect, mFont, mRenderer);

//    srand(time(NULL));

    Map* zone = Map::GetInstance(); //Map with 5 lanes created, can be accessed by simply Map::GetInstance->GetField or zone->GetField

    GamePlay* gameRun = new GamePlay(zone, mRenderer);
    gameRun->SetDimensions(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Main loop flag
    bool gamePlay = false;
    bool loadGame = false;
    bool saveGame = false;
    bool pauseGame = false;

    bool initializeGuard = true;

    int moneyCounter = 0;

    //Current animation frame
    int frameR = 50;
    int frameL = 50;

    bool unitCreated1 = false;  //player1
    bool unitCreated2 = false;  //player2

    int unit1Index = 8; //Points at unit that the player will produce upon pressing spacebar. changed with left and right arrowkeys
    int unit2Index = 1; //Considers Player 2 or L.H.S player
//            bool pressSpace = false;
//            bool pressEnter = false;


    bool playerMiner=true;
    bool enemyMiner=true;

    int minerCount = 0; //initializes 3 minors in the start

    bool playerSabotage = false;
    bool enemySabotage = false;

    int movePlayerGuard = 0;
    int moveEnemyGuard = 0;

    bool flagresume = false;
    bool flagsave = false;



    while( !quit )
    {
            //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            //User requests quit
            UI.EventHandler(&e, x, y);

            if( e.type == SDL_QUIT )
            {
                    quit = true;
            }

            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {

            if (resumebutton.Animation(&e, x, y, ButtonClickSound)){ flagresume = true; }
            if (savebutton.Animation(&e, x, y, ButtonClickSound)) { flagsave = true;  }
            if (quitbutton.Animation(&e, x, y, ButtonClickSound)) { quit = true; }
            }


            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym==  SDLK_UP)
                {
//                            cout<<"UP arrow key"<<endl;
                    if (gameRun->GetLane1()>2)
                        gameRun->SetLane1(gameRun->GetLane1()-1);
                }
                else if (e.key.keysym.sym == SDLK_DOWN)
                {
//                            cout<<"DOWN arrow key"<<endl;

                    if (gameRun->GetLane1()<5)
                        gameRun->SetLane1(gameRun->GetLane1()+1);
                }
            /// ///// / // / / // // / / /            //////////////
                if (e.key.keysym.sym == SDLK_w)
                {
                    if (gameRun->GetLane2()>2)
                        gameRun->SetLane2(gameRun->GetLane2()-1);
                }
                else if (e.key.keysym.sym == SDLK_s)
                {
                    if (gameRun->GetLane2()<5)
                        gameRun->SetLane2(gameRun->GetLane2()+1);
                }

            }

            if (e.type==SDL_KEYUP)
            {
                if (e.key.keysym.sym == SDLK_SPACE && frameL>50)
                {
                    frameL = 0;
                    unitCreated2 = true;
                }
                if (e.key.keysym.sym == SDLK_RSHIFT && frameR>50)
                {
                    frameR = 0;
                    unitCreated1 = true;
                }

                if (e.key.keysym.sym == SDLK_LEFT)
                {
                    if (unit1Index>8)
                        unit1Index--;
//                            cout<<"Left Pressed"<<" , "<<unit1Index<<endl;

                }

                if (e.key.keysym.sym == SDLK_RIGHT)
                {
                    if (unit1Index<11)
                        unit1Index++;
//                            cout<<"Right pressed"<<" , "<<unit1Index<<endl;
                }

                if (e.key.keysym.sym == SDLK_a)
                {
                    if (unit2Index>1)
                        unit2Index--;
//                            cout<<"A pressed"<<" , "<<unit2Index<<endl;

                }

                if (e.key.keysym.sym == SDLK_d)
                {
                    if (unit2Index<4)
                        unit2Index++;
//                            cout<<"D pressed"<<" , "<<unit2Index<<endl;
                }

                if (e.key.keysym.sym == SDLK_q)
                {
                    if ((zone->GetField()[8])[0].Length()<3)
                    {
//                                unit2Index = 5;
                        playerMiner = true;
                    }

                }

                if (e.key.keysym.sym == SDLK_SLASH)
                {
                    if ((zone->GetField()[8])[1].Length()<3)
                    {
//                                unit1Index = 10;
                        enemyMiner = true;
                    }

                }

                if (e.key.keysym.sym == SDLK_e)
                {
                    playerSabotage = true;
                }

                if (e.key.keysym.sym == SDLK_PERIOD)
                {
                    enemySabotage = true;
                }
//
//                if (e.key.keysym.sym == SDLK_o) //saves game when O is pressed
//                {
//                    cout<<"GOES IN HERE"<<endl;
//                    saveGame = true;
//                }



                if (e.key.keysym.sym == SDLK_p)
                {
                    if (gamePlay == false && pauseGame == true)
                    {
                        pauseGame = false;
                        gamePlay = true;
                    }
                    else if (gamePlay ==true)
                    {
                        gamePlay = false;
                        pauseGame = true;
                    }
                }
            }

        }

        if (newGame)
        {
            if (pauseGame==false)
            {
                gamePlay = true;
                newGame = false;
            }
        }

        if (load)
        {
            loadGame = true;
            load = false;
        }



    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(mRenderer);



    SDL_RenderCopy(mRenderer, bgTexture, NULL, NULL);
    UI.render(mRenderer);


    MineA.render(mRenderer);
    MineB.render(mRenderer);
    MineC.render(mRenderer);

    MineD.render(mRenderer);
    MineE.render(mRenderer);
    MineF.render(mRenderer);

    BuildingA.render(mRenderer);
    BuildingB.render(mRenderer);

    if (pauseGame)
    {
        PauseTextTexture.render(570, 150, mRenderer, NULL, 400, 100);
        resumebutton.render(mRenderer);
        savebutton.render(mRenderer);
        quitbutton.render(mRenderer);
    }

    if (flagsave) //saves game when O is pressed
    {
        cout<<"GAME IS SAVED"<<endl;
        flagsave = false;
        saveGame = true;
    }



    if (flagresume)
    {
        if (gamePlay == false && pauseGame == true)
        {
            flagresume = false;
            pauseGame = false;
            gamePlay = true;
        }
    }

    if (saveGame)
    {

        saveGame = false;

        ofstream file;
        file.open("Game.txt");

        file<<moneyCounter<<endl;

        file<<frameR<<endl;
        file<<frameL<<endl;
        file<<unitCreated1<<endl;
        file<<unitCreated2<<endl;

        file<<unit1Index<<endl;
        file<<unit2Index<<endl;

        file<<playerMiner<<endl;
        file<<enemyMiner<<endl;
        file<<minerCount<<endl;
        file<<playerSabotage<<endl;
        file<<enemySabotage<<endl;

        file<<movePlayerGuard<<endl;
        file<<moveEnemyGuard<<endl;

        gameRun->SaveGamePlay();

        file.close();
    }

    if (gamePlay)
    {
            if (initializeGuard)
            {
                initializeGuard = false;
                gameRun->InitializeGuard();

            }

            if (unitCreated2 && gameRun->GetPlayer()->CheckAffordability(unit2Index))   //L.H.S player
            {
                        cout<<"created"<<endl;

                unitCreated2=false;
                gameRun->LaunchPlayerUnit(unit2Index);
            }
            else
            {
                unitCreated2=false; //when player can't afford unit
            }

            if (unitCreated1 && gameRun->GetEnemy()->CheckAffordability(unit1Index))       //Player on R.H.S , player 1
            {
                unitCreated1=false;
                gameRun->LaunchEnemyUnit(unit1Index);

            }
            else
            {
                unitCreated1=false;
            }

           if (playerMiner && (gameRun->GetPlayer()->CheckAffordability(5) || minerCount<=2))
           {
                playerMiner = false;
                gameRun->LaunchPlayerMiner();
           }
           else
           {
               playerMiner=false;
           }

            if (enemyMiner && (gameRun->GetEnemy()->CheckAffordability(12) || minerCount<=2))
            {
                enemyMiner = false;
                gameRun->LaunchEnemyMiner();
            }
            else
            {
                enemyMiner = false;
            }


            if (playerSabotage && gameRun->GetPlayer()->CheckAffordability(6))///DELETE COMMENT
                //Correct error that units automatically generated after existing units
                //blow up if key pressed like 4 time for example because they are in queue. or maybe don't?
            {
                playerSabotage = gameRun->GeneratPlayerSabotage(playerSabotage);

            }
            else
            {
                playerSabotage = false;
            }

            if (enemySabotage && gameRun->GetEnemy()->CheckAffordability(13))
            {
                enemySabotage = gameRun->GenerateEnemySabotage(enemySabotage);
            }
            else
            {
                enemySabotage = false;
            }

            int randomChance = rand()%100;

            if (randomChance<2 && movePlayerGuard>=200 )   ///Moves player guard randomly
            {
                movePlayerGuard = 0;
                gameRun->RandomizePlayerGuard();
            }

            randomChance = rand()%100;

            if (randomChance<2 && moveEnemyGuard>=200)
            {
                moveEnemyGuard = 0;
                gameRun->RandomizeEnemyGuard();
            }


            if (minerCount<2)
            {
                playerMiner = true;
                enemyMiner = true;
                minerCount++;
            }
            else if (minerCount==2)
            {
                minerCount++;
                playerMiner = false;
                enemyMiner = false;

            }


            if (moneyCounter>=200)
            {
                moneyCounter = 0;
                gameRun->GetPlayer()->IncrementMoney((zone->GetField()[8])[0].Length());
                gameRun->GetEnemy()->IncrementMoney((zone->GetField()[8])[1].Length());

//
//                cout<<"player money: "<<gameRun->GetPlayer()->GetMoney()<<endl;
//                cout<<"enemy money: "<<gameRun->GetEnemy()->GetMoney()<<endl;
//
//                cout<<"player health: "<<gameRun->GetPlayer()->GetHealth()<<endl;
//                cout<<"enemy health: "<<gameRun->GetEnemy()->GetHealth()<<endl;
//
//                cout<<"player score: "<<gameRun->GetPlayer()->GetScore()<<endl;
//                cout<<"enemy score: "<<gameRun->GetEnemy()->GetScore()<<endl<<endl;

            }
            UI.P1_UpdateHealth(gameRun->GetPlayer()->GetHealth());
            UI.P2_UpdateHealth(gameRun->GetEnemy()->GetHealth());
            UI.P1_UpdateMoney(gameRun->GetPlayer()->GetMoney());
            UI.P2_UpdateMoney(gameRun->GetEnemy()->GetMoney());
            UI.P1_UpdateScore(gameRun->GetPlayer()->GetScore());
            UI.P2_UpdateScore(gameRun->GetEnemy()->GetScore());
            if (gameRun->GetPlayer()->GetHealth()<=0 || gameRun->GetEnemy()->GetHealth() <=0)
            {
                break;
            }
            gameRun->UpdateGamePlay();

            ++movePlayerGuard;
            ++moveEnemyGuard;
            ++frameR;
            ++frameL;
            ++moneyCounter;
            //Update screen


    }



    if (loadGame && !gamePlay && !pauseGame)
    {
        string line;

        ifstream file;
        file.open("Game.txt",fstream::app);
        if (!file)
        {
            cout<<"Unable to Open File"<<endl;
        }
        else
        {
            getline(file, line);
            moneyCounter = atoi(line.c_str());
//                        cout<<moneyCounter<<endl;
            getline(file, line);
            frameR  = atoi(line.c_str());
//                        cout<<frameR<<endl;
            getline(file, line);
            frameL = atoi(line.c_str());
//                        cout<<frameL<<endl;
            getline(file, line);
            unitCreated1 = gameRun->Boolean(line);
//                        cout<<unitCreated1<<endl;
            getline(file, line);
            unitCreated2 = gameRun->Boolean(line);
//                        cout<<unitCreated2<<endl;

            getline(file, line);
            unit1Index = atoi(line.c_str());
//                        cout<<unit1Index<<endl;
            getline(file, line);
            unit2Index = atoi(line.c_str());
//                        cout<<unit2Index<<endl;

            getline(file, line);
            playerMiner = gameRun->Boolean(line);
//                        cout<<playerMiner<<endl;
            getline(file, line);
            enemyMiner = gameRun->Boolean(line);
//                        cout<<enemyMiner<<endl;
            getline(file, line);
            minerCount = atoi(line.c_str());
//                        cout<<minerCount<<endl;
            getline(file, line);
            playerSabotage = gameRun->Boolean(line);
//                        cout<<playerSabotage<<endl;
            getline(file, line);
            enemySabotage = gameRun->Boolean(line);
//                        cout<<enemySabotage<<endl;

            getline(file, line);
            movePlayerGuard = atoi(line.c_str());
//                        cout<<movePlayerGuard<<endl;
            getline(file, line);
            moveEnemyGuard = atoi(line.c_str());
//                        cout<<moveEnemyGuard<<endl;

            gameRun->LoadGamePlay(mRenderer);


        }

        file.close();

        gamePlay = true;
        quit = false;
        saveGame = false;
        loadGame = false;
        pauseGame = false;
        initializeGuard = false;
    }

    if (mRenderer == NULL)
        cout << "NULL" << endl;

    //if (Renderer==NULL)
     //   cout << " ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"<<endl;
    gameRun->DrawGamePlay(mRenderer);


    //SDL_RenderPresent(Renderer);
    SDL_RenderPresent(mRenderer);
    }

    if (gameRun!=NULL)
    {
        delete gameRun;
        gameRun = NULL;
    }

}


void GameScreen::setInitialState(int i)
{
   if (i == 0)
        newGame = true;
   else
        load = true;
}

