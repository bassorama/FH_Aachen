// Datum: 30.05.2014
#include <vector>

#pragma once
class newhash {

private:
	std::vector<int> hash_list;
	static const int prim[];
	int strategy;
	int collision;

public:
	newhash(int size);
	~newhash(void);

	int hashValue(int key, int index);
	int insert(int key, int index);

	float allocation();

	int rehash(int index);

	int get_collisions();
};

