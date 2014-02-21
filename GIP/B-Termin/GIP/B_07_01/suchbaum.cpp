#include "suchbaum.h"

namespace suchbaum{
	void insert(TreeNode* &root, int data){

		if ( find(root, data) == true)
			return;
	
		TreeNode *new_node = new TreeNode;
		new_node->data = data;
		new_node->left_node = 0;
		new_node->right_node = 0;
	
		// Is tree empty?
		if (root == 0) {
			root = new_node;
		} else {
			TreeNode *root_ptr = root;

			// Is data smaller than the nodes data?
			if (root->data > data) {
				if (root->left_node == 0) {
					root->left_node = new_node;
				} else {
					insert(root->left_node, data);
				}

			// its not
			} else {
				if (root->right_node == 0) {
					root->right_node = new_node;
				} else {
					insert(root->right_node, data);
				}
			}
		}
	}

	bool find(TreeNode* &node,int data){
		bool found = false;

		if (node == 0){
			return false;
		}

		if (node->data == data) {
			found = true;
			return found;
		}

		if (node->left_node != 0){
			found = find(node->left_node, data);
			if (found == true)
				return found;
		}

		if (node->right_node != 0){
			found = find(node->right_node, data);
			if (found == true)
				return found;
		}

		return found;

	}

	void output(TreeNode* node, int depth){

		if (node == 0) {
			cout << "Empty tree." << endl;
			return;
		}

		if (node->right_node != 0){
			output(node->right_node, depth+1);
		}

		for (int i = 0; i < depth; i++) {
			cout << "    ";
		}
		cout << node->data << endl;

		if (node->left_node != 0){
			output(node->left_node, depth+1);
		}

	}


}