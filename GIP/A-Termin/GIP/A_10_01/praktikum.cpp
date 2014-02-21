#include "praktikum.h"
#include <iostream>
using namespace std;

praktikum::praktikum(void){
	
	cout << "Betreuer = ?";
	cin >> betreuer;
	betreuer[29] = '\0';
	
};

void praktikum::anzeige(){
	cout << endl << " -- Anzeige Praktikum -- " << endl;

	lehrveranstaltung::anzeige();

	cout << "Betreuer: " << betreuer << endl;

};