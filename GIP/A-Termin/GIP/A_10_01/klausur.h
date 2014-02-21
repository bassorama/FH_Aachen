#pragma once
#include <string>
#include "lehrveranstaltung.h"
using namespace std;

class klausur : public lehrveranstaltung{
	private:
		int anzahlteilnehmer;
		char datum[30];

	public:
		klausur();
		void anzeige();
};