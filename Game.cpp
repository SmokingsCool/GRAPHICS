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
	currLevel.setCentre(screenHeight,screenWidth);
	mainChar = mainCharacter(screenWidth,screenHeight);
	
}
void Game::addVelocities(){
	currLevel.updateCoord(mainChar.getxVel(),mainChar.getyVel());
}
void Game::mainJump(){
	mainChar.jump();
}
void Game::Run(){
	mainChar.newIteration();
	addVelocities();
	mainChar.xDecay();
	currLevel.Render();
	mainChar.Render();
	
	string checkThisShit = currLevel.checkCollisionMain(mainChar);
	
	mainChar.gravityCheck();
}
void Game::adjustCoord(int xAdj, int yAdj){
	currLevel.updateCoord(xAdj,yAdj);
}
void Game::moveHoriz(float amount){
	mainChar.changexVel(amount);
}