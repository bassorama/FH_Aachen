#pragma once
#include <string>
#include "lehrveranstaltung.h"
using namespace std;

class uebung : public lehrveranstaltung{
	private:
		char gruppe[30];
	public:
		uebung();
		void anzeige();
};