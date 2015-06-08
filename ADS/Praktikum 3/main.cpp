// Datum: 01.05.2014
// Mergesort und Heapsort funktoiniert noch nicht, Aufgb. 6 und 7 muessen noch zuende implementiert werden.
#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
#include <fstream>

using namespace std;

// Insertion Sort
void insertionsort(vector<int> input) {

	#ifdef _AUSGABE
	for(unsigned i=0; i<input.size();i++) {
		cout << input[i] << " ";
	}

	cout << endl;
	#endif

	for (int i=1; i < input.size(); i++) {
		int temp = input[i];
		int j = i - 1;
 
		while (j >= 0 && input[j] > temp) {
		  input[j + 1] = input[j];
		  j--;
		}
 
		input[j+1] = temp;
		
		#ifdef _AUSGABE
		cout << "Durchlauf " << i << ": ";
		for(unsigned i=0; i<input.size();i++) {
			cout << input[i] << " ";
		}
		cout << endl;
		#endif
	}

}

// Selection Sort
void selectionsort(vector<int> input){
	#ifdef _AUSGABE
	for(unsigned i=0; i<input.size();i++) {
		cout << input[i] << " ";
	}

	cout << endl;
	#endif

	for (int i=0; i < input.size(); i++) {
		int temp = input[i];
		int j= i+1;
		int smallest = temp;
		int smallest_pos = i;
		while(j < input.size() ){
			if (input[j] < smallest) {
				smallest = input[j];
				smallest_pos = j;
			}
			j++;
		}
		if (smallest != temp){
			input[i] = input[smallest_pos];
			input[smallest_pos] = temp;
		}
	
		#ifdef _AUSGABE		
		cout << "Durchlauf " << i << ": ";
		for(unsigned i=0; i<input.size();i++) {
			cout << input[i] << " ";
		}
		cout << endl;
		#endif
	}

}

// Bubble Sort
void bubblesort(vector<int> input)  {
	
	#ifdef _AUSGABE
	for(unsigned i=0; i<input.size();i++) {
		cout << input[i] << " ";
	}
	cout << endl;
	#endif

	for(int i=input.size(); i>0; i--){
		for(int j=0; j<i-1 ; j++ ){
			if( input[j] > input[j+1]) {
				int temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			}
		}

		#ifdef _AUSGABE
		cout << "Durchlauf " << i << ": ";
		for(unsigned i=0; i<input.size();i++) {
			cout << input[i] << " ";
		}
		cout << endl;
		#endif

	}

}

// Shell Sort
void shellsort(vector<int> input) {
	
	#ifdef _AUSGABE
	for(unsigned i=0; i<input.size();i++) {
		cout << input[i] << " ";
	}
	cout << endl;
	#endif

	int gap = 0;

	while (gap > input.size()-1){
		gap = (gap*2)+1;
	}

	//int h[] = {7, 3, 1};

	int N = (int) input.size();
	// Schleife über die Abstandsfolge
	for (; gap > 0; gap = (gap-1)/2 ) { // H = Gap
		for (int i = gap; i < N; i++) {
			int tmp = input[i];
			int j = i;
			// Insertion Sort im Abstand von gap
			for (; j >= gap && tmp < input[j-gap]; j -= gap) {
				input[j] = input[j-gap];
			}
			input[j] = tmp;
		}
	}

	#ifdef _AUSGABE
	for(unsigned i=0; i<input.size();i++) {
		cout << input[i] << " ";
	}
	#endif

}

// Quick Sort
void quicksort(int links, int rechts, vector<int>& input){
	
	if( links < rechts ) {
		int i = links;
		int j = rechts;
		int pivot = (j + i)/2;
		pivot = input[pivot];

		#ifdef _AUSGABE
		cout << endl << "Vor Durchlauf: " << endl;
		
		for(unsigned i=0; i<input.size();i++) {
			cout << input[i] << " ";
		}
		cout << endl;

		cout << "links: " << i << " rechts: " << j << " pivot: " << pivot << endl;
		#endif


		while (i < j) {
		
			while (input[i] < pivot ) {
				i++;
			}
			while (pivot < input[j]){
				j--;
			}

			if ( i < j ){
				int temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}

		}

		#ifdef _AUSGABE
		cout << "Nach Durchlauf: " << endl;

		for(unsigned i=0; i<input.size();i++) {
			cout << input[i] << " ";
		}
		cout << endl;
		#endif

		quicksort(links, i-1, input);
		quicksort(i+1, rechts, input);

	}

	return;

}



// merge
void merge(vector<int> &a, vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd) {

	int leftEnd = rightPos-1;
	int tmpPos = leftPos;
	int numElements = (rightEnd - leftPos) +1;

	while((leftPos <= leftEnd)&&(rightPos <= rightEnd)){
		if (a[leftPos] <= a[rightPos]){
			tmpArray[tmpPos] = a[leftPos];
			tmpPos++;
			leftPos++;
		} else {
			tmpArray[tmpPos] = a[rightPos];
			tmpPos++;
			rightPos++;
		}
	}

	while(leftPos <= leftEnd){
		tmpArray[tmpPos] = a[leftPos];
		tmpPos++;
		leftPos++;
	}

	while(rightPos <= rightEnd){
		tmpArray[tmpPos] = a[rightPos];
		tmpPos++;
		rightPos++;
	}

	int i = 0;

	while( i < numElements ) {
		a[rightEnd] = tmpArray[rightEnd];
		i++;
		rightEnd--;
	}

}

// mergesort
void mergesort(vector<int> &a, vector<int> &tmpArray, int left, int right) {
	#ifdef _AUSGABE
		cout << "mergesort(" << left << ", " << right << ")" << endl;
	#endif


	if (left < right ) {
		int center = (left+right) /2;
		mergesort(a, tmpArray, left, center);
		mergesort(a, tmpArray, center+1, right);
		merge(a, tmpArray, left, center+1, right);
	}

}

// left child
int leftChild(int i){
	return 2*i+1;
}

// percdown
void percDown(vector<int> &a, int i, int n) {
	int child = i;
	int tmp = a[i];
	int j = i;

	while(leftChild(j) < n ){
		child = leftChild(j);
		if ( (child != n-1) && (a[child] > a[child+1])) {
			child++;
		}

		if (tmp > a[child] ){
			int temp = a[j];
			a[j] = a[child];
			a[child] = temp;

			j = child;
		} else {
			break;
		}
	}
}



// heapsort
void heapsort(vector<int> &a){
	int N = a.size();
	int i = N/2;

	while( i >= 0){
		percDown(a, i, N);
		i--;
	}

	int j = N-1;

	while(j > 0){
		int temp = a[0];
		a[0] = a[j];
		a[j] = temp;
	
		percDown(a, 0, j);
		j--;
	}
}


int main(){

	//int my_ints[] = {39, 12, 72, 11, 18, 46, 83, 21, 10, 1};
	int my_ints[] = {9, 5, 7, 3, 8, 1, 6, 2, 4};
	int leer[10] = {};
	vector<int> my_list (my_ints, my_ints + sizeof(my_ints) / sizeof(int) );

	clock_t start, end; // Zeitstempel
	float diff_time; // Differenz der Zeitstempel

	cout << "Insertionsort:" << endl;
	start = clock();
	insertionsort(my_list);
	end = clock();
	cout << endl;
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	cout << "Selectionsort:" << endl;
	start = clock();
	selectionsort(my_list);
	end = clock();
	cout << endl;
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	cout << "Bubblesort:" << endl;
	start = clock();
	bubblesort(my_list);
	end = clock();
	cout << endl;
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	cout << "Shellsort:" << endl;
	start = clock();
	shellsort(my_list);
	end = clock();
	cout << endl;
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;


	// -Aufgabe 6- //


	cout << "Quicksort:" << endl;
	quicksort(0, my_list.size()-1, my_list);
	cout << endl;
	
	// Mergesort:
	vector<int> my_list_2 (my_ints, my_ints + sizeof(my_ints) / sizeof(int) );
	vector<int> temp_list (leer, leer + sizeof(leer) / sizeof(int) );
	for(unsigned i=0; i<my_list_2.size() ;i++) {
		cout << my_list_2[i] << " ";
	}
	cout << endl;
	cout << "Mergesort:" << endl;
	start = clock();
	mergesort(my_list_2, temp_list, 0, 9);
	end = clock();
	for(unsigned i=0; i<temp_list.size() ;i++) {
		cout << temp_list[i] << " ";
	}
	cout << endl;
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	//Heapsort:
	vector<int> my_list_3 (my_ints, my_ints + sizeof(my_ints) / sizeof(int) );
	for(unsigned i=0; i<my_list_3.size() ;i++) {
		cout << my_list_3[i] << " ";
	}
	cout << endl;
	cout << "Heapsort:" << endl;
	start = clock();
	heapsort(my_list_3);
	end = clock();
	for(unsigned i=0; i<my_list_3.size() ;i++) {
		cout << my_list_3[i] << " ";
	}
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	// - Aufgabe 7 - Benchmarks - //

	int max = 10;
	int zufall[10] = {};
	int leer_bench[10] = {};
	srand ((unsigned int) time (NULL));

	for (int i = 0; i<(max-1); i++){
		zufall[i] = i+1;
	}

	for (int i = 0; i<max-1; i++){
		int random1 = (rand()%(max-1)) + 1;
		int temp = zufall[i];
		zufall[i] = zufall[random1];
		zufall[random1] = temp;
	}

	ofstream output;
	output.open("zahlen.txt", ios::out);

	for (int i = 0; i<max-1; i++){
		output << zufall[i] << " ";
	}

	output.close();

	vector<int> zufall_1 (zufall, zufall + sizeof(zufall) / sizeof(int) );
	vector<int> empty (leer_bench, leer_bench + sizeof(leer_bench) / sizeof(int) );

	// Sorting starts here:

	cout << endl << "Starting Benchmarks:" << endl << endl;

	// Insertionsort:
	cout << "Insertionsort:" << endl;
	start = clock();
	insertionsort(zufall_1);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	// Selectionsort:
	cout << "Selectionsort:" << endl;
	start = clock();
	selectionsort(zufall_1);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	// Bubblesort:
	cout << "Bubblesort:" << endl;
	start = clock();
	bubblesort(zufall_1);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	// Shellsort:
	cout << "Shellsort:" << endl;
	start = clock();
	shellsort(zufall_1);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	// Quicksort:
	cout << "Quicksort:" << endl;
	start = clock();
	quicksort(0, zufall_1.size()-1, zufall_1);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;
	
	// Mergesort:
	vector<int> zufall_2 (zufall, zufall + sizeof(zufall) / sizeof(int) );
	cout << "Mergesort:" << endl;
	start = clock();
	mergesort(zufall_2, temp_list, 0, 9);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;

	//Heapsort:
	vector<int> zufall_3 (zufall, zufall + sizeof(zufall) / sizeof(int) );	
	cout << "Heapsort:" << endl;
	start = clock();
	heapsort(zufall_3);
	end = clock();
	diff_time = ((float)(end-start)/CLOCKS_PER_SEC);
	cout << "\t" << diff_time << " sec" << endl;


	system("PAUSE");
	return 0;

}