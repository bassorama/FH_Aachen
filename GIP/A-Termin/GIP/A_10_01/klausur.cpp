#include "klausur.h"
#include <iostream>
using namespace std;

klausur::klausur(void){

	cout << "Datum = ? ";
	cin >> datum;
	datum[29] = '\0';

	cout << "Teilnehmeranzahl = ? ";
	cin >> anzahlteilnehmer;
};

void klausur::anzeige(){
	cout << endl << " -- Anzeige Klausur -- " << endl;

	lehrveranstaltung::anzeige();

	cout << "Datum: " << datum << endl;
	cout << "Anzahl der Teilnehmer: " << anzahlteilnehmer << endl;
};