#include "uebung.h"
#include <iostream>
using namespace std;

uebung::uebung(void){

	cout << "Gruppe = ? ";
	cin >> gruppe;
	gruppe[29] = '\0';
};

void uebung::anzeige(){
	cout << endl << " -- Anzeige Uebung -- " << endl;

	lehrveranstaltung::anzeige();

	cout << "Gruppe: " << gruppe << endl;
};