#include "lehrveranstaltung.h"
#include <iostream>
using namespace std;

lehrveranstaltung::lehrveranstaltung(void){
	
	cout << "Bezeichnung \t = ? ";
	cin >> bezeichnung;
	bezeichnung[29] = '\0';

	cout << "Wochentag (Mo/Di/Mi/Do/Fr) = ? ";
	cin >> wochentag;
	wochentag[29] = '\0';

	cout << "Raumnummer \t\t = ? ";
	cin >> raumnummer;

	cout << "Uhrzeit: von-bis \t = ? ";
	cin >> uhrzeit;
	uhrzeit[29] = '\0';

};

void lehrveranstaltung::anzeige(){
	cout << bezeichnung << endl;
	cout << wochentag << " in " << raumnummer << endl;
	cout << "Uhrzeit: " << uhrzeit << endl;
};