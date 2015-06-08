// Datum: 10.04.2014
#pragma once
class queue
{
public:
	int* data;
	int L;
	int S;
	int size;

	queue(const int elements);
	~queue(void);

	void Push(int item);
	int Pop();

	void Output();

	bool isFull();
	bool isEmpty();
};

