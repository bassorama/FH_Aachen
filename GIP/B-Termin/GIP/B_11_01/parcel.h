#include "mail.h"

class parcel : public mail{
	private:
		bool insured;
		float weight;
	public:
		parcel(unsigned long id, float w, bool ins=false);
		parcel(unsigned long id, float w, const address& adrTo, const address& adrFrom, bool ins=false);

		bool setInsured(bool ins);
		float getWeight();
		void setWeight(float w);
		bool isInsured();
		ostream& print(ostream& os);
}