// Datum: 30.05.2014

// Obviously doesnt compile yet, cause it misses the whole main function,
// will be done by tuesday
#include "newhash.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(){

	newhash* my_hash = new newhash(10);

	int index = 0;
	int input = 0;
	int position = 0;

	cout << "Kollisionsstrategie wählen: " << endl;
	cout << "1: Lineares Sondieren" << endl;
	cout << "2: Quadratisches Sondieren" << endl;
	cout << "3: Doppeltes hashen" << endl;

	cin >> index;

	while (input != -1) {
		cout << "Einzufuegender Schluessel: " << endl;
		cin >> input;
		if (input > 0){
			position = my_hash->insert(input, index);
			cout << "Hash-Wert: " << position << endl;
			if (my_hash->allocation() > 0.7){
				cout << "Rehashing benoetigt!" << endl;
				my_hash->rehash(index);
			}
		}
	}

	delete my_hash;

	// --- Aufgabe 6 --- //

	cout << endl << "Starte Aufgabe 6" << endl;
	int size = 200;

	newhash* test_hash = new newhash(5);

	srand ((unsigned int) time (NULL));
	cout << "Seed fuer rand() gesetzt" << endl;

	vector<int> zufall;
	int rehash_counter = 0;

	cout << "Bestuecke Vector mit Zufallszahlen" << endl;
	for (int i = 1; i<size; i++){
		zufall.push_back( rand()% 100 + 1100 );
	};
	cout << "Vector mit Zufallszahlen bestueckt" << endl;

	cout << "Starte einfuegen der Zufallszahlen in die Hash Liste" << endl;
	while (zufall.size() > 0){
		test_hash->insert(zufall.back(), index);
		zufall.pop_back();
		if (test_hash->allocation() > 0.7){
			cout << "Rehashing benoetigt " << test_hash->rehash(index) << endl;
			//test_hash->rehash(index);
			rehash_counter++;
		};
	}
	cout << "Einfuegen beendet" << endl;

	cout << "Es musste " << rehash_counter << "mal gerehashed werden" << endl;
	cout << "Es gab " << test_hash->get_collisions() << " kollisionen" << endl;

	delete test_hash;

	system("pause");
	return 0;

}