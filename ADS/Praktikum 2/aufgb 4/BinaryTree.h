// Datum: 11.04.2014
#pragma once
#include "treenode.h"

class BinaryTree
{
public:

	treenode* head;
	treenode* root;

	BinaryTree(void);
	~BinaryTree(void);

	bool insert(int);
	bool find(treenode* &, treenode* &, int);
	bool pop(int);
	int find_max(treenode* &, treenode* &);
	int find_min(treenode* &, treenode* &);
	void preorder(treenode* &);
	void postorder(treenode* &);
	void inorder(treenode* &);
	void levelorder(treenode* &);
	void printlevel(treenode*&, int, int);
};

