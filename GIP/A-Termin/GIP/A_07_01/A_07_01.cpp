#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std; 
 
void graphisch2(const unsigned a[], const unsigned elemente){
	int ausgabe;
	int g = a[0];

	for (unsigned int i = 0; i < elemente; i++){
		if( a[i] > g)
			g = a[i];
	}

	do{
		for(int b=0; b < elemente; b++){
			ausgabe = a[b];
			if(ausgabe == g){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		cout << endl;
		g--;
	} while(g > 0);
			
	for(int b=0; b < elemente; b++){
			cout << "=";
		}
	cout << endl;
}


void graphisch(const unsigned int a[], const unsigned int N){
	unsigned int biggest = a[0];
	unsigned int pos = 0;

	for (unsigned int i = 0; i < N-1; i++){
		if( a[i] > biggest)
			biggest = a[i];
	}
	
	for (unsigned int i = 0; i < N; i++){
		for (unsigned int j = 0; j < N; j++){
			if( a[j] == biggest)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
		biggest--;
	}
	
	for(unsigned int i = 1; i<N; i++){
		cout << "=";
	}
	cout << endl;
}

void sortiere(unsigned int *a, unsigned int length){
	//cout << endl << "Elemente: " << length << endl;
	for (int i = length; i > 0; i--){
		//cout << i << endl << endl;
		for (int j = 1; j < i; j++){
			//cout << j << "->" << a[j] << " , "<< j+1 << "->" << a[j+1] << endl;
			if (a[j-1] > a[j]){
				unsigned int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
		graphisch2(a, length);
	}
}

unsigned int zufall(const unsigned int untergrenze, const unsigned int obergrenze){
	static bool initialisiert = false;
	if (! initialisiert) {
		initialisiert = true;
		srand((unsigned int) time(0));
	}
	int bereich = (obergrenze - untergrenze) + 1;
	return untergrenze + unsigned(bereich * (rand() / (RAND_MAX + 1.0)));
}
 
int main()
{
	int x, elemente, obergrenze;
	//const unsigned int N = 10;
	//unsigned int a[N] = { };
	
	cout << "Bitte geben sie die Anzahl der Array-Elemente ein: ";
	cin >> elemente;
	cout << endl;
	cout << "Bitte geben sie die Maximalgroesse jedes Array-Elements ein: ";
	cin >> obergrenze;

	unsigned int* a = new unsigned int[elemente];

	for(int p = 0; p <= elemente; p++){
		a[p] = zufall(1, obergrenze);
	}

	cout << "Vorher: ";
	for(int x = 0; x <= elemente-1; x++){
	   if (x == elemente-1)
		   cout << a[x] << endl;
	   else
		cout << a[x] << ", ";
	}
	

	sortiere(a, elemente);
	
	cout << endl << "Nachher: ";
	for(int x = 0; x <= elemente-1; x++){
	   if (x == elemente-1)
		   cout << a[x] << endl;
	   else
		cout << a[x] << ", ";
	}

	system("PAUSE");
}