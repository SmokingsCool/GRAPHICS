
#include "Square.h"

#include <glfw3.h>


Square::Square(float newBot, float newLeft, float newwidth){
	bottom = newBot;
	origBot = newBot;
	left = newLeft;
	origLeft = newLeft;
	width = newwidth;
}
float Square::getOrigBottom(){
	return origBot;
}
float Square::getOrigLeft(){
	return origLeft;
}
float Square::getBottom(){
	return bottom;
}
float Square::getLeft(){
	return left;
}
void Square::updateCoord(float btop,float bleft){
	bottom = btop;
	left = bleft;
}
void Square::setType(int typeN){
	type = typeN - '0';
	GLuint myTexture = 0;
	if (type == 1){
		myTexture = loadPNG("brick.png");
	}
	else if (type == 2){
		myTexture = loadPNG("character_alpha.png");
	}
	if (type !=3 && type != 0){
		thisTexture = myTexture;
	}
}
void Square::setDeleted(bool news){
	deleted = news;
}
void Square::Display(){
	if (type !=0){
	if (deleted != true){
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,thisTexture);
		glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
			glVertex2f(bottom,left);
		glTexCoord2f( 1.0,0.0);
			glVertex2f(bottom+width,left);
		glTexCoord2f(1.0, 1.0);
			glVertex2f(bottom+width,left+width);
		glTexCoord2f(0.0, 1.0);
			glVertex2f(bottom,left+width);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
		glDisable(GL_BLEND);
	}}
}

int Square::getType(){
	return type;
}
GLuint Square::loadPNG(char* name)
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
void Square::Color(char c){
	color = c;
}
void Square::setColor(){
}