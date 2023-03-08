#pragma once
#include "SDL.h"
class GameTextures
{
public:
	static SDL_Texture* loadTex(const char* path, SDL_Renderer* renderer);
	static void displayTex(SDL_Texture* texture, SDL_Rect obj, SDL_Renderer* renderer);
};

