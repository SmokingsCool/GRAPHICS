#include "Projectile.h"

bool Projectile::Intersects(float MX,float MY, float MinX, float MinY){
if (	projectileMinX+width < MinX || 
        projectileMinY+height < MinY|| 
        projectileMinX  > MX   || 
        projectileMinY > MY    ) 
            {
				return false;
	}
	else{
		return true;
	}
}
Projectile::Projectile(float newWidth,float newHeight,float newMinX, float newMinY, float newXVel, float newYVel){
	width = newWidth;
	height = newHeight;
	projectileMinX = newMinX;
	projectileMinY = newMinY;
	xVel = newXVel;
	yVel = newYVel;
	GLuint myTex = loadPNG("shuriken.png");
	thisTexture = myTex;
}
GLuint Projectile::loadPNG(char* name)
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
Projectile::Projectile(){
}
void Projectile::setOwner(string newowner){
	owner = newowner;
}
void Projectile::updateCoord(){
	projectileMinX += xVel;
	projectileMinY += yVel;
}
void Projectile::display(){
	if (deleted != true){
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,thisTexture);
		glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
			glVertex2f(projectileMinX,projectileMinY);
		glTexCoord2f( 1.0,0.0);
			glVertex2f(projectileMinX,projectileMinY+width);
		glTexCoord2f(1.0, 1.0);
			glVertex2f(height+projectileMinX,projectileMinY+width);
		glTexCoord2f(0.0, 1.0);
			glVertex2f(height+projectileMinX,projectileMinY);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
		glDisable(GL_BLEND);
	}
	if (abs(projectileMinX) > 100000 || abs(projectileMinX) > 100000){
		deleted = true;
	}
}
