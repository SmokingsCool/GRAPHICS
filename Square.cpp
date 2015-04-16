#include <glfw3.h>
#include "Square.h"


Square::Square(float newBot, float newLeft, float newwidth){
	bottom = newBot;
	left = newLeft;
	width = newwidth;
}
void Square::updateCoord(float btop,float bleft){
	bottom = btop;
	left = bleft;
}
void Square::Display(){
	setColor();
	glBegin(GL_POLYGON);
		glVertex2f(bottom,left);
		glVertex2f(bottom+width,left);
		glVertex2f(bottom+width,left+width);
		glVertex2f(bottom,left+width);
	glEnd();
}
void Square::Color(char c){
	color = c;
}
void Square::setColor(){
	if (color == 'r'){
		glColor3f(1.0,0.0,0.0);
	}
	else if (color == 'b'){
		glColor3f(0.0,0.0,1.0);
	}
	else{
		glColor3f(0.0,1.0,0.0);
	}
}