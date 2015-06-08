// Datum: 30.05.2014
#include "newhash.h"
#include <math.h>

// Primzahlen bis 1000:
const int newhash::prim[] = {2,     3,     5,     7,    11,    13,    17,    19,    23,    29,    31,    37,    41,    43,
   47,    53,    59,    61,    67,    71,    73,    79,    83,    89,    97,   101,   103,   107,
  109,   113,   127,   131,   137,   139,   149,   151,   157,   163,   167,   173,   179,   181,
  191,   193,   197,   199,   211,   223,   227,   229,   233,   239,   241,   251,   257,   263,
  269,   271,   277,   281,   283,   293,   307,   311,   313,   317,   331,   337,   347,   349,
  353,   359,   367,   373,   379,   383,   389,   397,   401,   409,   419,   421,   431,   433,
  439,   443,   449,   457,   461,   463,   467,   479,   487,   491,   499,   503,   509,   521,
  523,   541,   547,   557,   563,   569,   571,   577,   587,   593,   599,   601,   607,   613,
  617,   619,   631,   641,   643,   647,   653,   659,   661,   673,   677,   683,   691,   701,
  709,   719,   727,   733,   739,   743,   751,   757,   761,   769,   773,   787,   797,   809,
  811,   821,   823,   827,   829,   839,   853,   857,   859,   863,   877,   881,   883,   887,
  907,   911,   919,   929,   937,   941,   947,   953,   967,   971,   977,   983,   991,   997};

newhash::newhash(int size) {
	for (int i = 0; i<size;i++){
		hash_list.push_back(-1);
	}

	collision = 0;
}


newhash::~newhash(void) {
}

int newhash::hashValue(int key, int index) {

	int M = hash_list.size();
	int i = 0;

	switch (index) {

		// lineares Sondieren
		case 1: {
				int table_position = 0;

				table_position = (key+i)%M;

				while (hash_list[table_position] != -1 ){
					collision++;
					i++;
					table_position = (key+i)%M;				
				}
				return table_position;

		}

		// quadratisches Sondieren
		case 2: {
				int table_position = 0;

				table_position = (key+i)%M;

				while (hash_list[table_position] != -1 ){
					collision++;
					i++;
					int tmp = std::pow(i, 2.0);
					table_position = (key+tmp)%M;				
				}
				return table_position;

		}

		// doppeltes Hashing
		case 3: {
				int R = 0;
				int j = 0;

				while(R < M) {
					if (prim[j] < M) {
						R =	prim[j];
					} else {
						break;
					}
					j++;
				}

				int hash_2 = R-(key%R);
				int table_position = ((key+i)*hash_2)%M;

				while (hash_list[table_position] != -1 ){
					collision++;
					i++;
					table_position = ((key+i)*hash_2)%M;
				}

				return table_position;

		}

	}

}

int newhash::insert(int key, int index){
	int position = newhash::hashValue(key, index);

	hash_list[position] = key;

	return position;
}

float newhash::allocation(){
	float M = hash_list.size();
	float occupied = 0;

	for (int i = 0; i < M-1; i++){
		if(hash_list[i] != -1)
			occupied++;
	}
	float ratio = occupied/M;
	return ratio;
}

int newhash::rehash(int index) {
	std::vector<int> temp = hash_list;

	int old_size = hash_list.size();

	while (hash_list.size() > 0){
		hash_list.pop_back();
	};

	int new_size = 2*old_size;

	int i = 0;
	int prim_tmp = prim[i];

	while (new_size > prim_tmp) {
		i++;
		prim_tmp = prim[i];
	}

	new_size = prim_tmp;

	for (int j = 0;j<new_size;j++){
		hash_list.push_back(-1);
	}

	while (temp.size() > 0) {
		int tmp = temp.back();
		temp.pop_back();
		if (tmp != -1)
			newhash::insert(tmp, index);
	}

	return new_size;
}

int newhash::get_collisions(){
	return collision;
}