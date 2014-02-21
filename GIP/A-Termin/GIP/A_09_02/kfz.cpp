#include <iostream>
#include <string>
using namespace std;

class kfz{
	private:
		float tankfuellungen[3];
		float wegstrecken[3];
		string kennzeichen;
	public:
		// Erwartet einen Parameter int pos = 1..3
		float get_tankfuellung(int pos){
			if (pos > 3) {
				cout << "Parameter zugross" << endl;
				return 0;
			} else {
				return tankfuellungen[pos-1];
			}
		};

		// Erwartet einen Parameter int pos = 1..3
		void set_tankfuellung(int pos, float data){
			if (pos > 3) {
				cout << "Parameter zugross" << endl;
			} else {
				tankfuellungen[pos-1] = data;
			}
		};

		// Erwartet einen Parameter int pos = 1..3
		float get_wegstrecke(int pos){
			if (pos > 3) {
				cout << "Parameter zugross" << endl;
				return 0;
			} else {
				return wegstrecken[pos-1];
			}
		};

		// Erwartet einen Parameter int pos = 1..3
		void set_wegstrecke(int pos, float data){
			if (pos > 3) {
				cout << "Parameter zugross" << endl;
			} else {
				wegstrecken[pos-1] = data;
			}
		};

		float get_mittlerer_verbrauch(){
			return ((tankfuellungen[0]/wegstrecken[0])*100+(tankfuellungen[1]/wegstrecken[1])*100+(tankfuellungen[2]/wegstrecken[2])*100)/3;
		};

		void set_kennzeichen(string zeichen){
			kennzeichen = zeichen;
		};

		string get_kennzeichen(){
			return kennzeichen;
		};

		kfz(){
			for(int i = 0; i <= 2; i++){
				tankfuellungen[i] = 0;
				wegstrecken[i] = 0;
			}
		};
};

int main(){

	kfz mein_auto;
	string kennzeichen_tmp;
	float temp, mittlerer_verbrauch;

	cout << endl << "Kennzeichen = ? ";
	//cin >> kennzeichen_tmp;
	getline(cin, kennzeichen_tmp);
	mein_auto.set_kennzeichen(kennzeichen_tmp);

	cout << endl << "Tankfuellung 1 [l] = ? ";
	cin >> temp;
	mein_auto.set_tankfuellung(1, temp);

	cout << endl << "Wegstrecke 1 = ? ";
	cin >> temp;
	mein_auto.set_wegstrecke(1, temp);
	
	cout << endl << "Tankfuellung 2 [l] = ? ";
	cin >> temp;
	mein_auto.set_tankfuellung(2, temp);

	cout << endl << "Wegstrecke 2 = ? ";
	cin >> temp;
	mein_auto.set_wegstrecke(2, temp);
	
	cout << endl << "Tankfuellung 3 [l] = ? ";
	cin >> temp;
	mein_auto.set_tankfuellung(3, temp);

	cout << endl << "Wegstrecke 3 = ? ";
	cin >> temp;
	mein_auto.set_wegstrecke(3, temp);
	
	mittlerer_verbrauch = mein_auto.get_mittlerer_verbrauch();

	cout << endl << mein_auto.get_kennzeichen() << ":" << endl;
	cout << "Mittlerer Verbrauch [l/100km] : " << mittlerer_verbrauch << endl;

	system("PAUSE");

	return 0;

};