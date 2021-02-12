
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "SDL_ttf.h"


//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
        bool loadFromFile( std::string path, SDL_Renderer* gRenderer);
		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip= NULL, int size_x = 0, int size_y = 0, SDL_RendererFlip Flip = SDL_FLIP_NONE);
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor, TTF_Font* mFont, SDL_Renderer* gRenderer );

		//Gets image dimensions
		int getWidth();
		int getHeight();
		void setHeight(int h);
		void setWidth(int w);

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};
