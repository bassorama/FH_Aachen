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
		cout << "2: Ausgabe des Baumes in Preorder" << endl;
		cout << "3: Ausgabe des Baumes in Postorder" << endl;
		cout << "4: Ausgabe des Baumes in Inorder" << endl;
		cout << "5: Element suchen" << endl;
		cout << "6: Element loeschen" << endl;
		cout << "7: Element einfuegen" << endl;
		cout << "8: Elemente eines Niveaus ausgeben" << endl;
		cout << "9: Quit" << endl;

		cin >> input;

		switch(input){
			case 1: {
				my_tree->levelorder(my_tree->root);
				cout << endl;
				break;
			}
			case 2: {
				my_tree->preorder(my_tree->root);
				cout << endl;
				break;
			}
			case 3: {
				my_tree->postorder(my_tree->root);
				cout << endl;
				break;
			}
			case 4: {
				my_tree->inorder(my_tree->root);
				cout << endl;
				break;
			}
			case 5: {
				int item = 0;
				cout << "Knoten suchen:" << endl;
				cin >> item;
				if (my_tree->find(my_tree->root, tmp_node, item))
					cout << "Element " << item << " vorhanden" << endl;
				else
					cout << "Suchelement im Baum nicht vorhanden!" << endl;
				break;
			}
			case 6: {
				int item = 0;
				cout << "Knoten loeschen:" << endl;
				cin >> item;
				if (my_tree->pop(item))
					cout << "Element " << item << " geloescht" << endl;
				else
					cout << "Suchelement im Baum nicht vorhanden!" << endl;
				break;
			}
			case 7: {
				int item = 0;
				cout << "Knoten einfuegen:" << endl;
				cin >> item;
				if (my_tree->insert(item))
					cout << "Element " << item << " erfolgreich eingefuegt" << endl;
				else
					cout << "Suchelement im Baum bereits vorhanden!" << endl;
				break;
			}
			case 8: {
				int item = 0;
				cout << "Niveau eingeben:" << endl;
				cin >> item;
				my_tree->printlevel(my_tree->root,item, 0);
				cout << endl;
				break;
			}
			case 9: {
				delete my_tree;
				break;
			}
		}
	}


	system("PAUSE");
	return 1;
}