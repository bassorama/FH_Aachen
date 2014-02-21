#pragma once
#include <iostream>;
#include "Mail.h"

class Parcel : public Mail
{
	bool insured;
	float weight;

public:
	Parcel(unsigned long id, float w, bool ins=false);
	Parcel(unsigned long id, float w, const Address& adrTo, const Address& adrFrom, bool ins=false);
	void setInsured(bool ins);
	bool isInsured();
	void setWeight(float w);
	float getWeight();
	ostream& print(ostream& os);
};

ostream& operator << (ostream& os, Parcel p);
