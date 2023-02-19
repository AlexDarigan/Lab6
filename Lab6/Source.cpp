// Student Name	: David Darigan
// Student ID	: C00263218
//
#pragma once
#include <iostream>
#include "FileIO.h"
#include "CaesarCipher.h"

void encrypt_with_user_key(const std::string &plaintext) {
	int key = 0;
	while (key < 1) {
		std::cout << "Please enter an encryption key as a positive int greater than 0" << std::endl;
		std::cin >> key;
	}
	std::cout << encrypt(plaintext, key);
}

void guess_key_for_decryption(const std::string& encrypted_text) {
	std::map<std::string, bool> word_frequency = map_words(split_text("words.txt"));
	char input = 'n';
	for (int guess = 5; guess < 25; guess++) {
		std::cout << decrypt(encrypted_text, guess);
		// Add a word check here somehow?
		std::cout << std::endl << "This text was decrypted with a key of " << guess << ". Is it correct?  " << std::endl;
		std::cin >> input;
		if (tolower(input) == 'y') {
			return;
		}
	}
}

//char right_shift(char input, int r_shift) { return (((input - 'a') + r_shift) % 25) + 'a'; }
//char left_shift(char input, int l_shift) { return (((input - 'a') - l_shift) % 25) + 'a'; }
 
int main() {
	//std::cout << encrypt(read_file("plaintext1.txt"), 5) << std::endl;
	//std::cout << ('z' + 1) - 'a' << std::endl;
	////std::cout << int('/');
	//std::cout << 25 % 25;

	/*std::cout << 'a' - 'a' << std::endl;
	std::cout << 'z' - 'a' << std::endl;
	std::cout << right_shift('a', 25) << std::endl;
	std::cout << left_shift('z', 25) << std::endl;
	std::cout << 'y' + 5 << std::endl;
	int x = '`';
	std::cout << x;*/

	//int a = 'a';
	//int y = 'y';
	//int tick = '`';
	//std::cout << "a: " << a << std::endl;
	//std::cout << "y: " << y << std::endl;
	//std::cout << "`: " << tick << std::endl;
	//std::cout << ((('y' - 'a') + 5) % 26) + 'a' << std::endl;
	//char hundred1 = 101;
	//std::cout << hundred1 << std::endl;

	////std::cout << (abs((('d' - 'a')) - 5) % 26) + 'a' << std::endl;
	////int r = (('d' - 'a') - 5) % 26;
	////std::cout << r << std::endl;
	////std::cout << r + 26 + 'a' << std::endl;

	//int decrypted = (('d' - 'a') - 5) % 26;
	///*while (decrypted < 0) {
	//	decrypted += 26;
	//}*/
	//std::cout << decrypted + 'a';


	//std::cout << 'y' - 'a';
	/*int a = 'a';
	int y = 'y';
	int underscore = '_';
	std::cout << a;
	std::cout << std::endl;
	std::cout << y;
	std::cout << std::endl;
	std::cout << underscore;*/
	//WORD_FREQUENCY_MAP["3D"] = true;
	//std::cout << WORD_FREQUENCY_MAP["3D"];
	//encrypt_with_user_key(read_file("plaintext1.txt"));
	//split_text(read_file("words.txt"));
	guess_key_for_decryption(read_file("encrypttext5.txt"));
	////std::string text = read_file("plaintext1.txt");
	////std::cout << text << std::endl;
	////std::cout << encrypt(text, 3);
}