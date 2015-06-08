// Datum: 26.03.2014
#include "node.h"
#include "deque.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	
	deque *my_list = new deque;
	
	// Aufgabe g.1
	my_list->empty();

	// Aufgabe g.2
	for (int i=1; i<=10; i++){
		my_list->push_back(i);
	}
	my_list->print();

	// Aufgabe g.3
	for (int i=11; i<=15; i++){
		my_list->push_front(i);
	}
	my_list->print();

	// Aufgabe g.4
	my_list->get_front();
	my_list->get_back();

	// Aufgabe g.5
	std::cout << "Elemente in der Liste: " << my_list->size() << std::endl;

	// Aufgabe g.6
	my_list->pop_front();
	my_list->pop_front();

	// Aufgabe g.7
	my_list->print();

	// Aufgabe g.8
	my_list->pop_back();
	my_list->pop_back();

	// Aufgabe g.9
	my_list->print();

	// Aufgabe g.10
	my_list->find(5);

	// Aufgabe g.11
	while (my_list->size() != 0) {
		my_list->pop_front();
	}
	my_list->empty();


	
	system("PAUSE");
	return 0;
};
