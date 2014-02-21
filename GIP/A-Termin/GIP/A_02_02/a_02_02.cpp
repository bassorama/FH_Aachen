#include <iostream>
using namespace std;

int main() {

	char input = 0;

	cout << "Geben Sie Ihre Ziffer ein: ";
	cin >> input;
	// numbers start in the ascii table at position 48, so I got to substract 48 after the typecast
	input = int(input)-int('0');
	cout << "Der dreifache Wert Ihrer Ziffer lautet: " << input*3 << endl;

	system("PAUSE");

	return 0;

}