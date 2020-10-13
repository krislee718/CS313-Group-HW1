#include <iostream>
#include <vector>
#include <string>
#include <cmath> 

using namespace std;

class VCencrypt {
public:
//members:
	string ORIGIN_TXT = "THISHOMEWORKISHELLADIFFICULTAHHH";//this is the original msg
	string ORIGIN_KEY = "ASDFASDFASDFASDFASDFASDFASDFASDF";//this is the original key that was used to encrypt our Vigenere Cypher secret msg
	string GENES = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";// we will use this to create mutated string for the key combination
	int keySize = 32;// the size of the key is given. it is 32 digits long
	string passedKey;// this will be the key made from original key
	string encriptedMsg;// this is encripted secret msg
	string triedKey;// we will create and recombine keys to make better key 

	VCencrypt() {//constructor to give certain values to the Vigenere Cyper object
		ORIGIN_TXT = "THISHOMEWORKISHELLADIFFICULTAHHH";
		ORIGIN_KEY = "ASDFASDFASDFASDFASDFASDFASDFASDF";
		string GENES = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		keySize = 32;
		passedKey = "";
		encriptedMsg = encrypt();
		triedKey = create_gnome();
		triedKey = recombine(triedKey);
	}

//methods:
	string createKey(string str, string key);
	string cipherTxt(string str, string key);
	string encrypt();
	int random_num(int start, int end);
	char mutated_key();
	string create_gnome();
	string recombine(string r1);

};

