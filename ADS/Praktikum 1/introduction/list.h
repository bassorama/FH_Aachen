// Datum: 25.03.2014
#pragma once
#include "node.h"
#include <iostream>


class list{

public:
	node *head;

	list();
	~list(void);
	void insert(int input);
	bool pop(int input);
	int pop_smallest();
	bool search(int input);
	void output_list();
	bool empty();
	void merge_list(list *input1, list *input2);
};

