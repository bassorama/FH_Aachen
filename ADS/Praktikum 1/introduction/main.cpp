// Datum: 25.03.2014
#include "node.h"
#include "list.h"
#include <iostream>

using namespace std;

// Testet die Funktionen der Liste
void test_list(){
	// Eine neue Liste erzeugen, befühlen und ausgeben
	list *my_list = new list;

	my_list->pop_smallest();

	my_list->insert(3);
	my_list->insert(1);
	my_list->insert(6);
	my_list->insert(4);
	my_list->insert(2);

	my_list->output_list();

	// Beliebige Elemente löschen und die Liste jeweils
	// zur Kontrolle ausgeben
	
	cout << "Loesche 5." << endl;
	if(my_list->pop(5)==true){
		cout << "Element gefunden und geloescht." << endl;
	} else {
		cout << "Element nicht gefunden." << endl;
	};
	my_list->output_list();
	
	cout << "Loesche 6." << endl;
	if(my_list->pop(6)==true){
		cout << "Element gefunden und geloescht." << endl;
	} else {
		cout << "Element nicht gefunden." << endl;
	};
	my_list->output_list();

	// Das kleinste Element löschen und die Liste ausgeben
	my_list->pop_smallest();
	my_list->output_list();

	// In der Liste nach 2 Werten suchen
	cout << endl;
	cout << my_list->search(8) << endl;
	cout << my_list->search(3) << endl;

	// Restliche Werte Löschen und test von Löschen bei
	// leerer Liste
	my_list->pop_smallest();
	my_list->pop_smallest();
	my_list->pop_smallest();

	// Fertig, liste löschen
	delete my_list;
}

// Testen der Verbindung von 2 Listen
void test_merge() {
	// Liste 1 erzeugen und ausgeben
	list *list1 = new list;

	list1->insert(7);
	list1->insert(2);
	list1->insert(14);

	cout << "Liste 1: ";
	list1->output_list();

	// Liste 2 erzeugen und ausgeben
	list *list2 = new list;

	list2->insert(19);
	list2->insert(55);
	list2->insert(13);

	cout << "Liste 2: ";
	list2->output_list();

	// Neue Liste erzeugen und die 2 Listen in der 
	// neuen Liste zusammenfügen und ausgeben
	list *new_list = new list;

	new_list->merge_list(list1, list2);

	cout << "Neue Liste: ";
	new_list->output_list();
	
	// Fertig, listen löschen
	delete list1;
	delete list2;
	delete new_list;

}

int main(int argc, char* argv[]) {
	
	cout << "Test der Listen Funktionen:" << endl;
	test_list();
	cout << endl;
	cout << "Test der Verbindung von 2 Listen:" << endl;
	test_merge();
	
	system("PAUSE");
	return 0;
};
