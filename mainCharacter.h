class mainCharacter{
	protected:
		int screenWidth;
		int screenHeight;

	public:
		mainCharacter(int,int);
		void Render();
		bool Intersects(float,float,float,float);

};