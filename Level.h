#include <string>
#include <vector>
#include <fstream>
#include "mainCharacter.h"
#include"Square.h"
//#include <GL\glut.h>
#include "Projectile.h"
#include <iostream>
#include "Enemy.h"
#include <vector>
using namespace std;

class Level{
	protected:
		vector <vector <Square>> levelArray;
		string fileInputName;
		int xAdj;
		int yAdj;
		int score;
		bool firstRender;
		float screenWidth;
		float screenHeight;
		int levelNum;
		int currMaxLevel;
		vector<Enemy> enemyArray;
	public:
		void Level::updateCoord(int ,int );
		void Load();
		void setFileInputName(string );
		void Render();
		string checkCollisionMain(mainCharacter&,vector<Projectile>&);
		void setCentre(float , float );
		bool Level::checkNewLevel(mainCharacter &);
		vector<Enemy> getInitEnemyArray();
		void displayEnemies();
};