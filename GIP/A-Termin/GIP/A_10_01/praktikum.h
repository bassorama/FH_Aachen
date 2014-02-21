#pragma once
#include <string>
#include "lehrveranstaltung.h"
using namespace std;

class praktikum : public lehrveranstaltung{
	private:
		char betreuer[30];

	public:
		praktikum();
		void anzeige();
};