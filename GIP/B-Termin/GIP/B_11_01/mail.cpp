#include "mail.h"
#include <iostream>

mail::mail(unsigned long i){
	id = i;
	delievered = false;
};

mail::mail(unsigned long i, const address& adrTo, const address& adrFrom){
	id = i;
	delievered = false;

	from = adrFrom;
	to = adrTo;
};

unsigned long mail::getID(){
	return id;
};

const address& mail::getFrom(){
	return from;
};

const address& mail::getTo(){
	return to;
};

bool mail::setFrom(const address& adr){
	from = adr;
	return true;
};

bool mail::setTo(const address& adr){
	to = adr;
	return true;
};

bool  mail::deliver(){
	if (delievered == false){
		if (to.isValid() == true){
			delievered = true;
			return true;
		} else {
			return false;		
		}
	} else {
		return false;
	}
};

bool mail::isDelievered(){
	return delievered;
};

bool mail::scanFrom(){
	return from.scan();
};

bool mail::scanTo(){
	return to.scan();
};

ostream& mail::print(ostream& os){
	os << endl << "Mail-ID: " << getID() << endl;
	os << "Absender: " << getFrom() << endl;
	os << "Empfaenger: " << getTo() << endl;
	return os;
};