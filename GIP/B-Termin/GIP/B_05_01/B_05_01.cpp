#pragma once
#include <iostream>
#include<string>
using namespace std;
//#include "B_05_01.h"

void parse_gesamtausdruck(string &, int &);
void parse_ausdruck(string &, int &);
void parse_term(string &, int &);
void parse_operand(string &, int &);
void parse_number(string &, int&);
void match(char, string &, int &);
bool expect(char, string &, int );

bool expect(char c, string &input, int pos){
	cout << "Teste auf das Zeichen " << c << endl;
	if (unsigned(pos) >= input.length()) {
		cout << "Aber schon am Ende der Eingabe-Zeichenkette angelengt." << endl;
		return false;
	}
	if (input.at(pos) == c) {
		cout << "Zeichen " << c << " gefunden." << endl;
		return true;
	} else {
		cout << "Test auf " << c << " nicht erfolgreich. Stattdessen " << input.at(pos) << " gesehen." << endl;
		return false;
	}
}

void match(char c, string &input, int &pos){
	cout << "Betrete match() fuer das Zeichen " << c << endl;
	if (unsigned(pos) >= input.length()){
		cout << "Input-Zeichenkette zu kurz. Erwarte noch das Zeichen " << c << endl;
		cout << "Verlasse match(): " << endl;
		return;
	}
	if (input.at(pos) != c) {
		cout << "Fehler: an Position " << pos << " erwarte " << c << " und sehe " << input.at(pos) << endl;
		cout << "Verlasse match(): " << endl;
		return;
	}
	pos++;
	cout << "Zeichen " << c << " konsumiert." << endl;
	cout << "Verlasse mathc() fuer das Zeichen " << c << endl;
}

void parse_number(string &input, int &pos){
	cout << "Betrete parse_number()" << endl;
	if (expect('1', input, pos)){
		match('1', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('2', input, pos)) {
		match('2', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('3', input, pos)) {
		match('4', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('5', input, pos)) {
		match('5', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('6', input, pos)) {
		match('6', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('7', input, pos)) {
		match('7', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('8', input, pos)) {
		match('8', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('9', input, pos)) {
		match('9', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	} else if (expect('0', input, pos)) {
		match('0', input, pos);
		cout << "Verlasse parse_number()" << endl;
		return;
	}
}

void parse_operand(string &input, int &pos){
	cout << "Betrete parse_operand()" << endl;
	int tmp_char[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i=0; i<=9;i++) {
		if (expect(tmp_char[i], input, pos)) {
			match(tmp_char[i], input, pos);
			parse_number(input, pos);
			cout << "Verlasse parse_operand()" << endl;
			//return;
		}
	}
	if (expect('(', input, pos)) {
		match('(', input, pos);
		parse_ausdruck(input, pos);
		cout << "Verlasse parse_operand()" << endl;
		return;
	}
	if (expect(')', input, pos)) {
		match(')', input, pos);
		cout << "Verlasse parse_operand()" << endl;
		return;
	} 

}

void parse_term(string &input, int &pos){
	parse_operand(input, pos);
	while (expect('>', input, pos) || expect('<', input, pos)){
		if (expect('>', input, pos)) {
			cout << "Betrete parse_term(): > Fall" << endl;
			match('>', input, pos);
			parse_operand(input, pos);
			cout << "Verlasse parse_term(): > Fall" << endl;
			return;
		} else if (expect('<', input, pos)) {
			cout << "Betrete parse_term(): < Fall" << endl;
			match('<', input, pos);
			parse_operand(input, pos);
			cout << "Verlasse parse_term(): > Fall" << endl;
			return;
		}
	}
}

void parse_ausdruck(string &input, int &pos){
	parse_term(input, pos);
	while (expect('U', input, pos) || expect('O', input, pos)){
		if (expect('U', input, pos) ) {
			cout << "Betrete parse_ausdruck(): U Fall" << endl;
			match('U', input, pos);
			parse_ausdruck(input, pos);
			cout << "Verlasse parse_ausdruck(): U Fall" << endl;
			return;
		} else if (expect('O', input, pos)){
			cout << "Betrete parse_ausdruck(): O Fall" << endl;
			match('O', input, pos);
			parse_ausdruck(input, pos);
			cout << "Verlasse parse_ausdruck(): O Fall" << endl;
			return;
		}
	}
}

void parse_gesamtausdruck(string &input, int &pos){
	cout << "Betrete parse_gesamtausdruck()" << endl;
	parse_ausdruck(input, pos);
	if (expect( '.', input, pos)){
		match('.', input, pos);
		cout << "Verlasse parse_gesamtausdruck()" << endl;
		return;
	}
}

int main(){
	int pos = 0;
	string input;
	cout << "Bitte geben Sie die Zeichenkette ein: " ;
	getline(cin, input);
	parse_gesamtausdruck(input, pos);
	if (pos != input.length()){
		cout << "Error! Noch Input-Zeichen uebrig." << endl;
	}
	system("PAUSE");
	return 0;
}