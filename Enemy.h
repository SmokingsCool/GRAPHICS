#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>
#include "Image_Loading\nvImage.h"
using namespace std;
class Enemy{
	protected:
		int screenWidth;
		int screenHeight;
		float gravityincrement;
		float bottom;
		float left;
		float origBot;
		float Height;
		float origLeft;
		float Width;
		float enemyMinX;
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
		float xAdj;
		float yAdj;
		float directionMod;
	public:
		string getDirection();
		void throwProj();
		void setTexture(string);
		Enemy(int,int,float,float);
		Enemy();
		void Render();
		vector<float> IntersectsIntraverse(float,float,float,float);
		bool Intersects(float,float,float,float);
		void jump();
		void gravityCheck();
		float getxVel();
		float getyVel();
		void SetXAdj(float );
		void SetYAdj(float );
		void changexVel(float);
		void xDecay();
		void newIteration();
		GLuint loadPNG(char*);
		void updateDirection(float );
};