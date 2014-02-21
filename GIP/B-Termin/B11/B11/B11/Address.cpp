#include <iostream>
#include "Address.h"

using namespace std;

Address::Address(){
	name = "";
	street = "";
	city = "";
	country = "";
}

Address::Address(const string& n, const string& s, const string& ci, const string& co) {
	name = n;
	street = s;
	city = ci;

	if(co == "")
		country = "Deutschland";
	else
		country = co;
}

const string& Address::getName() const {
	return name;
}

bool Address::isValid() const {
	if(name == "" || street == "" || city == "")
		return false;
	else
		return true;
}

bool Address::scan(){
	string tn = "", ts = "", tci = "", tco = "";
	cout << "Nachname, Vorname : \t";
	getline(cin,tn);

	cout << "Strasse mit Hausnr.: \t";
	getline(cin,ts);

	cout << "Postleitzahl Stadt : \t";
	getline(cin,tci);

	cout << "Land : \t";
	getline(cin,tco);


	if(tn == "" || ts == "" || tci == "") {
		return false;
	} else {
		name = tn;
		street = ts;
		city = tci;

		if(tco == "")
			country = "Deutschland";
		else
			country = tco;

		return true;
	}
}

ostream& Address::print(ostream& os){
	os << "\t\t" << name << endl;
	os << "\t\t" << street << endl;
	os << "\t\t" << city << endl;
	os << "\t\t" <<  country << endl;

	return os;
}

ostream& operator << (ostream& os, Address adr){
	return adr.print(os);
}