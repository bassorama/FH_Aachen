#include <iostream>
using namespace std;

int main() {

	double input = 0;
	double output = 0;

	cout << "Bitte geben Sie die Länge in Meter ein: ";
	cin >> input;

	output = (input*3.2808);

	cout << "Die Länge in Fuss lautet: " << output << endl;

	system("PAUSE");

	return 0;

}