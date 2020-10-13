#include "VigCipher.h"
#include <time.h>

string VCencrypt::createKey(string str, string key) {// this function take in the original text and original keyword 
	int x = str.size();								 // to create a key that matched the length of the original text

	for (int i = 0; ; i++) {
		if (key.size() == str.size()) break;
		else key.push_back(key[i]);
	}
	return key;
}

string VCencrypt::cipherTxt(string str, string key) {//with the key that is same length of the original text, 
	string cipher;									 //we use ascii number to find sum of ascii codes of text and key

	for (int i = 0; i < str.size(); i++) {
		char x = (str[i] + key[i]) % 26;
		x += 'A';

		cipher.push_back(x);
	}
	return cipher;
}

string VCencrypt::encrypt(){						//function that calls "createKey" and "cipherTxt" functions
	passedKey = createKey(ORIGIN_TXT, ORIGIN_KEY);
	encriptedMsg = cipherTxt(ORIGIN_TXT, passedKey);
	return encriptedMsg;
}

int VCencrypt::random_num(int start, int end) {		//generate random number
	//srand(time(NULL));
	int range = (end - start) + 1;
	int random_int = start + (rand() % range);
	return random_int;
}

char VCencrypt::mutated_key(){						//uses the generated randome number to assign random character
	int r = random_num(0, GENES.size() - 1);
	return GENES[r];
}

string VCencrypt::create_gnome(){					//uses the generated character to create a key with random characters
	string gnome = "";
	for (int i = 0; i < ORIGIN_TXT.size(); i++)
		gnome += mutated_key();
	return gnome;
}

string VCencrypt::recombine(string gnome){			//generates a random probability
	string newGnome = "";							//if the probability is lower than 25%,
	int t = 0, p = 0;								//the concatinated string is made up of newly created random characters
	double prob = (double)random_num(0, 100) / 100;	//if the probability is higher than 25%,
													//it uses the passed in character to be concatinated to the string
		for (int i = 0; i < gnome.size(); i++) {
			if (prob > 0.25) {
				newGnome += gnome[i]; p++;
			}
			else {
				newGnome += mutated_key();
			}
		} 
													//at the end of this task, we will inform the user that this key is 32 digits long and its % of probability
		cout <<"Your key-" <<newGnome<<" with length of"<<newGnome.size() <<" has " <<prob*100<<"% of chance to be a correct key. The correct key is "<<encriptedMsg<<endl<<endl;
	return newGnome;
}
