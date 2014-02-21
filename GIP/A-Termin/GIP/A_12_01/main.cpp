#include <fstream>
#include <iostream>
using namespace std;

int main(){
	int tmp_in = 0;
	char input_file [50];
	char output_file [50];

	cout << "Einlesen: Dateiname = ?";
	cin >> input_file;

	cout << "Ausgabe: Dateiname = ?";
	cin >> output_file;

	ifstream input;
	input.open(input_file, ios::in | ios::binary);

	ofstream output;
	output.open(output_file, ios::out | ios::binary);

	cout << endl;

	while (!input.eof()){
		tmp_in = input.get();
		if (tmp_in >= 97 && tmp_in <= 122){
			tmp_in -= 32;
			cout << char(tmp_in);
			output.put(tmp_in);
		} else {
			cout << char(tmp_in);
			output.put(tmp_in);
		}
	}

	input.close();
	output.close();

	system("PAUSE");

	return 0;
}