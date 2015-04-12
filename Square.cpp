#include <glfw3.h>
#include "Square.h"


Square::Square(float newBot, float newLeft, float newwidth){
	bottom = newBot;
	left = newLeft;
	width = newwidth;
}
void Square::Display(){
	glColor3f(0.0,1,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(bottom,left);
		glVertex2f(bottom+width,left);
		glVertex2f(bottom+width,left+width);
		glVertex2f(bottom,left+width);
	glEnd();
}