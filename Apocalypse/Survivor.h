#pragma once
#include "Object.h"
#include <SDL.h>
class Survivor: public Object
{
private:
	bool up, down, right, left;
	SDL_Rect survivorRect;
	SDL_Texture* survivorTex;
	SDL_Renderer* renderer;
	void keyPressed(SDL_KeyboardEvent* event);
	void keyReleased(SDL_KeyboardEvent* event);
	bool checkCollision(SDL_Rect a, SDL_Rect b);

public:
	Survivor(const char* path, SDL_Renderer* renderer);
	void act();
	void inputListen(SDL_Event event);
	void display();
	
};

