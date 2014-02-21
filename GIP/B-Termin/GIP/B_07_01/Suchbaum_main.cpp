#include <iostream>
#include "suchbaum.h"
using namespace std;
using namespace suchbaum;

int main(){
	int input = 0;
	TreeNode *root = 0;

	output(root, 0);

	do {
		cout << "Naechster Wert (99 Beendet)?";
		cin >> input;
		if (input != 99) {
				insert(root, input);
		}
	} while(input != 99);

	output(root, 0);

	system("PAUSE");
	return 0;
}