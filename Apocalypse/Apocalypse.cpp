#include "Gameplay.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]) {
	//Frame rate limitation, so the charachter would move slower on the map. 
	int FPS = 60;
	int delayFrame = 1000 / FPS;
	Uint32 frameBegin;
	int frameTime;
	try {
		int mapSizeX;
		int mapSizeY;
		//Taking the size of window from a user
		cin >> mapSizeX >> mapSizeY;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (mapSizeX != mapSizeY) {
			throw 1;
		}
		else {
			Gameplay* game = new Gameplay();
			//Creating a window
			game->createGame(mapSizeX * 32, mapSizeY * 32, mapSizeX, mapSizeY);

			//The game loop
			while (game->active()) {
				frameBegin = SDL_GetTicks();
				//Handles events
				game->eventHandle();
				//Movement of a character 
				game->update();
				//Displaying objects in a window
				game->display();
				frameTime = SDL_GetTicks() - frameBegin;

				if (delayFrame > frameTime) {
					SDL_Delay(delayFrame - frameTime);
				}
			}
			//Clearin game window
			game->clear();
		}
	}
	catch (int error) {
		if (error == 1) {
			cout << "Incorrect size was entered" << endl;
		}
	}
	return 0;
}