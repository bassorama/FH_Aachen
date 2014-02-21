//Namespace missing, then namespace should be added to commands like cout etc
//#include <iostream>
//using namespace std;

#include <iostream>
using namespace std;


//This will not work as the main routine is missing:
//int foo() {

// This doesnt work as it returns an integer on ending the program
//main() {

int main() {

	// foo // works !

	/*
	foo
		// does work as well!
	bar
	*/

	//Putting a blockcomment into a blockcomment does not work

	// foo /* bar */ does work

	cout << "Hallo Welt" << endl;

	cout /* << "Hallo Welt" */ << endl; // Shows just an empty line (endl)

	/*
	B01.05 does not work due to a syntaxerror (see B01.03 Blockcomment in blockcomment)
	*/

	system("PAUSE");

	return 0;

}