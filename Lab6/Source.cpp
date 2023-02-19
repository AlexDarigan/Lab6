// Student Name	: David Darigan
// Student ID	: C00263218

#pragma once
#include <iostream>


char right_shift(char input, int r_shift) {
	return (((input - 'a') - r_shift) % 26) + 'a';
}

char left_shift(char input, int l_shift) {
	return (((input - 'a') + l_shift) % 26) + 'a';
}

std::string encrypt(std::string& plain_text) {
	return "";
}

std::string decrypt(std::string& encrypted_text) {
	return "";
}
 
int main() {
	std::cout << left_shift('d', 1) << std::endl;
	std::cout << right_shift('e', 1) << std::endl;

}