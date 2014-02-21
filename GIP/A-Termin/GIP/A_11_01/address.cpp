#include "address.h"

address::address(){
	name = "";
	street = "";
	city = "";
	country = "";
};

address::address(const string& n, const string& s, const string& ci, const string& co="Deutschland"){
	name = n;
	street = s;
	city = ci;
	country = co;
};

const string& address::getName() const {
	return name;
};

bool address::isValid(){
	bool is_valid = true;

	if (name.length() == 0)
		is_valid = false;

	if (street.length() == 0)
		is_valid = false;

	if (city.length() == 0)
		is_valid = false;

	return is_valid;
};

bool address::scan(){
	string tmp_name, tmp_street, tmp_city, tmp_country;

	cout << "Nachname, Vorname\t: ";
	getline(cin, tmp_name);

	cout << "Strasse mit Hausnr.\t: ";
	getline(cin, tmp_street);

	cout << "Postleitzahl Stadt\t: ";
	getline(cin, tmp_city);

	cout << "Land\t: ";
	getline(cin, tmp_country);

	if (tmp_name.length() == 0 || tmp_street.length() == 0 || tmp_city.length() == 0 ){
		return false;
	} else {
		name = tmp_name;
		street = tmp_street;
		city = tmp_city;

		if (tmp_country.length() == 0)
			country = "Deutschland";
		else
			country = tmp_country;
		return true;
	}
}

ostream& address::print(ostream& os){
	os << endl << name << endl << street << endl << city << endl << country << endl;
	return os;
};
