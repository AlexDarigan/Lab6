// Student Name	: David Darigan
// Student ID	: C00263218
#pragma once
#include <string>
#include <map>
#include <iostream>

std::map<std::string, bool> map_words(std::vector<std::string> words);
const std::string LETTER_FREQUENCY_STR_DESC = "etainoshrdlucmfwygpbvkqjx";
const std::map<std::string, bool> WORD_FREQUENCY_MAP = map_words(split_text(read_file("words.txt")));


std::map<std::string, bool> map_words(std::vector<std::string> words) {
	std::cout << "Generating large amount of words" << std::endl;
	std::map<std::string, bool> word_freq_map;
	for (int i = 0; i < words.size(); i++) {
		word_freq_map[words.at(i)] = false;
	}
	std::cout << "Finished loading words" << std::endl << std::endl;
	return word_freq_map;
}

bool is_alpha(char character) { return (('a' <= character) && (character <= 'z')); }
char right_shift(char input, int r_shift) { return (((input - 'a') + r_shift) % 26) + 'a'; }
char left_shift(char input, int l_shift) { return ((((input - 'a') - l_shift) + 26) % 26) + 'a'; }

std::string encrypt(const std::string& plain_text, int r_shift) {
	std::string encrypted = "";
	for (int pos = 0; pos < plain_text.length(); pos++) {
		char current = plain_text.at(pos);
		encrypted += is_alpha(current) ? right_shift(current, r_shift) : current;
	}
	return encrypted;
}

std::string decrypt(const std::string& encrypted, int l_shift) {
	std::string plain_text = "";
	for (int pos = 0; pos < encrypted.length(); pos++) {
		char current = encrypted.at(pos);
		plain_text += is_alpha(current) ? left_shift(current, l_shift) : current;
	}
	return plain_text;
}

int count_real_words(std::vector<std::string> words, std::map<std::string, bool> wordmap) {
	int word_count = 0;
	for (int i = 0; i < words.size(); i++) {
		word_count += wordmap.count(words[i]);
	}
	return word_count;
}

char* get_frequencies(const std::string &text) {
	char sorted[26] = { ' ' };
	int frequencies[26] = { 0 };
	for (int i = 0; i < text.length(); i++) {
		frequencies[text.at(i) - 'a']++;
	}

	int sorted_size = 0;
	int size = 26;
	while (sorted_size < 26) {
		int most_freq_idx = 0;
		for (int i = 1; i < size; i++) {
			if (frequencies[i] >= frequencies[most_freq_idx]) {
				most_freq_idx = i;
			}
		}

		frequencies[most_freq_idx] = -1;
		sorted[sorted_size] = most_freq_idx + 'a';
		sorted_size++;
	}

	return sorted;
}


