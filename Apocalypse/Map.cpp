#include "Map.h"
#include <fstream>
#include <iostream>

using namespace std;

Map::Map(SDL_Renderer* renderer, int row, int column): rows(row), columns(column) {
	cement = GameTextures::loadTex("D:/Textures/Cement.bmp", renderer);
	grass = GameTextures::loadTex("D:/Textures/Grass.bmp", renderer);
	wall = GameTextures::loadTex("D:/Textures/Wall.bmp", renderer);
	water = GameTextures::loadTex("D:/Textures/Water.bmp", renderer);
	
	
	char fileName[256];
	gets_s(fileName);
		
	loadMapTex(fileName);
	
	
	obj.x = 0;
	obj.y = 0;
	obj.h = 32;
	obj.w = 32;

	
}

//Puts integers from file into 2D dynamic array
void Map::loadMapTex(char* fileName) {
	try {
		ifstream file(fileName);
		//Checks if file exists
		if (!file.is_open()) {
			throw 1;
		}
		else {
			int sizeOfFile = 0;
			int tmp;
			while (file >> tmp) {
				sizeOfFile++;
			}
			file.close();
			//Checks if file is of correct size
			if (sizeOfFile != rows * columns) {
				throw 2;
			}
			else {
				file.open(fileName, ios::in);
				//Allocates memory for rows
				map = new int* [rows];
				for (int i = 0; i < rows; i++) {
					//Allocates memory for columns
					map[i] = new int[columns];
					for (int j = 0; j < columns; j++) {
						file >> map[i][j];
					}
				}
			}
		}
	}
	catch (int error) {
		if (error == 1) {
			cout << "File couldn't be opened" << endl;
		} 
		if (error == 2) {
			cout << "Incorrect map size" << endl;
		}
	}
	
}

//Draws textures into the map
void Map::drawMapTex(SDL_Renderer* renderer) {
	int type = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			type = map[i][j];
			obj.x = j * obj.w;
			obj.y = i * obj.h;
			switch (type)
			{
				//Displaying grass textures
			case 0:
				GameTextures::displayTex(grass, obj, renderer);
				break;
				//Displaying cement textures
			case 1:
				GameTextures::displayTex(cement, obj, renderer);
				break;
				//Displaying wall textures
			case 2: 
				GameTextures::displayTex(wall, obj, renderer);
				break;
				//Displaying water textures
			case 3:
				GameTextures::displayTex(water, obj, renderer);
				break;
			}
		}
	}
}

Map::~Map() {
	for (int i = 0; i < rows; ++i) {
		delete[] map[i];
	}
	delete[] map;
}

