#include <iostream>
using namespace std;

int main() {

	double input = 0;
	double output = 0;

	cout << "Bitte geben Sie die L�nge in Meter ein: ";
	cin >> input;

	output = (input*3.2808);

	cout << "Die L�nge in Fuss lautet: " << output << endl;

	system("PAUSE");

	return 0;

}