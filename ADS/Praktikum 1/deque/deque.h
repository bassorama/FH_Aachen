// Datum: 26.03.2014
#pragma once
#include "node.h"

class deque{
public:
	node *head;
	node *tail;

	deque(void);
	~deque(void);

	void push_front(int input);
	void push_back(int input);
	int get_front();
	int get_back();
	void pop_front();
	void pop_back();
	bool find(int input);
	bool empty();
	int size();
	void print();
};

