#include "MenuScreen.h"

MenuScreen::MenuScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height):Screen(gRenderer, gWindow, gScreenSurface, width, height)
{
    bgTexture = NULL;
    ButtonClickSound = NULL;
    AudioIconClickSound = NULL;
    ButtonTextureClips = new SDL_Rect[5];
    AudioIconTextureClips = new SDL_Rect[4];
    closingstatus = Quit;
    cout << "Menu Screen Constructor Called!" << endl;
}

MenuScreen::~MenuScreen()
{
    Mix_FreeChunk(ButtonClickSound);
    Mix_FreeChunk(AudioIconClickSound);
    ButtonClickSound = NULL;
    AudioIconClickSound = NULL;

    delete[] ButtonTextureClips;
    delete[] AudioIconTextureClips;
    ButtonTextureClips = NULL;
    AudioIconTextureClips = NULL;

    ButtonTextureSheet.free();
    AudioIconTextureSheet.free();

    cout << "Menu Screen Destructor Called!" << endl;
}

bool MenuScreen::LoadTextures()
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

    if( !AudioIconTextureSheet.loadFromFile( "graphics/MenuScreen/audioicons.png", mRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
    {
        AudioIconTextureClips[0].x = 0;
        AudioIconTextureClips[0].y = 0;
        AudioIconTextureClips[0].w = 512;
        AudioIconTextureClips[0].h = 512;

        AudioIconTextureClips[1].x = 512;
        AudioIconTextureClips[1].y = 0;
        AudioIconTextureClips[1].w = 512;
        AudioIconTextureClips[1].h = 512;

        AudioIconTextureClips[2].x = 0;
        AudioIconTextureClips[2].y = 512;
        AudioIconTextureClips[2].w = 512;
        AudioIconTextureClips[2].h = 512;

        AudioIconTextureClips[3].x = 512;
        AudioIconTextureClips[3].y = 512;
        AudioIconTextureClips[3].w = 512;
        AudioIconTextureClips[3].h = 512;

    }
	mBackgroundSurface = loadSurface("graphics/MenuScreen/MenuScreenBg.png");
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

    mFont = TTF_OpenFont( "graphics/GameScreen/LifeCraft_Font.ttf", 144 );
	if( mFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}

	if (!GameTitleText.loadFromRenderedText("HOSRUBA: The Land & The Tilism", {255, 246, 16, 255}, mFont, mRenderer))
	{
	    printf("Failed to renderer text!");
	    success = false;
	}


    if (success)
        cout << "Imagery Loaded!" << endl;

	return success;
}

bool MenuScreen::LoadAudio()
{
    bool success = true;
    ButtonClickSound = Mix_LoadWAV("audio/MenuScreen/switch6.wav");
    if( ButtonClickSound == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    AudioIconClickSound = Mix_LoadWAV("audio/MenuScreen/click5.wav");
    if( ButtonClickSound == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    bgMusic = Mix_LoadMUS("audio/MenuScreen/Dota2SoundTrack.mp3");
    if( ButtonClickSound == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    if (success)
        cout << "Audio Loaded!" << endl;
    return success;
}



void MenuScreen::ScreenHandler()
{

    bool quit = false;
    bgTexture = GenerateBackground();
    SDL_Event e;
    SDL_Rect charRect; charRect.x = 0; charRect.y = 0; charRect.w = 33; charRect.h = 41;
    int FontRowSize = 15;


    Button startbutton("STARTGAME", &FontTextureSheet, &ButtonTextureSheet, ButtonTextureClips, charRect, FontRowSize, 25, SCREEN_WIDTH/2-200, SCREEN_HEIGHT/2+75, 400, 60);
    Button loadbutton("LOADGAME", &FontTextureSheet, &ButtonTextureSheet, ButtonTextureClips, charRect, FontRowSize, 25, SCREEN_WIDTH/2-200, SCREEN_HEIGHT/2+75+90, 400, 60);
    Button quitbutton("QUIT",&FontTextureSheet, &ButtonTextureSheet, ButtonTextureClips, charRect, FontRowSize, 25, SCREEN_WIDTH/2-200, SCREEN_HEIGHT/2+75+90+90, 400, 60);

    AudioIcon volume(&AudioIconTextureSheet, AudioIconTextureClips, 1, 15, 700, 50, 50);
    AudioIcon music(&AudioIconTextureSheet, AudioIconTextureClips, 2, 75, 700, 50, 50);

    Mix_PlayMusic(bgMusic, 0);

    while (!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
                cout << "Quitting..." << endl;
            }

            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {

                int x, y;
                SDL_GetMouseState( &x, &y );
                //cout << "Coordinates: " << "(" << x << ", " << y << ")" << endl;

                volume.Animation(&e, x, y, AudioIconClickSound);
                music.Animation(&e, x, y, AudioIconClickSound);

                if (startbutton.Animation(&e, x, y, ButtonClickSound)){ Mix_HaltMusic(); quit = true; closingstatus = Start;  }
                if (loadbutton.Animation(&e, x, y, ButtonClickSound)) { Mix_HaltMusic(); quit = true; closingstatus = Load;  }
                if (quitbutton.Animation(&e, x, y, ButtonClickSound)) {   quit = true; closingstatus = Quit;  }
            }
        }
        SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(mRenderer);

        SDL_RenderCopy(mRenderer, bgTexture, NULL, NULL);
        startbutton.render(mRenderer);
        loadbutton.render(mRenderer);
        quitbutton.render(mRenderer);
        volume.render(mRenderer);
        music.render(mRenderer);
        GameTitleText.render(250, 200, mRenderer, NULL, 1000, 100);


        SDL_RenderPresent(mRenderer);


    }
   // SDL_Delay(1000);
}

int MenuScreen::getClosingStatus()
{
    return closingstatus;
}

