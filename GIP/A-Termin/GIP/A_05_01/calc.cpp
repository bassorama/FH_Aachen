#pragma once;
#include "calc.h"
#include "gui.h"
using namespace gui;

namespace calc {
	void calculate(int dezi_a, int einer_a, int dezi_b, int einer_b, bool addition){
		int einer_out = 0;
		int dezi_out = 0;
	
		if (addition) {
			if ((einer_a + einer_b) > 9){
				einer_out = ( (einer_a + einer_b) - 10 );
				dezi_out = ((dezi_a + dezi_b)+1);

				if (dezi_out > 9) {
					printout(dezi_out, einer_out, overflow_char);
					//return;
				} else {
					printout(dezi_out, einer_out, 'c');
					//return;
				}
			} else {
				einer_out = einer_a + einer_b;
				dezi_out = dezi_a + dezi_b;

				if (dezi_out > 9) {
					printout(dezi_out, einer_out, overflow_char);
				} else {
					printout(dezi_out, einer_out, 'c');
				}
			}
		} else {
			if (einer_b > einer_a) {
				einer_out = (10 - (einer_b - einer_a));
				dezi_out = ((dezi_a - dezi_b)-1);
				printout(dezi_out, einer_out, 'c');
			} else {
				einer_out = (einer_a - einer_b);
				dezi_out = (dezi_a - dezi_b);
				printout(dezi_out, einer_out, 'c');
			}
		}
	}
}