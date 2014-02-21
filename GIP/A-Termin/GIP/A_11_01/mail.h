#pragma once
#include "address.h"
#include <string>

using namespace std;

class mail {
	protected:
		unsigned long id;
		address from, to;
		bool delievered;
	public:
		mail(unsigned long i);
		mail(unsigned long i, const address& adrTo, const address& adrFrom);
		unsigned long getID();
		const address& getFrom();
		const address& getTo();
		bool setFrom(const address& adr);
		bool setTo(const address& adr);
		bool deliver();
		bool isDelievered();
		bool scanFrom();
		bool scanTo();
		ostream& print(ostream& os);
};

inline ostream& operator << (ostream& os, mail data){
	return data.print(os);
};