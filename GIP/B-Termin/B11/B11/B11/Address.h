#pragma once
#include <string>
using namespace std;

class Address
{
	string name;
	string street;
	string city;
	string country;

public:
	Address();
	Address(const string& n, const string& s, const string& ci, const string& co="Deutschland");
	const string& getName() const;
	bool isValid() const;
	bool scan();
	ostream& print(ostream& os);
};

ostream& operator << (ostream& os, Address adr);