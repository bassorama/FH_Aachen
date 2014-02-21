#pragma once
//#include <string>
//using namespace std;

class lehrveranstaltung{
	protected:
		char bezeichnung[30];
		char uhrzeit[30];
		char wochentag[30];
		int raumnummer;

	public:
		lehrveranstaltung();
		void anzeige();
};