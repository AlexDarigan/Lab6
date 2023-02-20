// Student Name	: David Darigan
// Student ID	: C00263218

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

bool confirmed_by_user(std::string text, int guess, clock_t time) {
	char input = 'n';
	std::cout << text << std::endl;
	std::cout << "Time to decrypt: " << time << std::endl;
	std::cout << std::endl << "This text was decrypted with a key of " << guess << ". Is it correct (y / n)?  " << std::endl;
	std::cin >> input;
	return tolower(input) == 'y';
}

void guess_key_for_decryption(const std::string& encrypted_text) {
	clock_t begin = clock();
	std::cout << "Text to decrypt" << std::endl << encrypted_text << std::endl;
	char input = 'n';
	std::string decrypted = "";
	for (int guess = 0; guess < 25; guess++) {
		decrypted = decrypt(encrypted_text, guess);
		std::vector<std::string> words = split_text(decrypted);
		int word_count = count_real_words(words, WORD_FREQUENCY_MAP);
		if (word_count > (words.size() / 2)) {
			if (confirmed_by_user(decrypted, guess, clock() - begin)) { return; }
		}
	}
}

void better_guess_key_for_decryption(const std::string& encrypted_text) {
	clock_t begin = clock();
	std::cout << "Text to decrypt" << std::endl << encrypted_text << std::endl;
	
	std::string decrypted = "";
	char* freqs = get_frequencies(encrypted_text);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; i < 26; i++) {
			// Take most frequent letter in encrypted text, and subtract it against most frequent letters in English
			int guess = freqs[i] - LETTER_FREQUENCY_STR_DESC[j];
			decrypted = decrypt(encrypted_text, guess);
			std::vector<std::string> words = split_text(decrypted);
			int word_count = count_real_words(words, WORD_FREQUENCY_MAP);
			if (word_count > (words.size() / 2)) {
				if (confirmed_by_user(decrypted, guess, clock() - begin)) { return; }
			}
		}
	}
}
 
int main() {
	encrypt_with_user_key(read_file("plaintext1.txt"));
	guess_key_for_decryption(read_file("encrypttext5.txt"));
	better_guess_key_for_decryption(read_file("encrypttext5.txt"));
}