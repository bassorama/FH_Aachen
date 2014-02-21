#include <iostream>
using namespace std;
struct TListenKnoten{
	int data;
	TListenKnoten *next;
	TListenKnoten *prev;
};

void hinten_anfuegen(TListenKnoten* &anker, const int wert){
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = 0;
	neuer_eintrag->prev = 0;
	if (anker == 0)
		anker = neuer_eintrag;
	else {
		TListenKnoten *ptr = anker;
		TListenKnoten *prev = anker;
		while (ptr->next != 0)
			ptr = ptr->next;
			neuer_eintrag->prev = anker;
			ptr->next = neuer_eintrag;
	}
}

void liste_ausgeben(TListenKnoten * anker){
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

void liste_ausgeben_rueckwaerts (TListenKnoten* anker){
	TListenKnoten *ptr = anker;
	if (anker->next == 0){
		cout << "[ " << ptr->data << " , ";
		return;
	} else {
		liste_ausgeben_rueckwaerts(ptr->next);
		if (anker->prev == 0 && anker->next != 0) {
			cout << ptr->data << " ]" << endl;
			return;
		} else {
			cout << ptr->data << " , ";
			return;
		}
	}

}

void einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert) {
	TListenKnoten *ptr = anker;
	if ( ptr->next != 0) {		
		if ( ptr->data == vor_wert) {
			TListenKnoten *neuer_eintrag = new TListenKnoten;
			neuer_eintrag->data = wert_neu;
			neuer_eintrag->next = ptr;
			neuer_eintrag->prev = 0;
			ptr->prev = neuer_eintrag;
			anker = neuer_eintrag;
			return;	
		} else {
			TListenKnoten *next = ptr->next;
			if ( next->data == vor_wert) {
				TListenKnoten *neuer_eintrag = new TListenKnoten;
				neuer_eintrag->data = wert_neu;
				neuer_eintrag->next = ptr->next;
				neuer_eintrag->prev = ptr;
				ptr->next = neuer_eintrag;
				return;	
			} else {
				einfuegen(ptr->next, wert_neu, vor_wert);
				return;
			}

		}

	} else {
		TListenKnoten *neuer_eintrag = new TListenKnoten;
		neuer_eintrag->data = wert_neu;
		neuer_eintrag->next = 0;
		neuer_eintrag->prev = ptr;
		ptr->next = neuer_eintrag;
		return;	
	}
}

int main() {
	const int laenge = 10;
	TListenKnoten *anker = 0;

	// liste_ausgeben(anker);
	for (int i = 0; i < laenge; i++)
		hinten_anfuegen(anker, i*i);
		liste_ausgeben(anker);
	
	// liste_ausgeben_rueckwaerts(anker);
	int wert_neu, vor_wert;
		cout << "Einzufuegender Wert: "; cin >> wert_neu;
		cout << "Vor welchem Wert? "; cin >> vor_wert;
	einfuegen(anker, wert_neu, vor_wert);
	
	liste_ausgeben(anker);

	liste_ausgeben_rueckwaerts(anker);
	
	system("PAUSE");
	return 0;
}