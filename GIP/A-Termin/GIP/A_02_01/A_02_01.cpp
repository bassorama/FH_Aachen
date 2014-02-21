#include <iostream>
using namespace std;

int main() {

	char c1 = '\n';
	char c2 = '\t';
	char c3 = '\x07';
	char c4 = '\"';
	char c5 = '\'';
	char c6 = 'a';
	char c7 = 'z';


	cout << "Newline: " << c1 << endl;
	cout << "Tab: " << c2 << endl;
	cout << "Bell: " << c3 << endl;
	cout << "Doppeltes Hochkomma: " << c4 << endl;
	cout << "Einfaches Hochkomma: " << c5 << endl;
	cout << "a: " << c6 << endl;
	cout << "z: " << c7 << endl;

	cout << endl;

	cout << "Newline: " << int(c1) << endl;
	cout << "Tab: " << int(c2) << endl;
	cout << "Bell: " << int(c3) << endl;
	cout << "Doppeltes Hochkomma: " << int(c4) << endl;
	cout << "Einfaches Hochkomma: " << int(c5) << endl;
	cout << "a: " << int(c6) << endl;
	cout << "z: " << int(c7) << endl;

	cout << endl;

	int i1 = int(c1);
	int i2 = int(c2);
	int i3 = int(c3);
	int i4 = int(c4);
	int i5 = int(c5);
	int i6 = int(c6);
	int i7 = int(c7);

	cout << "Newline: " << char(i1) << endl;
	cout << "Tab: " << char(i2) << endl;
	cout << "Bell: " << char(i3) << endl;
	cout << "Doppeltes Hochkomma: " << char(i4) << endl;
	cout << "Einfaches Hochkomma: " << char(i5) << endl;
	cout << "a: " << char(i6) << endl;
	cout << "z: " << char(i7) << endl;

	system("PAUSE");

	return 0;
}