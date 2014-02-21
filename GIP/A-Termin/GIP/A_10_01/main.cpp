#include "vorlesung.h"
#include "uebung.h"
#include "praktikum.h"
#include "klausur.h"
#include <iostream>
using namespace std;

int main(){

	cout << "- Vorlesung GIP " << endl;
	vorlesung neue_vorlesung;
	cout << endl;
	neue_vorlesung.anzeige();

	cout << endl << "- Uebung GIP " << endl;
	uebung neue_uebung;
	cout << endl;
	neue_uebung.anzeige();

	cout << endl << "- Praktikum GIP " << endl;
	praktikum neues_praktikum;
	cout << endl;
	neues_praktikum.anzeige();

	cout << endl << "- Klausur GIP " << endl;
	klausur neue_klausur;
	cout << endl;
	neue_klausur.anzeige();	

	cout << endl;

	system("PAUSE");
	return 0;
}