#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	long float input[100];
	int number = 0;
	long float mittel = 0, tmp = 0;

	for(int i = 0; i < 99; i++){
		input[i] = 0;
	};

	cout << "Anzahl der Werte = ? ";
	cin >> number;

	for(int x = 0; x < number; x++){
		cout << "Wert Nr. " << x+1 << " = ? ";
		cin >> input[x];
		mittel += input[x];
	};

	mittel = (mittel / number);

	cout << setprecision (8);
	cout << "Mittelwert = " << mittel << endl;

	for(int x = 0; x < number; x++){
		if (input[x] > mittel)
			tmp++;
	};

	cout << tmp << " Werte liegen ueber dem Mittelwert." << endl;

	system("PAUSE");

	return 0;

}