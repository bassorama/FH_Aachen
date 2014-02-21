#include <iostream>
#include <string>
using namespace std;

class mobile{
	private:
		int id, plz, kilometerstand;
		float preis;
		string marke, modell, kraftstoff;
	public:
		// Setter, getter fuer id:
		void set_id(int data){
			id = data;
		};

		int get_id(){
			return id;
		};

		// Setter, getter fuer plz:
		void set_plz(int data){
			plz = data;
		};

		int get_plz(){
			return plz;
		};

		//Setter, getter fuer kilometerstand:
		void set_kilometer(int data){
			kilometerstand = data;
		};

		int get_kilometer(){
			return kilometerstand;
		};

		//Setter, getter fuer preis:
		void set_preis(float data){
			preis = data;
		};

		float get_preis(){
			return preis;
		};

		//Setter, getter fuer marke:
		void set_marke(string data){
			marke = data;
		};

		string get_marke(){
			return marke;
		}

		//Setter, getter fuer modell:
		void set_modell(string data){
			modell = data;
		};

		string get_modell(){
			return modell;
		}

		//Setter, getter fuer kraftstoffart:
		void set_kraftstoff(string data){
			kraftstoff = data;
		};

		string get_kraftstoff(){
			return kraftstoff;
		}

		void input(){
			string str_tmp;
			int int_tmp = 0;
			float float_tmp = 0;

			cout << "ID \t \t= ? ";
			cin >> int_tmp;
			set_id(int_tmp);

			cout << "Marke \t \t= ? ";
			cin >> str_tmp;
			set_marke(str_tmp);

			cout << "Modell \t \t= ? ";
			cin >> str_tmp;
			set_modell(str_tmp);

			cout << "Preis \t \t= ? ";
			cin >> float_tmp;
			set_preis(float_tmp);

			cout << "Kilometerstand \t = ? ";
			cin >> int_tmp;
			set_kilometer(int_tmp);

			cout << "Kraftstoffart \t = ? ";
			cin >> str_tmp;
			set_kraftstoff(str_tmp);

			cout << "PLZ \t \t= ? ";
			cin >> int_tmp;
			set_plz(int_tmp);
		};

		void search_input(){
			string str_tmp;
			int int_tmp = 0;
			float float_tmp = 0;

			cout << "Wonach suchen Sie?" << endl;

			cout << "Marke \t \t= ? ";
			cin >> str_tmp;
			set_marke(str_tmp);

			cout << "Modell \t \t= ? ";
			cin >> str_tmp;
			set_modell(str_tmp);

			cout << "Preis \t \t= ? ";
			cin >> float_tmp;
			set_preis(float_tmp);

			cout << "Kilometerstand \t = ? ";
			cin >> int_tmp;
			set_kilometer(int_tmp);

			cout << "Kraftstoffart \t = ? ";
			cin >> str_tmp;
			set_kraftstoff(str_tmp);

			cout << "PLZ \t \t= ? ";
			cin >> int_tmp;
			set_plz(int_tmp);
		};

		void output(){
			cout << endl << "ID \t\t = " << get_id() << endl;

			cout << "Marke \t\t = " << get_marke() << endl;

			cout << "Modell \t\t = " << get_modell() << endl;

			cout << "Preis \t\t = " << get_preis() << endl;
			
			cout << "Kilometerstand \t = " << get_kilometer() << endl;

			cout << "Kraftstoffart \t = " << get_kraftstoff() << endl;

			cout << "PLZ \t\t = " << get_plz() << endl << endl;
		};

		mobile(){
			id = 0;
			plz = 0;
			kilometerstand = 0;
			preis = 0;
			marke = "Leer";
			modell = "Leer";
			kraftstoff = "Leer";
		};

};

int main(){

	mobile mobil_1;
	mobile mobil_2;
	mobile mobil_3;

	mobile search_mobil;

	mobil_1.input();
	cout << endl;
	mobil_2.input();
	cout << endl;
	mobil_3.input();
	cout << endl;

	search_mobil.search_input();

	if (search_mobil.get_marke() != "0"){
		if(mobil_1.get_marke() == search_mobil.get_marke()){
			mobil_1.output();
		}
		if(mobil_2.get_marke() == search_mobil.get_marke()){
			mobil_2.output();
		}
		if(mobil_3.get_marke() == search_mobil.get_marke()){
			mobil_3.output();
		}
		system("PAUSE");
		return 0;
	}

	if (search_mobil.get_modell() != "0"){
		if(mobil_1.get_modell() == search_mobil.get_modell()){
			mobil_1.output();
		}
		if(mobil_2.get_modell() == search_mobil.get_modell()){
			mobil_2.output();
		}
		if(mobil_3.get_modell() == search_mobil.get_modell()){
			mobil_3.output();
		}
		system("PAUSE");
		return 0;
	}

	if (search_mobil.get_preis() != 0){
		if(mobil_1.get_preis() <= search_mobil.get_preis()){
			mobil_1.output();
		}
		if(mobil_2.get_preis() <= search_mobil.get_preis()){
			mobil_2.output();
		}
		if(mobil_3.get_preis() <= search_mobil.get_preis()){
			mobil_3.output();
		}
		system("PAUSE");
		return 0;
	}

	if (search_mobil.get_kilometer() != 0){
		if(mobil_1.get_kilometer() <= search_mobil.get_kilometer()){
			mobil_1.output();
		}
		if(mobil_2.get_kilometer() <= search_mobil.get_kilometer()){
			mobil_2.output();
		}
		if(mobil_3.get_kilometer() <= search_mobil.get_kilometer()){
			mobil_3.output();
		}
		system("PAUSE");
		return 0;
	}

	if (search_mobil.get_kraftstoff() != "0"){
		if(mobil_1.get_kraftstoff() == search_mobil.get_kraftstoff()){
			mobil_1.output();
		}
		if(mobil_2.get_kraftstoff() == search_mobil.get_kraftstoff()){
			mobil_2.output();
		}
		if(mobil_3.get_kraftstoff() == search_mobil.get_kraftstoff()){
			mobil_3.output();
		}
		system("PAUSE");
		return 0;
	}

	if (search_mobil.get_plz() != 0){
		if(mobil_1.get_plz() == search_mobil.get_plz()){
			mobil_1.output();
		}
		if(mobil_2.get_plz() == search_mobil.get_plz()){
			mobil_2.output();
		}
		if(mobil_3.get_plz() == search_mobil.get_plz()){
			mobil_3.output();
		}
		system("PAUSE");
		return 0;
	}

	system("PAUSE");
	return 0;
};