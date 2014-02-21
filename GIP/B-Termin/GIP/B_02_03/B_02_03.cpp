#include <iostream>
using namespace std;

int main() {
	double input = 0;
	double output = 0;

	cout << "Bitte geben Sie die Geldmenge in Euro ein: ";
	cin >> input;

	output = input*1.2957;

	cout << "Die Geldmenge in Dollar lautet: " << output << endl;

	system("PAUSE");

	return 0;

}