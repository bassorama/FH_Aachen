#include "mail.h"
#include "letter.h"
#include "parcel.h"
#include <iostream>
using namespace std;

int main(){
	// --- Briefe ---
	address to("Boss, Anton","Antonstr. 11", "23456 Hamburg");
	Letter letter1( 102030, Letter::EXPRESS), letter2( 203040, to);// Zwei Briefe
	cout << "Die Briefe: \n" << letter1 << letter2 << endl;
	cout << "Bitte Absender fuer Brief " << letter1.getID() << " eingeben:" << endl;
	if( !letter1.scanFrom())
		cout << "Ungueltige Eingabe!" << endl;
	cout << "und der Empfaenger:" << endl;
	if( !letter1.scanTo())
		cout << "Ungueltige Eingabe!" << endl;
	cout << "Die neuen Daten des Briefs: \n" << letter1 << endl;
	cout << "Ein Versuch, den Brief auszuliefern:" << endl;
	if( letter1.deliver())
		cout << "Brief mit der ID " << letter1.getID() << " wurde ausgeliefert!\n" << endl;
	else
		cout << "Kein gueltiger Empfaenger!" << endl;
	cin.get();
	
	// --- Pakete ---
	Parcel parcel1( 500001, 2.5F, true),// Zwei Pakete
	parcel2( 500002, 10.7F, to, Address("Bauer, Hans","Feldweg 2","88888 Einoed"));
	cout << "Die Pakete: \n" << parcel1 << parcel2 << endl;
	cout << "Bitte Empfaenger fuer Paket " << parcel1.getID() << " eingeben:" << endl;
	if( !parcel1.scanTo())
		cout << "Ungueltige Eingabe!" << endl;
	if( parcel2.deliver())
		cout << "\nPaket mit der ID " << parcel2.getID() << " und dem Gewicht " << parcel2.getWeight() << " wurde ausgeliefert!" << endl;
	return 0;
}