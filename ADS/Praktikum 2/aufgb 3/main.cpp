// Datum: 10.04.2014
#include "queue.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	int input = 0;
	int size = 0;
	int item = 0;

	cout << "Wieviele Elemente soll die Queue aufnehmen koennen? ";
	cin >> size;
	cout << endl;

	queue my_queue = queue(size);

	while(input != 4) {
		cout << "1: Element einfuegen" << endl;
		cout << "2: Element entnehmen" << endl;
		cout << "3: Ausgabe aller Element in der Queue" << endl;
		cout << "4: Beenden" << endl;

		cin >> input;

		switch(input) {
			case 1:
				cout << "Einzufuegendes Element eingeben: ";
				cin >> item;
				my_queue.Push(item);
				break;
			case 2:
				cout << "Erstes Element ausgeben: " << my_queue.Pop() << endl;
				break;
			case 3:
				my_queue.Output();
				cout << endl;
				break;
			case 4:
				break;
			default:
				cout << "Waehlen Sie 1,2,3 oder 4!" << endl;
				break;
		}
	}

	my_queue.~queue();

	system("PAUSE");
	return 1;
}