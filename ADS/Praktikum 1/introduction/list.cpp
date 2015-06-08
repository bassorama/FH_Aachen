// Datum: 25.03.2014
#include "list.h"
#include "node.h"

// Konstruktor, setzt den Kopf der Liste auf 0
list::list(){
	head = NULL;
}

// Gibt alle Knoten frei beim l�schen der Liste
list::~list(void){
	while (empty() != true) {
		pop_smallest();
	};
}

// Einf�ge Methode, input ist der einzuf�gende Wert
void list::insert(int input){
	// Liste ist leer, also Knoten hinter Kopf einh�ngen
	if (head == NULL) {
		node *new_node = new node;
		new_node->data = input;
		new_node->next = NULL;
		head = new_node;
		return;
	}
	// Erster Knoten ist gr��er als der Eingabe Wert, also
	// neuen Knoten zwischen Kopf und dem ersten Knoten einh�ngen
	if (head->data >= input ){
		node *new_node = new node;
		new_node->data = input;
		new_node->next = head;
		head = new_node;
		return;		
	}

	// Hilfspointer zum durchlaufen der Liste
	node *ptr = head;

	while (ptr->next != NULL){
		// N�chster Knoten ist gr��er als Eingabe Wert, also
		//  neuen Knoten vor diesem Knoten einh�ngen
		if (ptr->next->data >= input){
			node *new_node = new node;
			new_node->data = input;
			new_node->next = ptr->next;
			ptr->next = new_node;
			return;
		}
		ptr = ptr->next;
	}

	// Alle Werte sind groesser, also neuen Knoten an das
	// Ende der Liste einh�ngen
	if (ptr->next == NULL){
		node *new_node = new node;
		new_node->data = input;
		new_node->next = NULL;
		ptr->next = new_node;
		return;
	}

}

// Kann ein beliebiges Element aus der Liste l�schen
// input ist der zu l�schende Wert, zur�ckgegeben wird
// true falls das Element vorhanden ist, sonst false
bool list::pop(int input) {

	// Einfachster Fall: Das zu l�schende Element ist
	// das erste Element
	if (head->data == input) {
		node *temp_ptr = head;
		head = temp_ptr->next;
		delete temp_ptr;
		return true;
	}
	
	// Ansonten wird die Liste mit dem Hilfspointer ptr
	// durchlaufen bis das entsprechende Element gefunden wurde
	node *ptr = head;
	while( ptr->next != NULL) {
		if (ptr->next->data == input) {
			node *temp_ptr = ptr->next;
			ptr->next = temp_ptr->next;
			delete temp_ptr;
			return true;
		}
		ptr = ptr->next;
	}

	// Element nicht gefunden
	return false;

}

// Entfernt das kleinste Element der Liste und
// gibt dieses zur�ck
int list::pop_smallest(){
	if( head != NULL) {
		int output = head->data;
		node *temp_ptr = head;
		head = temp_ptr->next;
		delete temp_ptr;
		return output;
	}
}

// Sucht nach einem Element in der Liste
// input ist der zu suchende Wert
bool list::search(int input){
	if (head->data == input) {
		return true;
	}

	node *ptr = head;
	while( ptr->next != NULL) {
		if (ptr->next->data == input) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

// Gibt alle Elemente dieser Liste auf der
// Konsole aus
void list::output_list(){
	node *ptr = head;

	while (ptr->next != NULL) {
		std::cout << ptr->data << "-";
		ptr = ptr->next;
	}
	std::cout << ptr->data << std::endl;
}


// Pr�ft, ob die Liste leer ist
bool list::empty(){
	if (head == NULL) {
		return true;
	} else {
		return false;
	}
}

// Nimmt 2Listen input1 und input2 auf und f�gt deren
// Element sortiert in die eigene Liste ein.
void list::merge_list(list *input1, list *input2){
	//list *output = new list;

	while (input1->empty() != true) {
		insert(input1->pop_smallest());
	}
	while (input2->empty() != true) {
		insert(input2->pop_smallest());
	}

}
