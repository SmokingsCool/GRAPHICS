#include "mainCharacter.h"
#include <glfw3.h>

mainCharacter::mainCharacter(int width,int height){
	screenHeight = height;
	screenWidth = width;
	xVel = 0;
	yVel = 0;
}
mainCharacter::mainCharacter(){};
void mainCharacter::Render(){
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(screenWidth/2+10,screenHeight/2);
		glVertex2f(screenWidth/2+10,screenHeight/2+10);
		glVertex2f(screenWidth/2,screenHeight/2+10);
		glVertex2f(screenWidth/2,screenHeight/2);
	glEnd();
	glColor3f(0.0,0.0,0.0);


}
vector<float> mainCharacter::IntersectsIntraverse(float MX,float MY, float MinX, float MinY)
        {
			bool checkFall = false;
			vector <float> toReturn ;
			toReturn.push_back(0);
			toReturn.push_back(0);
            if (screenWidth/2+10 < MinX || 
                screenHeight/2+10 < MinY || 
                screenWidth/2 >  MX|| 
                screenHeight/2 > MY ) 
            {
				resting = false;
                return toReturn;
            }
			else{
				double goLeft = (abs(screenWidth/2+10)- abs(MinX))  ;
				double goUp = (abs(MY)-abs(screenHeight/2) );
				double goRight = (abs(MX) -abs(screenWidth / 2));
				double goDown = (abs(screenHeight / 2+10) -abs(MinY)  );
				double min;
				double x;
				double y;
				if (goRight< goLeft)
				{
					x = -goRight;
					if( xVel >0){
						xVel = xVel - 0.5;
					}

				}
				else
				{
					x = goLeft;
					if( xVel <0){
						xVel = xVel + 0.5;
					}
				}
				if (goUp < goDown && goUp != 0 )
				{ 
					y = -goUp;
					if (goUp < goLeft && goUp < goRight){
					 yVel = 0;
					}
					
					
				}
				else if(goUp < goDown && goUp ==0 && goUp != goLeft && goUp != goRight){
					y = -goUp;
					yVel = 0;
					resting = true;
				}
				else{y = goDown;
					if (yVel < 0){
						yVel=0;
					}
				}
				if (abs(x) > abs(y))
				{
					toReturn[1] = y;
				}
				else
				{
					toReturn[0] = x;
				}
				if (checkFall != true){
					resting = false;
				}
				return toReturn;
				
			};
}
bool mainCharacter::Intersects(float MX,float MY, float MinX, float MinY){
	if (screenWidth/2+10 < MinX || 
        screenHeight/2+10 < MinY|| 
        screenWidth/2  > MX   || 
        screenHeight/2 > MY    ) 
            {
				return false;
	}
	else{
		return true;
	}


}
void mainCharacter::jump(){
	resting = false;
	if (yVel > -5){
	yVel -= 5;
	}
}
void mainCharacter::gravityCheck(){
	if (resting == false){
		if (yVel < 10){
			yVel += 0.1;
		}
	}

}
void mainCharacter::changexVel(float amount){
	xVel = xVel + amount;
}
float mainCharacter::getxVel(){
	return xVel;
}
float mainCharacter::getyVel(){
	return yVel;
}
