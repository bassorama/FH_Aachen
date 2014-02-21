#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ifstream input;
	ofstream output;

	output.open("zahlen.txt", ios::out);

	float float_tmp = 0.0;

	cout << "Zahl 1 = ? ";
	cin >> float_tmp;

	output << float_tmp << endl;

	cout << "zahl 2 = ? ";
	cin >> float_tmp;

	output << float_tmp << endl;

	output.close();

	input.open("zahlen.txt", ios::in);

	if (input.fail()){
		cout << "Fehler beim Oeffnen der Datei zahlen.txt!" << endl;
		system("PAUSE");
		return -1;
	}

	cout << "Zahlen gelesen aus Datei zahlen.txt:" << endl;
	input >> float_tmp;

	while(!input.eof()){
		if (input.fail()){
			cout << "Fehler beim lesen in Datei zahlen.txt!" << endl;
			system("PAUSE");
			return -1;
		} else {
			cout << float_tmp << endl;
		}
		input >> float_tmp;
	}
	
	system("PAUSE");
	return 0;
}