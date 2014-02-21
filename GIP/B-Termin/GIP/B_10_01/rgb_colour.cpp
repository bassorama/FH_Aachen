#include "rgb_colour.h"
#include <iostream>
#include <cstring>
using namespace std;

rgb_colour::rgb_colour(){
	red = unsigned char(0);
	green = unsigned char(0);
	blue = unsigned char(0);
};

rgb_colour::rgb_colour(rgb_colour &my_colour){
	set_colour(my_colour.getR(), my_colour.getG(), my_colour.getB());
};

void rgb_colour::set_colour(int red_data, int green_data,int blue_data){
	red = unsigned char(red_data);
	green = unsigned char(green_data);
	blue = unsigned char(blue_data);
};

int rgb_colour::getR(){
	return int(red);
};

int rgb_colour::getG(){
	return int(green);
};

int rgb_colour::getB(){
	return int(blue);
};

void rgb_colour::display(){
	cout << "rot : " << getR() << " green : " << getG() << " blue : " << getB() << endl;
};

bool rgb_colour::chooseColour(){
	int tmp_r = -1;
	int tmp_g = -1;
	int tmp_b = -1;

	cout << "rot (0,  , 255): ";
	cin >> tmp_r;
	if (tmp_r < 0 || tmp_r > 255){
		cout << "Falsche Eingabe!" << endl;
		return false;
	}

	cout << "gruen (0,  , 255): ";
	cin >> tmp_g;
	if (tmp_g < 0 || tmp_g > 255){
		cout << "Falsche Eingabe!" << endl;
		return false;
	}

	cout << "blau (0,  , 255): ";
	cin >> tmp_b;
	if (tmp_b < 0 || tmp_b > 255){
		cout << "Falsche Eingabe!" << endl;
		return false;
	}

	set_colour(tmp_r, tmp_g, tmp_b);

	return true;
	/*
	do {
		cout << "rot (0,  , 255): ";
		cin >> tmp_r;
		if (tmp_r < 0 || tmp_r > 255)
			cout << "Wert liegt nicht zwischen 0 und 255!" << endl;
	} while (tmp_r < 0 || tmp_r > 255);

	do {
		cout << "gruen (0,  , 255): ";
		cin >> tmp_g;
		if (tmp_g < 0 || tmp_g > 255)
			cout << "Wert liegt nicht zwischen 0 und 255!" << endl;
	} while (tmp_g < 0 || tmp_g > 255);

	do {
		cout << "blau (0,  , 255): ";
		cin >> tmp_b;
		if (tmp_b < 0 || tmp_b > 255)
			cout << "Wert liegt nicht zwischen 0 und 255!" << endl;
	} while (tmp_b < 0 || tmp_b > 255);
	*/


};
