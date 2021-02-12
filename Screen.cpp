#include "Screen.h"

Screen::Screen()
{
    mWindow = NULL;
    mRenderer = NULL;
    mScreenSurface = NULL;
    mBackgroundSurface = NULL;
    bgMusic = NULL;
    mFont = NULL;
    cout << "Screen Constructor Called!" << endl;
}

Screen::Screen(SDL_Renderer* gRenderer, SDL_Window* gWindow, SDL_Surface* gScreenSurface, int width, int height)
{
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;
    mWindow = gWindow;
    mRenderer = gRenderer;
    mScreenSurface = gScreenSurface;
    mBackgroundSurface = NULL;
    bgMusic = NULL;
    mFont = NULL;
    TTF_CloseFont( mFont );
	mFont = NULL;
}


SDL_Surface* Screen::loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, mScreenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

SDL_Texture* Screen::GenerateBackground()
{
    SDL_Rect background;
    background.x = 0;    background.y = 0;
    background.w = SCREEN_WIDTH;    background.h = SCREEN_HEIGHT;
    SDL_BlitScaled( mBackgroundSurface, NULL, mScreenSurface, &background );
    SDL_UpdateWindowSurface(mWindow);
    bgTexture = SDL_CreateTextureFromSurface(mRenderer ,mScreenSurface);
    return bgTexture;
}

bool Screen::LoadTextures(){}
bool Screen::LoadAudio(){}
void Screen::ScreenHandler(){}

Screen::~Screen()
{

    SDL_DestroyTexture(bgTexture);
    bgTexture = NULL;

    FontTextureSheet.free();

    if (mFont != NULL)
        TTF_CloseFont( mFont );
	mFont = NULL;

    mRenderer = NULL;
    mWindow = NULL;
    mScreenSurface = NULL;
    mBackgroundSurface = NULL;

    if (bgMusic != NULL)
    {
        Mix_FreeMusic(bgMusic);
        bgMusic = NULL;
    }
	cout << "Screen Destructor Called!" << endl;
	cout << "--------------------------" << endl;
}
