#include <iostream>
#include <string>
using namespace std;

int main() {
	int goal = 0;
	int tmp = 0;
	int counter = 0;
	int sum = 0;
	bool reached = false;

	cout << "S = ?";
	cin >> goal;

	while (!reached){
		cout << "Zahl = ?";
		cin >> tmp;
		sum += tmp;
		counter++;
		if (sum >= goal){
			cout << "Der Wert " << goal << " wurde ueberschritten!" << endl;
			reached = true;
		};
	}
	cout << "Summe = " << sum << endl;
	cout << counter << " Zahlen wurden eingegeben." << endl;

	system("PAUSE");

	return 0;
}