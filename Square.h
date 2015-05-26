#include <Windows.h>
#include "Image_Loading\nvImage.h"
#include <string>
using namespace std;

class Square{
	protected:
		float bottom;
		float left;
		float width;
		char color;
		GLuint thisTexture;
		int type;
		bool deleted;
		float origBot;
		float origLeft;
	public:
		float getOrigBottom();
		float getOrigLeft();
		void setType(int);
		void Display();
		Square(float newBot, float newLeft, float newwidth);
		void Color(char);
		void setColor();
		void updateCoord(float,float);
		GLuint loadPNG(char*);
		void setDeleted(bool);
		int getType();
		float getBottom();
		float getLeft();
};