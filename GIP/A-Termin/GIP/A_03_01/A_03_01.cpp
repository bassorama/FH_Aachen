#include<iostream>
using namespace std;

int main(){

	// Initialisieren der Variablen
	int Std1 = 0;
	int Min1 = 0;
	int Sek1 = 0;

	int Std2 = 0;
	int Min2 = 0;
	int Sek2 = 0;

	int OutStd = 0;
	int OutMin = 0;
	int OutSek = 0;

	// Eingabe der Uhrzeiten
	cout << "Erste Uhrzeit (Std, Min, Sek)?" << endl;
	cin >> Std1 >> Min1 >> Sek1;

	cout << "Zweite Uhrzeit (Std, Min, Sek)?" << endl;
	cin >> Std2 >> Min2 >> Sek2;

	// Pruefen der Eingaben
	if (( Std1 > 23 ) || ( Std2 > 23 ))
	{
		cout << "Ungueltige Eingabe" << endl;
		system("PAUSE");
		return -1;
	}

	if ( (Sek1 > 59) || (Sek2 > 59) || (Min1 > 59) || (Min2 > 59) )
	{
		cout << "Ungueltige Eingabe" << endl;
		system("PAUSE");
		return -1;
	}

	// Differenz Sekunden
	if (Sek1 == Sek2)
		OutSek = 0;
	else if (Sek2 < Sek1)
	{
		OutSek = (60-Sek1)+Sek2;
		Min1 += 1;
	}
	else
		OutSek = Sek1 + Sek2;


	// Diefferenzen Minuten
	if (Min1 == Min2)
		OutMin = 0;
	else if (Min2 < Min1)
	{
		OutMin = (60-Min1)+Min2;
		Std1 += 1;
	}
	else
		OutMin = Min1 + Min2;

	// Differenzen Stunden
 	if (Std1 == Std2)
		OutStd = 0;
	else if (Std2 < Std1)
		OutStd = (24-Std1)+Std2;
	else
		OutStd = Std1 + Std2;

	// Ausgabe
	cout << "Die Zeitdifferenz betraegt: " << OutStd << "Std, " << OutMin << "Min und " << OutSek << "Sek." << endl;

	system("PAUSE");

	return 0;
}