#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>
#include "Image_Loading\nvImage.h"
using namespace std;
class mainCharacter{
	protected:
		int screenWidth;
		int screenHeight;
		float gravityincrement;
		float yVel;
		float xVel;
		bool resting;
		float xLimit;
		float gravityCounter;
		bool restingIterator;
		bool jumpB;
		bool dblJump;
		GLuint thisTexture;
		string direction;
	public:
		string getDirection();
		void throwProj();
		void setTexture(string);
		mainCharacter(int,int);
		mainCharacter();
		void Render();
		vector<float> IntersectsIntraverse(float,float,float,float);
		bool Intersects(float,float,float,float);
		void jump();
		void gravityCheck();
		float getxVel();
		float getyVel();
		void changexVel(float);
		void xDecay();
		void newIteration();
		GLuint loadPNG(char*);
};