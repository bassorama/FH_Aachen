#include <string>
#include "mail.h"

class letter : public mail{
	public:
		enum Category{STANDARD, EXPRESS};
	private:
		Category ctg;

	public:
		letter(unsigned long id, Category c=STANDARD);
		letter(unsigned long id, const address& adrTo, const address& adrFrom, Category c=STANDARD);
		void setCategory(Category c);
		Category getCategory();
		ostream& print(ostream& os);
};