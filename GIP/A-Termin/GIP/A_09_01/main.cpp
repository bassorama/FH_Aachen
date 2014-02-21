#include <iostream>
#include <string>
using namespace std;

int main(){
	float tankfuellungen[3];
	float wegstrecken[3];
	string kennzeichen;

	float mittlererverbrauch = 0;

	cout << endl << "Kennzeichen = ? ";
	//cin >> kennzeichen;
	getline(cin, kennzeichen);

	cout << endl << "Tankfuellung 1 [l] = ? ";
	cin >> tankfuellungen[0];

	cout << endl << "Wegstrecke 1 = ? ";
	cin >> wegstrecken[0];
	
	cout << endl << "Tankfuellung 2 [l] = ? ";
	cin >> tankfuellungen[1];

	cout << endl << "Wegstrecke 2 = ? ";
	cin >> wegstrecken[1];
	
	cout << endl << "Tankfuellung 3 [l] = ? ";
	cin >> tankfuellungen[2];

	cout << endl << "Wegstrecke 3 = ? ";
	cin >> wegstrecken[2];
	
	mittlererverbrauch = ((tankfuellungen[0]/wegstrecken[0])*100+(tankfuellungen[1]/wegstrecken[1])*100+(tankfuellungen[2]/wegstrecken[2])*100)/3;

	cout << endl << kennzeichen << ":" << endl;
	cout << "Mittlerer Verbrauch [l/100km] : " << mittlererverbrauch << endl;

	system("PAUSE");

	return 0;
}