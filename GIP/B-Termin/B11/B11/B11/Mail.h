#pragma once
#include "Address.h";
//using namespace std;

class Mail {
protected:
	unsigned long id;
	Address from;
	Address to;
	bool delivered;

public:
	Mail();
	Mail(unsigned long i);
	Mail(unsigned long i, const Address& adrTo, const Address& adrFrom);
	unsigned long getID();
	const Address& getFrom();
	const Address& getTo();
	bool setFrom(const Address& adr);
	bool setTo(const Address& adr);
	bool deliver();
	bool isDeliverd();
	bool scanFrom();
	bool scanTo();
	ostream& print(ostream& os);
};

ostream& operator << (ostream& os, Mail m);