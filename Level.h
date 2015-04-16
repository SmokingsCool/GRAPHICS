#include <string>
#include <vector>
#include <fstream>
#include "mainCharacter.h"
#include"Square.h"
#include <iostream>
using namespace std;

class Level{
	protected:
		vector <vector <char>> levelArray;
		string fileInputName;
		int xAdj;
		int yAdj;
		int score;
		bool firstRender;
		float screenWidth;
		float screenHeight;
	public:
		void Level::updateCoord(int ,int );
		void Load();
		void setFileInputName(string );
		void Render();
		string checkCollisionMain(mainCharacter&);
		void setCentre(float , float );
};