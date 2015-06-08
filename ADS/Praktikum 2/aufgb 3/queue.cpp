// Datum: 10.04.2014
#include "queue.h"
#include<iostream>

// Constructor
queue::queue(const int elements) {
	size = elements+1;
	data = new int[size];
	for (int i=0; i<=size;i++){
		data[i] = 0;
	}
	L = size-1;
	S = 0;
}

// Destructor
queue::~queue(void) {
	
}

// inserts an item into the queue, if the queue is full
// an error will be written to console
void queue::Push(int item) {
	if (isFull() != true) {
		data[S] = item;
		S = (S+1)%size;
		return;
	} else {
		std::cout << "Queue ist voll!" << std::endl;
		return;
	}
}

// reads an item from the queue and deletes it. The item
// is returned as int. If the queue is empty an error will
// be written to console
int queue::Pop(){
	if (isEmpty() != true) {
		L = (L+1)%size;
		int output = data[L];
		data[L] = 0;
		return output;
	} else {
		std::cout << "Queue ist leer!" << std::endl;
		return -1;
	}
}

// Writes all current elements of the queue to console
// except any 0
void queue::Output() {
	for (int i=0; i<=size;i++){
		if (data[i] != 0)
			std::cout << data[i];
	}
	std::cout << std::endl;
}

// checks whether the queue is full, returns a boolean
bool queue::isFull() {
	if (S==L){
		return true;
	} else {
		return false;
	}
}

// checks whether the queue is empty, returns a boolean
bool queue::isEmpty() {
	if ( S == (L+1)%size ){
		return true;
	} else {
		return false;
	}
}