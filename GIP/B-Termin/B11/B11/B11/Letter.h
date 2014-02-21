#pragma once
#include <iostream>;
#include "Mail.h"

class Letter : public Mail
{
public:
	enum Category {STANDARD, EXPRESS};

private:
	Category ctg;

public:
	Letter(unsigned long id, Category c=STANDARD);
	Letter(unsigned long id, const Address& adrTo, const Address& adrFrom, Category c=STANDARD);
	void setCategory(Category c);
	Category getCategory();
	ostream& print(ostream& os);
};

ostream& operator << (ostream& os, Letter l);