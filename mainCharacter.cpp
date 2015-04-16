#include "mainCharacter.h"
#include <glfw3.h>

mainCharacter::mainCharacter(int width,int height){
	screenHeight = height;
	screenWidth = width;
	xVel = 0;
	yVel = 0;
	xLimit = 0;
	resting = true;
	gravityCounter = 0;
	restingIterator = false;
	jumpB = false;
	dblJump = false;
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
void mainCharacter::newIteration(){
	restingIterator = false;
}
vector<float> mainCharacter::IntersectsIntraverse(float MX,float MY, float MinX, float MinY)
        {
			vector <float> toReturn ;
			toReturn.push_back(0);
			toReturn.push_back(0);
            if (screenWidth/2+10 < MinX || 
                screenHeight/2+10 < MinY || 
                screenWidth/2 >  MX|| 
                screenHeight/2 > MY ) 
            {
				if (restingIterator!=true){
					resting = false;
					
				}
                return toReturn;
            }
			else{
				double goLeft = (abs(screenWidth/2+10)- abs(MinX))  ;
				double goUp = (abs(MY)-abs(screenHeight/2) );
				double goRight = (abs(MX)-abs(screenWidth / 2));
				double goDown = (abs(screenHeight / 2+10) -abs(MinY) ),x, y;
				
				if (goRight< goLeft)
				{
					x = -goRight;
					if (goRight < goUp && goRight < goDown && xVel > 0){
						xVel = 0;
					}


				}
				else
				{
					x = goLeft;
					if (goLeft < goUp && goLeft < goDown && xVel < 0){
						xVel = 0;
					}
				}
				if (goUp < goDown && goUp != 0 )
				{ 
					y = -goUp;
					if (goUp < goLeft && goUp < goRight){
					 yVel = 0;
					 xLimit = 0;
					 resting = true;
					 jumpB = false;
					 dblJump = false;
					 restingIterator = true;
					 gravityCounter = 0;
					}
					else{
						if (restingIterator != true){
							resting = false;
						}
					}
					
					
					
				}
				else if(goUp < goDown && goUp ==0 && goUp != goLeft && goUp != goRight){
					y = -goUp;
					yVel = 0;
					xLimit = 0;
					resting = true;
					jumpB = false;
					 dblJump = false;
					restingIterator = true;
					gravityCounter = 0;
				}
				else if (goUp ==0 && goDown!=0 && goLeft != 0 && goRight != 0){
					resting = true;
					jumpB = false;
					 dblJump = false;
					restingIterator = true;
				}
				else{
					y = goDown;
					if (yVel > 0 && goDown < goRight && goDown < goLeft){
						yVel+=0.0001;
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
	

	if (dblJump == false){
		resting = false;
		if (yVel > -2.5){
			if (jumpB == true){
				yVel = -0.5;
			}
			yVel = yVel - 2.5;
		}
	}
	if(jumpB == false){
		jumpB = true;}
	else if(dblJump == false){
		dblJump = true;
	}
}
void mainCharacter::xDecay(){
	if (resting != true){
		if (xVel < xLimit && (xLimit - xVel)<0.1){
			xVel = xVel + 0.01;
		}
		else if (xVel > xLimit && (xLimit - xVel )>0.1){
			xVel = xVel - 0.01;
		}

	}
	else{
		xLimit = 0;
		if (xVel > xLimit && (xVel - xLimit)>0.3){
			xVel = xVel - 0.03;
		}
		else if (xVel > xLimit && (xVel - xLimit)<0.3){
			xVel = xLimit;
		}
		
		if (xVel < xLimit && (xVel - xLimit)<-0.3){
			xVel = xVel + 0.03;
		}
		else if (xVel < xLimit && (xVel - xLimit)>-0.3){
			xVel = xLimit;
		}
	}
	
	
}
void mainCharacter::gravityCheck(){
	if (resting == false){
		if (yVel < 4){
			if (gravityCounter-0.1 > 0){
				gravityCounter = 0.1;
			}
			else if(gravityCounter-0.04 < 0){
				gravityCounter += 0.0025;
			}
			yVel += gravityCounter;
			
		}
	}

}
void mainCharacter::changexVel(float amount){
	float mAmount = 3;
	if (xVel < mAmount && xVel >= 0){
		xVel = amount;}
	else if(xVel > mAmount && xVel <= 0){
		xVel = amount;}
	if (resting == false && xVel != 0){
		xLimit = -xVel;
	}
}
float mainCharacter::getxVel(){
	return xVel;
}
float mainCharacter::getyVel(){
	return yVel;
}
