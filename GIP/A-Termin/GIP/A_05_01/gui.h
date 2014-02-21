#pragma once;
#include <iostream>

namespace gui {

	void input_numbers();

	inline void printout(int dezi_out, int einer_out, char overflow){
		if (overflow == 'o'){
			std::cout << "Overflow!" << std::endl;
		} else {
			std::cout << "Ergebnis: " << dezi_out << einer_out << std::endl;
		}
	}

}