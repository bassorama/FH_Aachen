#include <iostream>
using namespace std;

int main(){

	double input = 0;
	double output = 0;

	cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ";
	cin >> input;

	output = (input*1.8) + 32;

	cout << "Die Temperatur in Farenheit lautet: " << output << endl;

	system("PAUSE");

	return 0;

}