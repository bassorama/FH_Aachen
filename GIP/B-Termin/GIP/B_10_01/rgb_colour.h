#pragma once

class rgb_colour{
	private:
		unsigned char red;
		unsigned char green;
		unsigned char blue;
	public:
		rgb_colour(void);
		rgb_colour(rgb_colour &my_colour);

		void set_colour(int red_data, int green_data,int blue_data);

		int getB();
		int getR();
		int getG();

		void display();
		bool chooseColour();
};