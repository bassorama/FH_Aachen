#include <iostream>
using namespace std;

int mystrln (const char * ptr){
	int counter = 0;
	int index = 0;
	while (ptr[index] != '\0'){
		counter +=1;
		index += 1;
	}
	return counter;
}

char * mystrnconcat(const char * sptr1, const char * sptr2, int count) {
	int out_length = 0;
	if (mystrln(sptr2) < count){
		out_length = mystrln(sptr1)+mystrln(sptr2)+1;
	} else {
		out_length =  mystrln(sptr1)+count+1;
	}
	char* temp = new char[out_length];
	
	int counter = 0;
	int s1_length = mystrln(sptr1);

	if (mystrln(sptr2) < count) {
		while(counter < s1_length) {
			temp[counter] = sptr1[counter];
			counter++;
		}
		for (int i = 1; i < mystrln(sptr2)+1; i++) {
			temp[counter] = sptr2[i-1];
			counter++;
		}
	} else {
		while(counter < s1_length) {
			temp[counter] = sptr1[counter];
			counter++;
		}
		for (int i = 1; i < (count+1); i++) {
			temp[counter] = sptr2[i-1];
			counter++;
		}
	}
	temp[counter]= '\0';
	return temp;
}

char* mystrfind(char * sptr1, char * sptr2) {

	char* input = sptr1;
	char* input2 = sptr2;
	int str1_lng = mystrln(input);
	int str2_lng = mystrln(input2);
	bool found = false;
	int i = 0;
	int j = 0;

	while ( i < str1_lng) {
		if (input[i] == sptr2[j]) {
			while (j < str2_lng) {
				if (input[i] == sptr2[j]) {
					found = true;
					i++;
				} else {
					found = false;
				}
				j++;
			}

			if (found == true) {
				for (int i = 0; i < mystrln(input); i++) {
					if (input[i] == sptr2[0]) {
						char * out_ptr = &input[i];
						return out_ptr;
					}
				}
			} 

		} else {
			found = false;
		}
		i++;
	}

	if (found == false) {
		char *out_ptr = NULL;
		return out_ptr;
	}
}



int main() {
	/*
	int choice = 0;

	cout << "Bitte waehlen Sie die Operation aus:" << endl;
	cout << "-1- mystrln()" << endl;
	cout << "-2- mystrnconcat()" << endl;
	cout << "-3- mystrfind()" << endl;

	cin >> choice;



	*/

	cout << "Aufgabe 1:" << endl;
	cout << mystrln("Hallo") << endl;
	
	cout << "Aufgabe 2:" << endl;
	char s1[80]="FH", s2[80]="Hallo Welt";
	cout << mystrnconcat(s1, s2, 4) << endl;
	
	cout << "Aufgabe 3:" << endl;
	char* p2=mystrfind("Dies ist ein Test", "e");
	if (p2 == NULL){
		cout << "String nicht gefunden." << endl;
	} else {
		cout << p2 << endl;
	}

	system("PAUSE");
	return 0;
}