#include "rgb_colour.h"
#include <iostream>
using namespace std;

int main(){
	// your_favourite mit copy_constructor erstellen
	rgb_colour weiss, tuerkis, gelb, magenta, my_favourite, your_favourite;

	tuerkis.set_colour(0, 255, 255);
	gelb.set_colour(255, 255, 0);
	magenta.set_colour(255, 0, 255);

	my_favourite.set_colour(255, 0, 0);

	cout << "Weiss:" << endl;
	weiss.display();
	cout << endl;

	cout << "Tuerkis:" << endl;
	tuerkis.display();
	cout << endl;

	cout << "Magenta:" << endl;
	magenta.display();
	cout << endl;

	cout << "Meine Lieblingsfarbe:" << endl;
	my_favourite.display();
	cout << endl;

	// Eigentlich mit Copy Constructor
	cout << "Deine Lieblingsfarbe?" << endl;
	
	if (your_favourite.chooseColour() == true)
		your_favourite.display();

	system("PAUSE");

	return 0;
}