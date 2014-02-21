#include <iostream>
using namespace std;
struct TListenKnoten{
	int data;
	TListenKnoten *next;
};

void insert(TListenKnoten* &anker, const int wert){
	// Anker ist NULL, dann neues Element anfuegen
	if (anker == 0) {
		TListenKnoten *neuer_eintrag = new TListenKnoten;
		neuer_eintrag->data = wert;
		neuer_eintrag->next = 0;
		anker = neuer_eintrag;
		return;
	}

	// Wert des Ankers ist groesser als Einzufuegender Wert
	if (anker->data >= wert){
		TListenKnoten *neuer_eintrag = new TListenKnoten;
		neuer_eintrag->data = wert;
		neuer_eintrag->next = anker;
		anker = neuer_eintrag;
		return;
	}

	TListenKnoten *ptr = anker;
	
	while (ptr->next != 0){

		// Naechster ist groesser, als Wert vor diesem Knoten einfuegen
		if (ptr->next->data >= wert){
			TListenKnoten *neuer_eintrag = new TListenKnoten;
			neuer_eintrag->data = wert;
			neuer_eintrag->next = ptr->next;
			ptr->next = neuer_eintrag;
			return;
		}
		ptr = ptr->next;
	}

	//Alle Werte sind groesser, also Wert an das Ende haengenb
	if (ptr->next == 0){
		TListenKnoten *neuer_eintrag = new TListenKnoten;
		neuer_eintrag->data = wert;
		neuer_eintrag->next = 0;
		ptr->next = neuer_eintrag;
		return;
	}
}

void output(TListenKnoten * anker){
	if (anker == 0)
		cout << "Leere Liste." << endl;
	else {
		cout << "[ ";
		TListenKnoten *ptr = anker;
	do {
		cout << ptr->data << (ptr->next != 0 ? " , " : " ");
		ptr = ptr->next;
	} while (ptr != 0);
	cout << "]" << endl;
	}
}

int main(){
	TListenKnoten *anker = 0;
	int choice = 0;
	int key_value = 0;

	//Menu:

	do {
		cout << endl;
		cout << "1 Schluesselwert eingeben" << endl;
		cout << "2 Liste ausgeben" << endl;
		cout << "3 Programm beenden" << endl;

		cin >> choice;

		if (choice == 1) {
			cout << "Schluesselwert = ?" << endl;
			cin >> key_value;

			insert(anker, key_value);
		}
		
		if (choice == 2)
			output(anker);
		
		if (choice == 3)
			break;
	} while(choice != 3);

	system("PAUSE");
	return 0;
}