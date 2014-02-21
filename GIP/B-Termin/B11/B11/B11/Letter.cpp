#include "Letter.h"

Letter::Letter(unsigned long id, Category c){
	this->id = id;
	ctg = c;
}

Letter::Letter(unsigned long id, const Address& adrTo, const Address& adrFrom, Category c){
	this->id = id;
	this->to = adrTo;
	this->from = adrFrom;
	ctg = c;
}

void Letter::setCategory(Category c){
	ctg = c;
}

Letter::Category Letter::getCategory(){
	return ctg;
}

ostream& Letter::print(ostream& os){
	os << "--- Brief-Daten ---" << std::endl;
	os << "Kategorie: ";

	if(ctg == EXPRESS)
		os << "Express" << std::endl; 
	else
		os << "Standard" << std::endl; 

	Mail::print(os);

	return os;
}

ostream& operator << (ostream& os, Letter l){
	return l.print(os);
}