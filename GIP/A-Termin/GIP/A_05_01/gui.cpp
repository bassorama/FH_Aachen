#pragma once;
#include <iostream>
#include "calc.h"
using namespace calc;

namespace gui {
	void input_numbers(){
		int dezi_a = 0;
		int einer_a = 0;

		int dezi_b = 0;
		int einer_b = 0;

		char operation;

		std::cout << "Geben Sie die erste Ziffer der ersten Zahl ein: ";
		std::cin >> dezi_a;

		std::cout << "Geben Sie die zweite Ziffer der ersten Zahl ein: ";
		std::cin >> einer_a;

		std::cout << "Geben Sie die erste Ziffer der zweiten Zahl ein: ";
		std::cin >> dezi_b;

		std::cout << "Geben Sie die zweite Ziffer der zweiten Zahl ein: ";
		std::cin >> einer_b;

		std::cout << "Geben Sie die Rechenoperation ein (+ oder -): ";
		std::cin >> operation;

		if (operation == '+')
			calculate(dezi_a, einer_a, dezi_b, einer_b, true);
		else if (operation == '-')
			calculate(dezi_a, einer_a, dezi_b, einer_b, false);

	}
}