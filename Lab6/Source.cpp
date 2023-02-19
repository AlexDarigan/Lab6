// Student Name	: David Darigan
// Student ID	: C00263218
//
#pragma once
#include <iostream>
#include "FileIO.h"
#include "CaesarCipher.h"

void encrypt_with_user_key(const std::string &plaintext) {
	std::cout << "Text to encrypt" << std::endl << plaintext << std::endl;
	int key = 0;
	while (key < 1) {
		std::cout << "Please enter an encryption key as a positive int greater than 0" << std::endl;
		std::cin >> key;
	}
	std::cout << encrypt(plaintext, key) << std::endl;
}

void guess_key_for_decryption(const std::string& encrypted_text) {
	std::cout << "Text to decrypt" << std::endl << encrypted_text << std::endl;
	char input = 'n';
	std::string decrypted = "";
	for (int guess = 0; guess < 25; guess++) {
		decrypted = decrypt(encrypted_text, guess);
		get_frequencies(decrypted);
		std::vector<std::string> words = split_text(decrypted);
		int word_count = count_real_words(split_text(decrypted), WORD_FREQUENCY_MAP);
		if (word_count > (words.size() / 2)) {
			std::cout << decrypted;
			std::cout << std::endl << "This text was decrypted with a key of " << guess << ". Is it correct (y / n)?  " << std::endl;
			std::cin >> input;
			if (tolower(input) == 'y') {
				return;
			}
		}
	}
}
 
int main() {
	encrypt_with_user_key(read_file("plaintext1.txt"));
	guess_key_for_decryption(read_file("encrypttext5.txt"));
}