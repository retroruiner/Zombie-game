#include "Gameplay.h"

void Gameplay::createGame(int width, int height, int mapSizeX, int mapSizeY) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not be initialized: " << SDL_GetError();
		isActive = false;
	}
	else {
		std::cout << "SDL system is ready\n";
		window = SDL_CreateWindow("Apocalypse", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		isActive = true;
	}

	survivor = new Survivor("D:/Textures/Survivor.bmp", renderer);
	map = new Map(renderer, mapSizeX, mapSizeY);
	
}


//Handles events
void Gameplay::eventHandle() {
	SDL_Event event;
	//If (X) button is pressed on the top right corner of the window than the game should stop
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isActive = false;
			break;
		}
		//Survivor's control
		survivor->inputListen(event);
	}
	
}


//Displays map and survivor
void Gameplay::display() {
	SDL_RenderClear(renderer);
	map->drawMapTex(renderer);
	survivor->display();
	SDL_RenderPresent(renderer);
	
}

//Survivor movement
void Gameplay::update() {
	survivor->act();
}

//Closes window
void Gameplay::clear() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	map->~Map();
	SDL_Quit();
}

bool Gameplay::active()
{
	return isActive;
}


