
#include <iostream>

using namespace std;

int main(){

	int b[10] = {0,0,0,0,0,0,0,0,0,0};
	int *p1 = &b[0];
	*p1 = 5;
	*(++p1) = 6;
	*(p1+1) = 7;
 
	p1 = &b[0];
	for (int i=0; i<10; i++)
	{
			cout << *p1 << " ";
			p1++;
	}

	cout << endl << b[0] << " " << b[1] << " " << b[2] << " " << endl;


	system("PAUSE");
	return 0;
}