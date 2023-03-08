#pragma once
#include "Object.h"
#include "SDL.h"
class Bullet: public Object
{
private:
	int durabilty, x, y;
	bool up, down, right, left;
	SDL_Rect bulletRect;
	SDL_Texture* bulletTex;
	SDL_Renderer* renderer;
	void keyPressed(SDL_KeyboardEvent* event);
	void keyReleased(SDL_KeyboardEvent* event);
public:
	Bullet(const char* path, SDL_Renderer* renderer);
	void act();
	void inputListen(SDL_Event event);
	void display(SDL_Rect survivor);
};

