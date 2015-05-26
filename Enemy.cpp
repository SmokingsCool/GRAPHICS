#include "Enemy.h"
#include <glfw3.h>

Enemy::Enemy(int width,int height,float newBot,float newLeft){
	Width = width;
	Height = height;
	xVel = 0;
	yVel = 0;
	xAdj = 0;
	yAdj = 0;
	xLimit = 0;
	resting = true;
	gravityCounter = 0;
	restingIterator = false;
	jumpB = false;
	dblJump = false;
	GLuint myTexture = loadPNG("dwarfL.png");
	thisTexture = myTexture;
	bottom = newBot;
	origBot = newBot;
	left = newLeft;
	origLeft = newLeft;
}
Enemy::Enemy(){};

void Enemy::Render(){
	
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,thisTexture);
		glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
			glVertex2f(bottom+xAdj,left+yAdj);
		glTexCoord2f( 1.0,0.0);
			glVertex2f(bottom+Width+xAdj,left+yAdj);
		glTexCoord2f(1.0, 1.0);
			glVertex2f(bottom+Width+xAdj,left+Height+yAdj);
			
		glTexCoord2f(0.0, 1.0);
			glVertex2f(bottom+xAdj,left+Height+yAdj);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
		glDisable(GL_BLEND);

}
void Enemy::setTexture(string newTex){
	string right = "right";
	string left = "left";
	if (newTex.compare(left) == 0){
		GLuint myTexture = loadPNG("dwarfL.png");
		thisTexture = myTexture;
		direction = left;
	}
	else if (newTex.compare(right) == 0) {
		GLuint myTexture = loadPNG("dwarfR.png");
		thisTexture = myTexture;
		direction = right;
	}
}
GLuint Enemy::loadPNG(char* name)
{
	// Texture loading object
	nv::Image img;

	GLuint myTextureID;

	// Return true on success
	if(img.loadImageFromFile(name))
	{
		glGenTextures(1, &myTextureID);
		glBindTexture(GL_TEXTURE_2D, myTextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
		glTexImage2D(GL_TEXTURE_2D, 0, img.getInternalFormat(), img.getWidth(), img.getHeight(), 0, img.getFormat(), img.getType(), img.getLevel(0));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0f);
	}

	else
		MessageBox(NULL, "Failed to load texture", "End of the world", MB_OK | MB_ICONINFORMATION);

	return myTextureID;
}
void Enemy::updateDirection(float mainMinX){
	float z = ((bottom-xAdj));
	if (mainMinX < z){
		direction = "left";
		directionMod = -1;
		GLuint myTexture = loadPNG("dwarfL.png");
		thisTexture = myTexture;
	}
	else{
		direction = "right";
		directionMod = 1;
		GLuint myTexture = loadPNG("dwarfR.png");
		thisTexture = myTexture;
	}
}
string Enemy::getDirection(){
	return direction;
}
void Enemy::newIteration(){
	restingIterator = false;
}
void Enemy::SetXAdj(float newValue){
	xAdj = newValue;
}
void Enemy::SetYAdj(float newValue){
	yAdj = newValue;
}
vector<float> Enemy::IntersectsIntraverse(float MX,float MY, float MinX, float MinY)
        {
			vector <float> toReturn ;
			toReturn.push_back(0);
			toReturn.push_back(0);
            if (left+Width+xAdj < MinX || 
				 bottom+Height+yAdj< MinY|| 
				 left  > MX   || 
				 bottom > MY    )  
            {
				if (restingIterator!=true){
					resting = false;
					
				}
                return toReturn;
            }
			else{
				double goLeft = (abs(left+Width+xAdj)- abs(MinX))  ;
				double goUp = (abs(MY)-abs(bottom) );
				double goRight = (abs(MX)-abs(left));
				double goDown = (abs(bottom+Height+yAdj) -abs(MinY) ),x, y;
				
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
bool Enemy::Intersects(float MX,float MY, float MinX, float MinY){
	if (left+Width+xAdj < MinX || 
        bottom+Height+yAdj< MinY|| 
        left  > MX   || 
        bottom > MY    ) 
            {
				return false;
	}
	else{
		return true;
	}


}
void Enemy::jump(){
	

	if (dblJump == false){
		resting = false;
		if (yVel > -1.5){
			if (jumpB == true){
				yVel = -0.3;
			}
			yVel = yVel - 1.5;
		}
	}
	if(jumpB == false){
		jumpB = true;}
	else if(dblJump == false){
		dblJump = true;
	}
}
void Enemy::xDecay(){
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
void Enemy::gravityCheck(){
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
void Enemy::changexVel(float amount){

	float mAmount;
	if (amount < 0){
		mAmount = -3;
	}
	else{
		mAmount = 3;
	}
	if (xVel < mAmount && xVel >= 0){
		xVel = amount;}
	else if(xVel > mAmount && xVel <= 0){
		xVel = amount;}
	if (resting == false && xVel != 0){
		xLimit = -xVel;
	}
}
float Enemy::getxVel(){
	return xVel;
}
float Enemy::getyVel(){
	return yVel;
}
