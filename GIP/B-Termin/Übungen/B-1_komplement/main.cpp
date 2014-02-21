#include <iostream>
#include <string>
using namespace std;


string convert(int input){
	int tmp = 128;
	string output = "";

	if (input >= tmp){
		output += "1";
		input -= 128;
		tmp = 64;
	} else {
		output += "0";
		tmp = 64;
	}

	if (input >= tmp){
		output += "1";
		input -= 64;
		tmp = 32;
	} else {
		output += "0";
		tmp = 32;
	}

	if (input >= tmp){
		output += "1";
		input -= 32;
		tmp = 16;
	} else {
		output += "0";
		tmp = 16;
	}

	if (input >= tmp){
		output += "1";
		input -= 16;
		tmp = 8;
	} else {
		output += "0";
		tmp = 8;
	}

	if (input >= tmp){
		output += "1";
		input -= 8;
		tmp = 4;
	} else {
		output += "0";
		tmp = 4;
	}

	if (input >= tmp){
		output += "1";
		input -= 4;
		tmp = 2;
	} else {
		output += "0";
		tmp = 2;
	}

	if (input >= tmp){
		output += "1";
		input -= 2;
		tmp = 1;
	} else {
		output += "0";
		tmp = 1;
	}

	if (input >= tmp){
		output += "1";
		input -= 1;
		tmp = 0;
	} else {
		output += "0";
		tmp = 0;
	}

	return output;
};

string complement(string dual){
	string output = "";
	for (int i = 0; i <= 7; i++){
		if (dual[i] == '0'){
			output += "1";
		}
		if (dual[i] == '1'){
			output += "0";
		}
	}

	return output;
};

int main(){
	int decimal = 0;
	string binary = "";

	for(;;){

		do {
			cout << "Dezimalzahl:";
			cin >> decimal;
		} while( decimal > 128 || decimal < -128);

		if(decimal == 0)
			break;

		binary = convert(decimal);

		if (decimal > 0){
			cout << "Dualzahl: " << binary << endl;
			cout << "B-1 Komplement: " << complement(binary) << endl << endl;
		};
		if (decimal < 0){
			cout << "Dualzahl: " << complement(binary) << endl;
			cout << "B-1 Komplement: " << binary << endl << endl;		
		}
	}

	system("PAUSE");
	return 0;

}