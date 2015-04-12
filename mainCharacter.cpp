#include "mainCharacter.h"
#include <glfw3.h>
mainCharacter::mainCharacter(int width,int height){
	screenHeight = height;
	screenWidth = width;
}
void mainCharacter::Render(){
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(screenWidth/2,screenHeight/2);
		glVertex2f(screenWidth/2,screenHeight/2+10);
		glVertex2f(screenWidth/2+10,screenHeight/2+10);
		glVertex2f(screenWidth/2+10,screenHeight/2);
	glEnd();
	glColor3f(0.0,0.0,0.0);


}
bool mainCharacter::Intersects(float MX,float MY, float MinX, float MinY)
        {
            if (screenWidth/2+10 < MinX || 
                screenHeight/2+10 < MinY || 
                screenWidth/2 >  MX|| 
                screenHeight/2 > MY ) 
            {
                return false;
            }
    return true;
}

