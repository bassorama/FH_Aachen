// Datum: 26.03.2014
#include "deque.h"
#include<iostream>

// Konstruktor setzt alle Variablen 0
deque::deque(void){
	head = NULL;
	tail = NULL;
}

// Destruktor, gibt alle vorhandenen Knoten frei
deque::~deque(void){
	while (size() != 0) {
		pop_front();
	}
}

// Fuegt ein Element am Anfang der Liste ein
// input ist der einzufuegende Wert
void deque::push_front(int input) {
	// Liste ist leer:
	if (head == NULL) {
		node *new_node = new node;
		new_node->data = input;
		new_node->next = NULL;
		new_node->prev = NULL;
		head = new_node;
		tail = new_node;
		return;
	}
	// Liste ist nicht leer:
	if (head != NULL){
		node *new_node = new node;
		new_node->data = input;
		new_node->next = head;
		new_node->prev = NULL;
		head->prev = new_node;
		head = new_node;
		return;	
	}
}

// Fuegt ein Element am Ende der Liste ein
// input ist der einzufuegende Wert
void deque::push_back(int input){
	// Liste ist leer
	if (tail == NULL) {
		node *new_node = new node;
		new_node->data = input;
		new_node->next = NULL;
		new_node->prev = NULL;
		head = new_node;
		tail = new_node;
		return;
	}
	// Liste ist nicht leer
	if (tail != NULL) {
		node *new_node = new node;
		new_node->data = input;
		new_node->next = NULL;
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
		return;		
	}
}

// Gibt das erste Element der Liste zurueck
int deque::get_front(){
	std::cout << "Kopfelement: " << head->data << std::endl;
	return head->data;
}

// Gibt das letzte Element der Liste zurueck
int deque::get_back(){
	std::cout << "Letztes Element: " << tail->data << std::endl;
	return tail->data;
}

// Entfernt das erste Element der Liste
void deque::pop_front(){
	// Die Liste besteht nur noch aus einem Element
	if (size() == 1){
		node *temp_ptr = head;
		head = NULL;
		tail = NULL;
		delete temp_ptr;	
	}
	// Es sind mehr als ein Element vorhanden
	if( head != NULL) {
		node *temp_ptr = head;
		head = temp_ptr->next;
		head->prev = NULL;
		delete temp_ptr;
	}
	// Ist die Liste leer passiert nichts
}

// Entfernt das letzte Element der Liste
void deque::pop_back(){
	// Die Liste besteht nur noch aus einem Element
	if (size() == 1){
		node *temp_ptr = head;
		head = NULL;
		tail = NULL;
		delete temp_ptr;	
	}
	// Es sind mehr als ein Element vorhanden
	if (tail != NULL) {
		node *temp_ptr = tail;
		tail = temp_ptr->prev;
		tail->next = NULL;
		delete temp_ptr;
	}
	// Ist die Liste leer passiert nichts
}

// Sucht in der Liste nach dem Wert input
/* Gibt einen boolean Wert zurück wenn der Wert gefunden wurde
   und schreibt in die Konsole
*/
 bool deque::find(int input){
	// Liste ist leer
	if (head == NULL){
		std::cout << "Liste ist leer!" << std::endl;
		return false;
	}
	// Erstes Element hat den gesuchten Wert
	if (head->data == input){
		std::cout << "Element " << input << " gefunden." << std::endl;
		return true;	
	}

	// Ansonsten wird mit dem Hilfspointer ptr die Liste durchgegangen
	node *ptr = head;

	while (ptr->next != NULL){
		if (ptr->next->data == input){
			std::cout << "Element " << input << " gefunden." << std::endl;
			return true;
		}
		ptr = ptr->next;
	}
	
	// Sollte das Element nicht gefunden werden
	std::cout << "Element " << input << " nicht in der Liste." << std::endl;
	return false;
}

// Pruef ob die Liste leer ist
bool deque::empty(){
	// Leere Liste ist head=tail=0	
	if (head == NULL){
		if (tail == NULL) {
			std::cout << "Liste ist leer!" << std::endl;
			return true;
		}
	}
	
	// Sonst ist die Liste nicht leer
	std::cout << "Liste ist nicht leer!" << std::endl;
	return false;
}

// Gibt die Groesse der Liste zurueck als int
int deque::size(){	
	int counter = 0;
	// Die Liste ist leer, die Groesse = 0
	if (head == NULL) {
		return counter;
	}
	
	// Sonst wird die Liste mit dem Hilfspointer ptr
	// durchlaufen und die Elemente gezaehlt
	counter += 1;
	node *ptr = head;

	while(ptr->next != NULL){
	 counter += 1;
	 ptr = ptr->next;
	}

	return counter;
}

// Gibt die Liste in der Konsole aus
void deque::print(){
	// Falls die Liste leer ist
	if (size() == 0){
		std::cout << "Liste ist leer!" << std::endl;
		return;
	}

	// Sonst wird mit dem Hilfspointer ptr die Liste
	// durchlaufen und die Elemente ausgegeben
	node *ptr = head;

	std::cout << "Inhalt der Liste: ";

	while (ptr->next != NULL) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << ptr->data << std::endl;
}
