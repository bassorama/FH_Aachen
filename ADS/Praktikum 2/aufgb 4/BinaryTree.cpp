// Datum: 11.04.2014
#include "BinaryTree.h"
#include <iostream>
#include <queue>

BinaryTree::BinaryTree(void){
	root = 0;

	treenode* tmp = new treenode;
	tmp->data = -1;
	tmp->left = 0;
	tmp->right = root;
	tmp->parent = 0;
	head = tmp;
}

// Deletes the root untill tree is empty - O(n)
BinaryTree::~BinaryTree(void){
	while (root != 0){
		int tmp = 0;
		tmp = root->data;
		pop(tmp);
	}
}

// Inserts item into tree - O(h) [h = height]
bool BinaryTree::insert(int item) {
	treenode *parent = head; // Elternknoten merken
	treenode *child = root; // child ist Wurzelknoten
	
	// tree is empty, item becomes new root
	if (root == 0) {
		treenode *new_node = new treenode;
		new_node->data = item;
		new_node->right = 0;
		new_node->left = 0;
		new_node->parent = parent;
		root = new_node;
	}

	// tree is not empty, we go down the tree untill we find a free slot
	while (child != 0){
		parent = child;
		if (item == child->data)
			return false;
		else if (item < child->data)
			child = child->left;
		else
			child = child->right;
	}
	treenode *new_node = new treenode;
	new_node->data = item;
	new_node->right = 0;
	new_node->left = 0;
	new_node->parent = parent;
	if (item < parent->data){
		parent->left = new_node;
	} else { 
		parent->right = new_node;
	}
	return true;

}

// We delete a node from out tree - O(h) [h = height of tree]
bool BinaryTree::pop(int item) {
	bool found = false;

	treenode* parent = head;
	treenode* child = root;

	if (child == 0)
		return false;

	//item is root and no children
	if(child->left == 0 && child->right == 0){		
		if (item == child->data) {
			root = 0;
			return true;
		} else
			return false;
	}

	//item is root and has 1 child
	if (child->left != 0 && child->right == 0) {
		treenode* tmp = root->left;
		tmp->parent = head;
		head->right = tmp;
		root = tmp;
		delete child;
		return true;
	};
	if (child->left == 0 && child->right != 0) {
		treenode* tmp = root->right;
		tmp->parent = head;
		head->right = tmp;
		root = tmp;
		delete child;
		return true;
	};
	// item is root and has 2 children
	if (child->left != 0 && child->right != 0) {
		treenode* tmp;
		find_min(child->right,tmp);
		treenode* tmp_parent = tmp->parent;
		tmp_parent->left = 0;
		tmp->left = root->left;
		tmp->right = root->right;
		tmp->parent = head;
		head->right = root;
		delete child;
		return true;
	};

	// Item is not root, we go down the tree untill we find the item
	while (child != 0) {
		parent = child;
		if (item == child->data){
			// has no children
			if (child->left == 0 && child->right == 0){
				parent = child->parent;
				treenode* tmp = child;
				if (item < parent->data)
					parent->left = 0;
				else
					parent->right = 0;
				delete tmp;
				return true;
			}
			// Just one child
			if (child->left != 0 && child->right == 0) {
				parent = child->parent;
				treenode* tmp = child->left;
				tmp->parent = child->parent;
				if (item < parent->data)
					parent->left = tmp;
				else
					parent->right = tmp;
				delete child;
				return true;
			}
			if (child->left == 0 && child->right != 0) {
				parent = child->parent;
				treenode* tmp = child->right;
				tmp->parent = child->parent;
				if (item < parent->data)
					parent->left = tmp;
				else
					parent->right = tmp;
				delete child;
				return true;
			}
			// Two children
			if (child->left != 0 && child->right != 0) {
				parent = child->parent;
				treenode* tmp;
				find_min(child->right,tmp);
				treenode* tmp_parent = tmp->parent;
				tmp_parent->left = 0;
				tmp->left = child->left;
				tmp->right = child->right;
				tmp->parent = child->parent;
				if (item < parent->data)
					parent->left = tmp;
				else
					parent->right = tmp;
				delete child;
				return true;
			}
		} else if (item < child->data)
			child = child->left;
		else
			child = child->right;
	}

	return found;
}

// Prints the tree in preorder - O(n)
void BinaryTree::preorder(treenode* &node) {
	if (node == 0)
		return;
	
	std::cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
}

// Prints the tree in postorder - O(n)
void BinaryTree::postorder(treenode* &node) {
	if (node == 0)
		return;
	
	postorder(node->left);
	postorder(node->right);
	std::cout << node->data << " ";
}

// Prints the tree in inorder - O(n)
void BinaryTree::inorder(treenode* &node) {
	if (node == 0)
		return;

	inorder(node->left);
	std::cout << node->data << " ";
	inorder(node->right);
}

// Prints the tree in preorder - O(n)
void BinaryTree::levelorder(treenode* &node) {
	if (node == 0)
		return;
	
	std::queue<treenode*> my_queue;
	
	my_queue.push(node);

	while ( !my_queue.empty()) {
		treenode* node = my_queue.front();
		my_queue.pop();
		std::cout << node->data << " ";
		if (node->left != 0)
			my_queue.push(node->left);
		if (node->right != 0)
			my_queue.push(node->right);
	}

}


// prints a given level of a tree - O(2^n) -> O(sum(2^(l-1)) [l=level]
void BinaryTree::printlevel(treenode* &node, int level, int start_lvl) {
	// tree is empty, nothing to print!
	if (node == 0)
		return;

	// we are on the wanted level, print item
	if (level == start_lvl) {
		std::cout << node->data << " ";
		return;
	}

	// we are not on the wanted level, go deeper
	if (node->left != 0)
		printlevel(node->left, level, start_lvl+1);
	if (node->right != 0)
		printlevel(node->right, level, start_lvl+1);

}

// Searches for an item in the given tree, returns a bool for success or failure
// writes the found item to &result. - O(h) [h=height of tree]
bool BinaryTree::find(treenode* &node, treenode* &result,int item) {
	bool found = false;

	//tree is empty
	if (node == 0){
		result = node;
		return false;
	}

	// we found the item
	if (node->data == item) {
		found = true;
		result = node;
		return found;
	}

	// did not find the item, go into left subtree
	if (node->left != 0){
		found = find(node->left, result, item);
	if (found == true)
		return found;
	}
	// did not find the item, go into right subtree
	if (node->right != 0){
		found = find(node->right,result, item);
	if (found == true)
		return found;
	}

	return found;
}

// Finds the max item of a tree, returns the max item as int and
// writes the node to &result
// O(h) [h=height of tree]
int BinaryTree::find_max(treenode* &node, treenode* &result) {
	int output = -1;

	// tree is empty
	if (node == 0){
		result = node;
		return output;
	}

	// we go down further the right subtree
	if (node->right != 0){
		output = find_max(node->right, result);
	} else {
		output = node->data;
		result = node;
	}

	return output;
}

// Finds the min item of a tree, returns the min item as int and
// writes the node to &result
// O(h) [h=height of tree]
int BinaryTree::find_min(treenode* &node, treenode* &result) {
	int output = -1;

	// tree is empty
	if (node == 0){
		result = node;
		return output;
	}

	// we go down further the left subtree
	if (node->left != 0){
		output = find_min(node->left, result);
	} else {
		output = node->data;
		result = node;
	}

	return output;
}