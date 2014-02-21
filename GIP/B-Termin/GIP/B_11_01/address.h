#include <string>
#include <iostream>
using namespace std;

class address{
	private:
		string name, street, city, country;
	public:
		address();
		address(const string& n, const string& s, const string& ci, const string& co);
		const string& getName() const ;
		bool isValid();
		bool scan();
		ostream& print(ostream& os);
};

inline ostream& operator << (ostream& os, address data){
	return data.print(os);
};