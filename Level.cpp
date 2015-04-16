#include "Level.h"
void Level::setFileInputName(string name){
	fileInputName = name;
}
void Level::updateCoord(int xAdjust,int yAdjust){
	xAdj = xAdj + xAdjust;
	yAdj = yAdj + yAdjust;
}
void Level::Load(){
	firstRender = true;
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
	//for(int i = 0; i < levelArray.size();i++){
		//for(int j = 0 ; j < levelArray[i].size();j++){
//			if (levelArray[i][j] == '3'){
				//firstRender = false;
				//Square newsquare = Square((j)*50+xAdj,(i)*50+yAdj,50);
				//newsquare.Color('r');
				//newsquare.Display();
				//newsquare.updateCoord(i*50,j*50);
			//}
		//}
	//}
	for(int i = 0; i < levelArray.size();i++){
		for(int j = 0 ; j < levelArray[i].size();j++){
			if (levelArray[i][j] == '1'){
				Square newsquare = Square((j)*50+xAdj,(i)*50+yAdj,50);
				newsquare.Display();
			}
			else if(levelArray[i][j] == '2'){
				//setting up collectibles
				Square newsquare = Square((j)*50+xAdj,(i)*50+yAdj,50);
				newsquare.Color('b');
				newsquare.Display();
			}
			else if (levelArray[i][j] == '3'&& firstRender == true){
				firstRender = false;
				float CtoNCX = 0;
				float CtoNCY = 0;
				CtoNCX =screenWidth/2 - abs((i)*50+xAdj);
				CtoNCY =screenHeight/2 - abs((j)*50+yAdj-15);
				updateCoord(CtoNCY,CtoNCX);
				
				
			}
		}
	}
}
void Level::setCentre(float x, float y){
	screenWidth = x;
	screenHeight = y;
}
string Level::checkCollisionMain(mainCharacter &main){
	string toReturn;
	for(int i = 0; i < levelArray.size();i++){
		for(int j = 0 ; j < levelArray[i].size();j++){
			if (levelArray[i][j] == '1'){
				float maxX = (i)*50+yAdj+50;
				float maxY = (j)*50+xAdj+50;
				float minX = (i)*50+yAdj;
				float minY = (j)*50+xAdj;
			
				vector<float> doesCollide = main.IntersectsIntraverse(maxY,maxX,minY,minX);
				updateCoord(doesCollide[0],doesCollide[1]);
				
			}
			else if (levelArray[i][j] == '2'){
				float maxX = (i)*50+yAdj+50;
				float maxY = (j)*50+xAdj+50;
				float minX = (i)*50+yAdj;
				float minY = (j)*50+xAdj;
				bool doesCollide = main.Intersects(maxY,maxX,minY,minX);
				if (doesCollide == true){
					levelArray[i][j] = '0';
					score += 100;
				}
			}
		}
	}
	return toReturn;

}