
#include <iostream>
#include <fstream>
#include <string>
#include "Level.h"
class Game{


	protected:
		int screenWidth;
		int screenHeight;
		int currentLevel;
		Level currLevel;
		mainCharacter mainChar;
	public:
		Game(int,int);
		void CreateLevel();
		void adjustCoord(int, int);
		void Run();
		void mainJump();
		void addVelocities();
		void moveHoriz(float );


};