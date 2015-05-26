#include <Windows.h>
#include "Image_Loading\nvImage.h"
#include <glfw3.h>
#include <string>
using namespace std;
class Projectile{

protected:
		float yVel;
		float xVel;
		float projectileMinX;
		float projectileMinY;
		float width;
		float height;
		GLuint thisTexture;
		string owner;
		bool deleted;
public:
	Projectile(float,float,float,float,float,float);
	bool Intersects(float,float,float,float);
	float getxVel();
	float getyVel();
	void changexVel(float);
	Projectile();
	void setOwner(string);
	void updateCoord();
	void display();
	GLuint loadPNG(char* );
};