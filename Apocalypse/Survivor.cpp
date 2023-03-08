#include "Survivor.h"
#include <iostream>


Survivor::Survivor(const char* path, SDL_Renderer* renderer)
{
	this->renderer = renderer;
	survivorTex = GameTextures::loadTex(path, renderer);
	//Survivor's size and coordinates 
	survivorRect.w = 64;
	survivorRect.h = 64;
	survivorRect.x = 20;
	survivorRect.y = 20;
	//Mouse presses - false
	right = left = up = down = false;
	 
}

//Display character on screen
void Survivor::display() {
	GameTextures::displayTex(survivorTex, survivorRect, renderer);
}



//Detect key presses and releases
void Survivor::inputListen(SDL_Event event) {
	switch (event.type)
	{
		//Kep pressed
	case SDL_KEYDOWN:
		keyPressed(&event.key);
		break;
		//Key released
	case SDL_KEYUP:
		keyReleased(&event.key);
		break;
	}
}

void Survivor::keyPressed(SDL_KeyboardEvent* event)
{
	//If one of keys "WASD" is pressed, the corresponding variable (left/right/up/down) is set to true, meaning the key is presses
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_A)
		{
			left = true;
		}

		if (event->keysym.scancode == SDL_SCANCODE_D)
		{
			right = true;
		}

		if (event->keysym.scancode == SDL_SCANCODE_S)
		{
			down = true;
		}

		if (event->keysym.scancode == SDL_SCANCODE_W)
		{
			up = true;
		}
	}

}

void Survivor::keyReleased(SDL_KeyboardEvent* event)
{
	//If one of keys "WASD" is released, the corresponding variable (left/right/up/down) is set to false, meaning the key is released
	//Key 'A'
	if (event->keysym.scancode == SDL_SCANCODE_A)
	{
		left = false;
	}
	//Key 'D'
	if (event->keysym.scancode == SDL_SCANCODE_D)
	{
		right = false;
	}
	//Key 'S'
	if (event->keysym.scancode == SDL_SCANCODE_S)
	{
		down = false;
	}
	//Key 'W'
	if (event->keysym.scancode == SDL_SCANCODE_W)
	{
		up = false;
	}
	
}

//Survivor's movement
void Survivor::act() {
	
	//If one or multiple keys (WASD) were pressed, then survivor will move in the corresponding direction
	if (right) {
		survivorRect.x += 1;
	}
	if (left) {
		survivorRect.x -= 1;
	}
	if (up) {
		survivorRect.y -= 1;
	}
	if (down) {
		survivorRect.y += 1;
	}
	
 }

//Checks for collision
bool Survivor::checkCollision(SDL_Rect a, SDL_Rect b)
{
	//a is to the left from b
	if (a.x + a.w <= b.x)
	{
		return false;
	}

	//a is to the right from b
	if (a.x >= b.x + b.w)
	{
		return false;
	}

	//a is above the b
	if (a.y + a.h <= b.y)
	{
		return false;
	}

	//a is below b
	if (a.y >= b.y + b.h)
	{
		return false;
	}

	return true;
}


