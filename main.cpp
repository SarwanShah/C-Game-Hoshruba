
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Screen.h"
#include "iostream"
#include "Buttons.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Screen.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "SplashScreen.h"
#include "SDL_ttf.h"
#include "GamePlay/Map.h"
#include "QuitScreen.h"

using namespace std;

const int SCREEN_HEIGHT = 820;
const int SCREEN_WIDTH = 1536;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Surface* gScreenSurface = NULL;



bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }

    gWindow = SDL_CreateWindow("HOSRUBA: The Land & The Tilism", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    }
    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( gRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    }

    else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );


		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
            success = false;
        }
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100,  AUDIO_F32SYS, 4, 4096 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
        //Initialize SDL_ttf
        if( TTF_Init() == -1 )
        {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
        }

    }
	return success;
}

void close()
{

	//Quit SDL subsystems
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	cout << "\n\n\n****************************************************" << endl;
	cout << "****************** SDL CLOSED! *********************" << endl;
	cout << "****************************************************" << endl;
}



int main( int argc, char* args[] )
{
	//Start up SDL and create window
    srand(time(NULL));
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
    {
        bool quit = false;
        while (!quit)
        {
            SplashScreen sScreen(gRenderer, gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT);
            MenuScreen mScreen(gRenderer, gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT);
            GameScreen gScreen(gRenderer, gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT);
            QuitScreen qScreen(gRenderer, gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT);

            if (sScreen.LoadTextures())
                if (sScreen.LoadAudio())
                    sScreen.ScreenHandler();
                else
                    quit = true;
            else
                quit = true;

            if (mScreen.LoadTextures())
                if (mScreen.LoadAudio())
                    mScreen.ScreenHandler();
                else
                    quit = true;
            else
                quit = true;


            if (mScreen.getClosingStatus() == 0)
            {
                gScreen.setInitialState(0);
                if (gScreen.LoadTextures())
                    if (gScreen.LoadAudio())
                        gScreen.ScreenHandler();
                    else
                        quit = true;
                else
                    quit = true;
            }
            else if (mScreen.getClosingStatus() == 1)
            {
                gScreen.setInitialState(1);
                if (gScreen.LoadTextures())
                    if (gScreen.LoadAudio())
                        gScreen.ScreenHandler();
                    else
                        quit = true;
                else
                    quit = true;
            }
            else
            {
                quit = true;
                break;
            }

            if (qScreen.LoadTextures())
                if (qScreen.LoadAudio())
                    qScreen.ScreenHandler();
                else
                    quit = true;
            else
                quit = true;

            if (qScreen.getClosingStatus() == 1)
            {
               quit = true;
            }
            else
            {
                sScreen.~Screen();
                mScreen.~Screen();
                gScreen.~Screen();
                qScreen.~Screen();
            }




        }


	}


	//Free resources and close SDL
	close();
	return 0;
}
