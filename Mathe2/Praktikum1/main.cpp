#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip> 

using namespace std;

void aufgb1(){
	double pi = M_PI;
	//long double pi = 4*atan(1.0);

	double V_1 [40];
	for (int i=0; i<=39;i++){
		V_1[i] = 0;
	};

	V_1[0] = 2/pi;
	V_1[1] = 1/pi;
	double help_1 = 1/pi;
	double sqrt_pi = pow(pi, 2);
		
	ofstream output;
	output.open("V_1.txt", ios::out | ios::binary);

	for (int n=2; n<=39; n++) {
		double help_2 = n*(n-1);	
		V_1[n] = help_1 - ((help_2/sqrt_pi)*V_1[n-2]);
	};

	for (int i=0; i<=39; i++){
		cout << "n: " << i << " I_"<< i << ": " << scientific << setprecision(10) << V_1[i] << endl;
		output << i << " " << scientific << setprecision(10) << V_1[i] << " " << endl;
	};

	output.close();
}

void aufgb2() {

	double pi = M_PI;
	//long double pi = 4*atan(1.0);

	double I_60 = 1./61.;
	double I_59 = 1./60.;

	double V_2 [60];
	for (int i=0; i<=59;i++){
		V_2[i] = 0;
	};

	V_2[59] = I_60;
	V_2[58] = I_59;

	ofstream output;
	output.open("V_2.txt", ios::out | ios::binary);

	for (int n=57; n>=0; n--) {
		double zaehler = pi*(1-pi*V_2[n+2]);
		double nenner = (n+2)*((n+2)-1);
		V_2[n] = zaehler/nenner;
	};

	for (int i=59; i>=0; i--){
		cout << "n: " << i << " I_"<< i << ": " << scientific << setprecision(10) << V_2[i] << endl;
		output << i << " " << scientific << setprecision(10) << V_2[i] << " " << endl;
	};

	output.close();
}

int main(int argc, char* argv[]) {
	
	aufgb1();

	aufgb2();

	system("PAUSE");
	return 0;
};