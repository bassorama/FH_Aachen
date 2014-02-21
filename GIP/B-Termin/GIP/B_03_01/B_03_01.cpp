#include<iostream>
#include<string>
using namespace std;

int main(){

	int input = 0;
	string output = "";

	cout << "Bitte geben Sie Ihre Dezimalzahl zwischen 1 und 3999 ein: ";
	cin >> input;

	if ((input > 3999) || (input <= 0)) {
		cout << "Die eingegebene Zahl liegt nicht zwischen 1 und 3999." << endl;
		system("PAUSE");
		return -1;
	}

	// M = 1000
	if (input >= 1000){
		while (input >= 1000) {
			output = output+"M";
			input -= 1000;
		}
	}

	// C = 500
	if (input >= 500) {
		if (input >= 900) {
			output = output + "CM";
			input -= 900;
		}
		while (input >= 500) {
			output = output+"D";
			input -= 500;
		}
	} 

	// D = 100
	if (input >= 100) {
		if (input >= 400) {
			output = output + "CD";
			input -= 400;
		}
		while (input >= 100) {
			output = output+"C";
			input -= 100;
		}
	} 

	// L = 50
	if (input >= 50) {
		if (input >= 90){
			output = output + "XC";
			input -= 90;
		}
		while (input >= 50) {
			output = output+"L";
			input -= 50;
		}

	} 

	// X = 10
	if (input >= 10) {
		if (input >= 40) {
			output = output + "XL";
			input -= 40;
		}		
		while (input >= 10) {
			output = output+"X";
			input -= 10;
		}
	} 

	// V =5
	if (input >= 5) {
		if (input >= 9) {
			output = output + "IX";
			input -= 9;
		}
		while (input >= 5) {
			output = output+"V";
			input -= 5;
		}
	} 

	// I = 1
	if (input >= 1) {
		if (input >= 4) {
			output = output + "IV";
			input -= 4;
		}
		while (input >= 1) {
			output = output+"I";
			input -= 1;
		}
	}

	cout << "Die roemische Zahl lautet: " << output << endl;

	system("PAUSE");
	return 0;
}