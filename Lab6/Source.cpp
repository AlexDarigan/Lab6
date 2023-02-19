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
	char input = 'n';
	while (input != 'y') {
		std::cout << "This text was decrypted with a key of ?. Is it correct?" << std::endl;
		std::cin >> input;
	}
}
 
int main() {
	//encrypt_with_user_key(read_file("plaintext1.txt"));
	split_text(read_file("words.txt"));
	//guess_decryption_key(read_file("")
	//std::string text = read_file("plaintext1.txt");
	//std::cout << text << std::endl;
	//std::cout << encrypt(text, 3);
}