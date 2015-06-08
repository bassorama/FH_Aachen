// Datum: 11.04.2014
#pragma once
class treenode
{
public:
	int data;
	treenode* left;
	treenode* right;
	treenode* parent;
	bool red;

	treenode(void);
	~treenode(void);

};

