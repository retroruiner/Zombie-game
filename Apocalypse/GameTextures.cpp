#include "GameTextures.h"


//Loads a texture of an object from .bmp file
 SDL_Texture* GameTextures::loadTex(const char* path, SDL_Renderer* renderer) {
	SDL_Surface* objSurf = SDL_LoadBMP(path);
	SDL_Texture* objTex = SDL_CreateTextureFromSurface(renderer, objSurf);
	SDL_FreeSurface(objSurf);
	return objTex;
}


 //Displays the texture on the screen
 void GameTextures::displayTex(SDL_Texture* texture, SDL_Rect obj, SDL_Renderer* renderer)
 {
	 SDL_RenderCopy(renderer, texture, NULL, &obj);
 }


