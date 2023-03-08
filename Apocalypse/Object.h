#pragma once
#include "SDL.h"
#include "GameTextures.h"
//Abstract class
class Object
{

public:
	virtual void act() = 0;
	virtual void display() = 0;
	virtual void inputListen(SDL_Event event) = 0;
};

