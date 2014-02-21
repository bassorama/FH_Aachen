#include "vorlesung.h"
#include <iostream>
using namespace std;

void vorlesung::anzeige(){
	cout << endl << " -- Anzeige Vorlesung -- " << endl;
	lehrveranstaltung::anzeige();
};
