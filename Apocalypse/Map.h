#pragma once
#include "SDL.h"
#include "GameTextures.h"
#include "Survivor.h"


class Map
{
private:
	SDL_Rect obj;
	SDL_Texture* cement;
	SDL_Texture* water;
	SDL_Texture* grass;
	SDL_Texture* wall;
	int rows, columns;
	int **map;
	
public:
	Map(SDL_Renderer* renderer, int rows, int columns);
	~Map();
	void loadMapTex(char* fileName);
	void drawMapTex(SDL_Renderer* renderer);
};
