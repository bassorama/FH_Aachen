#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	string input;
	cout << "Input test phrase = ";
	getline(cin, input);

	cout << "Some test:" << endl;

	cout << input[input.length()-1] << endl;
	cout << char(toupper(input[0])) << endl;

	system("PAUSE");

	return 0;
}