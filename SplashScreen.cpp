#include "Screen.h"
#include "SplashScreen.h"

SplashScreen::SplashScreen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height):Screen(gRenderer, gWindow, gScreenSurface, width, height)
{
    StoryText = new LTexture[10];
    cout << "SplashScreen Constructor Called!" << endl;
}

SplashScreen::~SplashScreen()
{
    if (StoryText != NULL)
        delete[] StoryText;
    StoryText = NULL;
    cout << "SplashScreen Destructor Called!" << endl;
}

bool SplashScreen::LoadTextures()
{
	//Loading success flag
	bool success = true;
	mBackgroundSurface = loadSurface("graphics/SplashScreen/SplashScreenBg.png");
    if (mScreenSurface == NULL)
    {
        printf("loadSurface: Could not load background screen!");
        success = false;
    }
    if (mBackgroundSurface == NULL)
    {
        printf("loadSurface: Could not load background screen!");
        success = false;
    }

    if( !FontTextureSheet.loadFromFile( "graphics/SplashScreen/Font(80x83).png", mRenderer) )
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

	StoryText[0].loadFromRenderedText("The Dread Wizard King Afrasiyaab and his army of monsters has", {209, 212, 232, 255}, mFont, mRenderer);
	StoryText[1].loadFromRenderedText("finally been challenged by a worthy contender. Ameer Hamza, ", {209, 212, 232, 255}, mFont, mRenderer);
    StoryText[2].loadFromRenderedText("leading an alliance of human and good Djinns from the far beyond", {209, 212, 232, 255}, mFont, mRenderer);
    StoryText[3].loadFromRenderedText("has entered Tilism-e-Hosruba, realm of Afrasiyab.", {209, 212, 232, 255}, mFont, mRenderer);
    StoryText[4].loadFromRenderedText("Here, Today, You shall put your mettle to the test.", {209, 212, 232, 255}, mFont, mRenderer);
    StoryText[5].loadFromRenderedText("A battle for the ages has begun. ", {209, 212, 232, 255}, mFont, mRenderer);
    StoryText[6].loadFromRenderedText("May the odds be ever in your favour... ", {209, 212, 232, 255}, mFont, mRenderer);



	if (success)
        cout << "Imagery loaded!" << endl;
	return success;
}

bool SplashScreen::LoadAudio()
{

}


void SplashScreen::ScreenHandler()
{
    bool quit = false;
    SDL_Event e;
    bgTexture = GenerateBackground();
    SDL_Rect charRect; charRect.x = 0; charRect.y = 0; charRect.w = 70; charRect.h = 77;
    int dot_x = 1410;

    Word loadingtext("LOADING", &FontTextureSheet, charRect, 1050, 700, 14, 55);
    Character dot(&FontTextureSheet, '.', charRect, 1410, 705,14);
    int pos = 1;


    Uint32 timeout = SDL_GetTicks() + 20000;
    while (!quit)
    {
        dot.setPosition(dot_x, 705 );
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
                cout << "Quitting SplashScreen..." << endl;
            }

        }

        SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(mRenderer);

        SDL_RenderCopy(mRenderer, bgTexture, NULL, NULL);
        loadingtext.render(mRenderer);
        dot.render(mRenderer);

        for (int i = 0; i < 7; i++)
        {
           StoryText[i].render(400, 150+(75*i), mRenderer, NULL, 800, 75);
        }

        SDL_RenderPresent(mRenderer);

        SDL_Delay(200);
        if (dot_x < 1465)   dot_x += 20;
        else    dot_x = 1410;

        if (SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
            quit = true;
    }
    cout << "Quitting SplashScreen..." << endl;
}
