#include <iostream>
using namespace std;

int main() {

	int input;

	cout << "Bitte geben Sie ihre Studienrichtung an" << endl;
	
	cout << "1: Informatiker" << endl;
	cout << "2: Elektrotechniker" << endl;

	cin >> input;

	cout << "Ihre Eingabe lautete: " << input << endl;

	/*
	if (input > 2) {
	
		cout << "Ihre Eingabe ist Ungueltig" << endl;
	
	} else {
	
		if (input < 1) {

			cout << "Ihre Eingabe ist Ungueltig" << endl;

		} else {

		cout << "Alles okay!" << endl;
		
		}
	}
	*/

	system("PAUSE");

	return 0;


}