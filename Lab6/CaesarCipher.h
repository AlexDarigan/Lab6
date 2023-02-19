// Student Name	: David Darigan
// Student ID	: C00263218
#pragma once
#include <string>

char right_shift(char input, int r_shift) {
	return (((input - 'a') + r_shift) % 26) + 'a';
}

char left_shift(char input, int l_shift) {
	return (((input - 'a') - l_shift) % 26) + 'a';
}

std::string encrypt(std::string& plain_text, int r_shift) {
	std::string encrypted = "";
	for (int pos = 0; pos < plain_text.length(); pos++) {
		char current = plain_text.at(pos);
		encrypted += (current != ' ' ? right_shift(current, r_shift) : current);
	}
	return encrypted;
}

std::string decrypt(std::string& encrypted, int l_shift) {
	std::string plain_text = "";
	for (int pos = 0; pos < encrypted.length(); pos++) {
		char current = encrypted.at(pos);
		plain_text += (current != ' ' ? left_shift(current, l_shift) : current);
	}
	return plain_text;
}