#include <iostream>
#include "Mail.h"

using namespace std;

Mail::Mail(){
	delivered = false;
}

Mail::Mail(unsigned long i){
	id = i;
	delivered = false;
}

Mail::Mail(unsigned long i, const Address& adrTo, const Address& adrFrom){
	id = i;
	to = adrTo;
	from = adrFrom;
	delivered = false;
}

unsigned long Mail::getID(){
	return id;
}

const Address& Mail::getFrom(){
	return from;
}

const Address& Mail::getTo(){
	return to;
}

bool Mail::setFrom(const Address& adr){
	if(adr.isValid())	{
		from = adr;
		return true;
	} else {
		return false;
	}
}

bool Mail::setTo(const Address& adr){
	if(adr.isValid()) {
		to = adr;
		return true;
	} else {
		return false;
	}
}

bool Mail::deliver() {
	if(to.isValid()) {
		delivered = true;
		return true;
	} else {
		return false;
	}
}

bool Mail::isDeliverd(){
	return delivered;
}

bool Mail::scanFrom(){
	return from.scan();
}

bool Mail::scanTo(){
	return to.scan();
}

ostream& Mail::print(ostream& os) {
	os << "Mail-ID: " << id << endl;

	if(from.isValid())
		os << "Absender:" << endl << from << endl;
	else
		os << "Kein gueltiger Absender!" << endl;
		
	if(to.isValid())
		os << "Empfaenger:" << endl << to <<endl;
	else
		os << "Kein gueltiger Empfaenger!" << endl;

	if(!delivered)
		os << "Post wurde noch nicht ausgeliefert!" << endl;
	
	return os;
}

ostream& operator << (ostream& os, Mail m){
	return m.print(os);
}