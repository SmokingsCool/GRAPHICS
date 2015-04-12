#include "Level.h"
void Level::setFileInputName(string name){
	fileInputName = name;
}
void Level::updateCoord(int xAdjust,int yAdjust){
	xAdj = xAdj + xAdjust;
	yAdj = yAdj + yAdjust;
}
void Level::Load(){
	string s;
	ifstream level("level1.txt");
	int x = 0;
	vector< vector <char>> newlevel; 
	levelArray = newlevel;
	if (level){
		while (getline(level,s)){
			vector<char> row;
			for(int i = 0 ; i < s.length();i++){
				
				char position = s[i];
				row.push_back(position);
			}
			levelArray.push_back(row);
		}
	}

}
void Level::Render(){
	for(int i = 0; i < levelArray.size();i++){
		for(int j = 0 ; j < levelArray[i].size();j++){
			if (levelArray[i][j] != '0'){
				Square newsquare = Square((j)*50+xAdj,(i)*50+yAdj,50);
				newsquare.Display();
			}
		}
	}
}
bool Level::checkCollisionMain(mainCharacter main){
	for(int i = 0; i < levelArray.size();i++){
		for(int j = 0 ; j < levelArray[i].size();j++){
			if (levelArray[i][j] != '0'){
				float maxX = (i)*50+yAdj+50;
				float maxY = (j)*50+xAdj+50;
				float minX = (i)*50+yAdj;
				float minY = (j)*50+xAdj;
				bool doesCollide = main.Intersects(maxY,maxX,minY,minX);
				if (doesCollide == true){
					
					std::cout << "COLLIDES AT '" << (i)*50+yAdj+50 << ", " << (j)*50+xAdj+50 << ", " << (i)*50+yAdj << ", " << (j)*50+xAdj;
					return true;
				}
			}
		}
	}
	return false;

}