#include "mail.h"
int main(){
	mail aMail(1020304);
	
	cout << "Bitte Absender angeben:" << endl;
	if( !aMail.scanFrom())
		cout << "Ungueltige Eingabe!" << endl << endl;
	
	cout << "und der Empfaenger:" << endl;
	if( !aMail.scanTo())
		cout << "Ungueltige Eingabe!" << endl;
	
	cout << aMail << endl;
	cout << "... Post mit der ID " << aMail.getID();
	
	if( aMail.deliver())
		cout << " wurde an " << aMail.getTo().getName() << " ausgeliefert!" << endl;
	else
		cout << " konnte nicht ausgeliefert werden!" << endl;
	
	system("PAUSE");

	return 0;
}