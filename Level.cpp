#include "Level.h"

void Level::setFileInputName(string name){
	fileInputName = name;
}
void Level::updateCoord(int xAdjust,int yAdjust){
	xAdj = xAdj + xAdjust;
	yAdj = yAdj + yAdjust;
	for(int i = 0; i < enemyArray.size();i++){
		enemyArray[i].SetXAdj(xAdj);
		enemyArray[i].SetYAdj(yAdj);
	}
}
void Level::Load(){
	currMaxLevel = 2;
	firstRender = true;
	levelArray.clear();
	string s;
	levelNum ++;
	if (levelNum > currMaxLevel) {
		levelNum = 1;
	}
	string levelFile = "Levels/level"+std::to_string (levelNum)+ "\.txt" ;
	ifstream level(levelFile);
	vector <vector <char>> firstArray;
	int x = 0;
	vector< vector <char>> newlevel; 
	firstArray = newlevel;
	if (level){
		while (getline(level,s)){
			vector<char> row;
			for(int i = 0 ; i < s.length();i++){
				
				char position = s[i];
				row.push_back(position);
			}
			firstArray.push_back(row);
		}
	}
	for(int i = 0; i < firstArray.size();i++){
		vector<Square> row;
		for(int j = 0 ; j < firstArray[i].size();j++){
			
			char x = firstArray[i][j] - '0';
			if (x == 4){
				Enemy tempEnemy = Enemy(37,68,(j)*50,(i)*50);
				enemyArray.push_back(tempEnemy);
			}
			else if (x != (3) && x!= 0){
				Square newsquare = Square((j)*50,(i)*50,50);
				newsquare.setType(firstArray[i][j]);
				row.push_back(newsquare);
			}
			else if (x!= 0) {
				float CtoNCX = 0;
				float CtoNCY = 0;
				CtoNCX =screenWidth/2 - abs((i)*50+xAdj);
				CtoNCY =screenHeight/2 - abs((j)*50+yAdj-15);
				updateCoord(CtoNCY,CtoNCX);
			}
			
		}
		levelArray.push_back(row);
	}

}
vector<Enemy> Level::getInitEnemyArray(){
	return enemyArray;
}
void Level::Render(){


	for(int i = 0; i < levelArray.size();i++){
		if (i == 11){
			int yolo = 0;
		}
		for(int j = 0 ; j < levelArray[i].size();j++){
			levelArray[i][j].updateCoord(levelArray[i][j].getOrigBottom()+xAdj,levelArray[i][j].getOrigLeft()+yAdj);

			levelArray[i][j].Display();
		}
	}
}
void Level::displayEnemies(){
	for(int i = 0; i < enemyArray.size();i++){
		enemyArray[i].Render();
		enemyArray[i].updateDirection(screenWidth/2);
	} 
}
void Level::setCentre(float x, float y){
	screenWidth = x;
	screenHeight = y;
	xAdj = 0;
	yAdj = 0;
}
string Level::checkCollisionMain(mainCharacter &main, vector<Projectile> &projectileArray){
	string toReturn;
	for(int i = 0; i < levelArray.size();i++){
		for(int j = 0 ; j < levelArray[i].size();j++){
			if (levelArray[i][j].getType() == 1){
				float maxX = levelArray[i][j].getOrigLeft()+yAdj+50;
				float maxY = levelArray[i][j].getOrigBottom()+xAdj+50;
				float minX = levelArray[i][j].getOrigLeft()+yAdj;
				float minY = levelArray[i][j].getOrigBottom()+xAdj;
				if (projectileArray.size() != 0){
					std::vector<Projectile>::iterator iterate = projectileArray.begin(); 
					int x = 0;
					bool end = false;
					while (end == false){
						bool collides = projectileArray[x].Intersects(maxY,maxX,minY,minX);
						if (collides == true){
							projectileArray.erase(iterate);
							iterate = projectileArray.begin();
							for (int p = 0;p<x-1;p++){
								iterate++;
								x--;
							}
						}
						if (x == projectileArray.size()-1 || projectileArray.size() == 0 ){
							end = true;
							x == 0;
						}
						else{
							x++;
							iterate++;
						}
					}
				}
				vector<float> doesCollide = main.IntersectsIntraverse(maxY,maxX,minY,minX);
				updateCoord(doesCollide[0],doesCollide[1]);
				
			}
			else if (levelArray[i][j].getType() == 2){
				float maxX = levelArray[i][j].getOrigLeft()+yAdj+50;
				float maxY = levelArray[i][j].getOrigBottom()+xAdj+50;
				float minX = levelArray[i][j].getOrigLeft()+yAdj;
				float minY = levelArray[i][j].getOrigBottom()+xAdj;
				bool doesCollide = main.Intersects(maxY,maxX,minY,minX);
				if (doesCollide == true){
					levelArray[i][j].setDeleted(true);
					score += 100;
				}
			}
		}
	}

	return toReturn;

}

bool Level::checkNewLevel(mainCharacter &main){
	bool doesCollide = false;
	for(int i = 0; i < levelArray.size();i++){
		for(int j = 0 ; j < levelArray[i].size();j++){
			if (levelArray[i][j].getType() == 5){
				float maxX = levelArray[i][j].getOrigLeft()+yAdj+50;
				float maxY = levelArray[i][j].getOrigBottom()+xAdj+50;
				float minX = levelArray[i][j].getOrigLeft()+yAdj;
				float minY = levelArray[i][j].getOrigBottom()+xAdj;
				doesCollide = main.Intersects(maxY,maxX,minY,minX);
			}
		}
	}
	return doesCollide;
}
