#include <iostream>
#include <string>
#include <random>

using namespace std;

string keyGenerate(size_t size) {
	string key;
	for (int i = 0; i < size; i++) {
		key += (rand()%(26-1+1)+1) % 26 + 'a';
	}
	return key;
}
string vernamEncypt(string plaintext, string key) {
	string ciphertext;
	for (int i = 0; i < key.length(); i++) {
		ciphertext += char((int)plaintext[i] ^ (int)key[i]);
	}
	return ciphertext;
}
string vernamDecypt(string ciphertext, string key) {
	string plaintext;
	for (int i = 0; i < key.length(); i++) {
		plaintext += char((int)ciphertext[i] ^ (int)key[i]);
	}
	return plaintext;
}


void main() {
	string p = "helloworld", c = "", k = "";
	for (int i = 0; i < 20; i++) {
		k = keyGenerate(p.length());
		c = vernamEncypt(p, k); cout << "ciphertext[" << i << "]:\t" << c << endl;
		p = vernamDecypt(c, k); cout << "plaintext[" << i << "]:\t" << p << endl;
		cout << endl << endl;
	}
}