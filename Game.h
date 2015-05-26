
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
		vector<Projectile> projectileArray;
		vector<Enemy> enemyArray;
	public:

		Game(int,int);
		void displayProjectiles();
		void CreateLevel();
		void adjustCoord(int, int);
		void Run();
		void mainJump();
		void addVelocities();
		void moveHoriz(float );
		void changeMainTexDir(string);
		void mainCharThrow();
		void updateEnemyDirection();
		void displayEnemies();

};