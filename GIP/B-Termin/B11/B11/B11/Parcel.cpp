#include "Parcel.h"	

Parcel::Parcel(unsigned long id, float w, bool ins){
	this->id = id;
	weight = w;
	insured = ins;
}

Parcel::Parcel(unsigned long id, float w, const Address& adrTo, const Address& adrFrom, bool ins){
	this->id = id;
	this->to = adrTo;
	this->from = adrFrom;
	weight = w;
	insured = ins;
}

void Parcel::setInsured(bool ins){
	insured = ins;
}

bool Parcel::isInsured(){
	return insured;
}

void Parcel::setWeight(float w){
	weight = w;
}

float Parcel::getWeight(){
	return weight;
}

ostream& Parcel::print(ostream& os){
	os << "--- Paket-Daten ---" << endl;
	os << "Gewicht: " << weight << " / ";
		
	if(insured)
		os << "Versichert." << endl;
	else
		os << "Nicht versichert." << endl;
		
	Mail::print(os);

	return os;
}

ostream& operator << (ostream& os, Parcel p){
	return p.print(os);
}