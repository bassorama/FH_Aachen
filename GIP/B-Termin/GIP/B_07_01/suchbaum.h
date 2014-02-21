#include<iostream>
using namespace std;

namespace suchbaum {

	struct TreeNode{
		int data;
		TreeNode *left_node;
		TreeNode *right_node;
	};
	
	void insert(struct TreeNode* &, int);
	void output(TreeNode*, int);
	bool find(TreeNode* &, int);
}