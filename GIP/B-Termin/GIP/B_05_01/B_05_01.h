#pragma once
#include <iostream>
#include<string>
using namespace std;

namespace parse_1 {
	void parse_gesamtausdruck(string &input, int pos);
	void parse_ausdruck(string &input, int pos);
	void parse_term(string &input, int pos);
	void parse_operand(string &input, int pos);
	void parse_number(string &input, int pos);
	void match(char c, string &input, int pos);
	bool expect(char c, string &input, int pos);
}