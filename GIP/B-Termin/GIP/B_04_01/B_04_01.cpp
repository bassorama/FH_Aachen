#include<iostream>
#include<cmath>
#include<iomanip>
#include<cassert>
using namespace std;


long double fakultaet(long double x){
	long double temp = 1;
	for(int i=1; i <= x; i++){
		temp = temp*i;
	}
	return temp;
}

long double folgeglied(long double x, int k){
	long double zaehler = 0;
	long double nenner = 0;
	long double bruch = 0;
	long double ausgabe = 0;

	zaehler =  pow(long double(-1), long double(k));
	nenner = fakultaet((2*k+1));

	bruch = zaehler/nenner;

	ausgabe = pow(long double(x), long double((2*k+1)) );

	ausgabe = ausgabe*bruch;

	return ausgabe;

}

long double approx(long double x, int iterationen){
	long double ausgabe = 0;
	
	for(int k=iterationen-1; k>=0; k--){
		ausgabe += folgeglied(x, k);
	}



	return ausgabe;
}

void test_approx(){
	const int iterationen = 6;
	const long double interval = 3.2;
	const int schritte = 10;
	
	long double x = 0;

	cout << "Schritte: " << schritte << endl;

	for(int i=0; i<=10; i++){
		x = (interval/schritte)*i;

		cout << "x: " << x << endl;

		long double sin_x = 0;
		long double approx_x = 0;

		sin_x = sin(x);
		approx_x = approx(x, iterationen);

		cout << setprecision(10)  << " sin Berechnung: " << sin_x << endl;
		cout << setprecision(10) << " Approx (" << iterationen << " Iterationen): " << approx_x << endl;
		assert((sin_x - approx_x)< 0.01);
		cout << setprecision(10) << " Diff: " << (float(approx_x) - float(sin_x)) << endl;
	}
}

int main() {

	test_approx();

	system("PAUSE");

	return 0;
}