#include "Game.h"
using namespace std;
Game::Game(int width,int height){
	screenHeight = height;
	screenWidth = width;
}
void Game::CreateLevel(){
	currentLevel++;
	Level newLevel = Level();
	string levelFile = "level"+currentLevel;
	string fileexten = levelFile + ".lvl";
	currLevel.setFileInputName("Levels/level"+std::to_string (currentLevel)+ "\.txt");
	currLevel.setCentre(screenHeight,screenWidth);
	currLevel.Load();
	mainChar = mainCharacter(screenWidth,screenHeight);
	mainChar.setTexture("left");
}
void Game::addVelocities(){
	currLevel.updateCoord(mainChar.getxVel(),mainChar.getyVel());
}
void Game::mainJump(){
	mainChar.jump();
}
void Game::changeMainTexDir(string newN){
	mainChar.setTexture(newN);
}
void Game::mainCharThrow(){
	int directionMod = 0;
	if (mainChar.getDirection().compare("left") ==0){
		directionMod = 1;
	}
	else {
		directionMod = -1;}
	Projectile shuriken = Projectile(15,21,screenWidth/2 ,screenHeight/2+10,directionMod*0.6,0);
	projectileArray.push_back(shuriken);
}
void Game::Run(){
	bool nextLevel = currLevel.checkNewLevel(mainChar);
	if (nextLevel == false){
		mainChar.newIteration();
		addVelocities();
		mainChar.xDecay();
		currLevel.Render();
		mainChar.Render();
		
		string checkThisShit = currLevel.checkCollisionMain(mainChar,projectileArray);
		displayProjectiles();
		displayEnemies();
		mainChar.gravityCheck();
	}
	else{
		CreateLevel();
	}
}
void Game::displayProjectiles(){
	for (int i = 0; i < projectileArray.size();i++){
		projectileArray[i].updateCoord();
		projectileArray[i].display();
	}
}
void Game::updateEnemyDirection(){
	for (int i = 0; i < enemyArray.size(); i ++){
		enemyArray[i].updateDirection(screenWidth/2);
	}
}
void Game::displayEnemies(){
	currLevel.displayEnemies();
}
void Game::adjustCoord(int xAdj, int yAdj){
	currLevel.updateCoord(xAdj,yAdj);
}
void Game::moveHoriz(float amount){
	mainChar.changexVel(amount);
}