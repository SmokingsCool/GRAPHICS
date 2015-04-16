

class Square{
	protected:
		float bottom;
		float left;
		float width;
		char color;

	public:
		void Display();
		Square(float newBot, float newLeft, float newwidth);
		void Color(char);
		void setColor();
		void updateCoord(float,float);



};