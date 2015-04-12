#include "Game.h"
using namespace std;
Game::Game(int width,int height){
	screenHeight = height;
	screenWidth = width;
}
void Game::CreateLevel(){
	currentLevel++;
	Level newLevel = Level();
	currLevel.setFileInputName("level1.lvl");
	currLevel.Load();
	currLevel.Render();
	mainCharacter mainChar = mainCharacter(screenWidth,screenHeight);
	mainChar.Render();
	currLevel.checkCollisionMain(mainChar);
}
void Game::adjustCoord(int xAdj, int yAdj){
	currLevel.updateCoord(xAdj,yAdj);
}