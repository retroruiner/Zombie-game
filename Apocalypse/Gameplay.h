#pragma once
#include "Object.h"
#include "Survivor.h"
#include <iostream>
#include <SDL.h>
#include "GameTextures.h"
#include "Map.h"


class Gameplay {
private:
	bool isActive;
	Object* survivor;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Map* map;
public:
	void createGame(int width, int height, int mapSizeX, int mapSizeY);
	void eventHandle();
	void update();
	void display();
	void clear();
	bool active();
};

