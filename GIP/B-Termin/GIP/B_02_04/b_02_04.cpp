#include <iostream>
using namespace std;

int main() {

	double input = 0;
	double output = 0;
	int choice = 0;

	cout << "Eingabe: ";
	cin >> input;

	cout << "Auswahl der Umwandlung:" << endl;
	cout << " 1 - Celsius in Farenheit" << endl;
	cout << " 2 - Meter in Fuss" << endl;
	cout << " 3 - Euro in US Dollar" << endl;

	cin >> choice;

	output = (((input*1.8) + 32)*((2-choice)*(3-choice))/2) + ((input*3.2808)*((1-choice)*(3-choice))*-1) + ((input*1.2957)*((2-choice)*(1-choice))/2);

	cout << "Das Ergebnis lautet: " << output << endl;

	system("PAUSE");

	return 0;
	
}