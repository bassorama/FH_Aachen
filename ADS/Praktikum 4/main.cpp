// Datum: 11.04.2014
#include "BinaryTree.h"
#include "treenode.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	BinaryTree* my_tree = new BinaryTree;
	treenode* tmp_node = new treenode;

	int input = -1;

	cout << "Geben Sie bitte Zahlen ein (Ende = 0)" << endl;
	while (input != 0) {
		cin >> input;
		if (input != 0)
			my_tree->insert(input);
	}

	input = -1;

	while (input != 9) {
	
		cout << "1: Ausgabe des Baumes in Levelorder" << endl;
		cout << "2: Element einfuegen" << endl;
		cout << "3: Quit" << endl;

		cin >> input;

		switch(input){
			case 1: {
				my_tree->levelorder(my_tree->root);
				cout << endl;
				break;
			}
			case 2: {
				int item = 0;
				cout << "Knoten einfuegen:" << endl;
				cin >> item;
				if (my_tree->insert(item))
					cout << "Element " << item << " erfolgreich eingefuegt" << endl;
				else
					cout << "Suchelement im Baum bereits vorhanden!" << endl;
				break;
			}
			case 3: {
				delete my_tree;
				break;
			}
		}
	}


	system("PAUSE");
	return 1;
}