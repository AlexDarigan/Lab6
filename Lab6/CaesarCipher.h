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

char left_shift(char input, int l_shift) {
	int shifted = ((input - 'a') - l_shift);
	while (shifted < 0) { shifted += 26; }
	return shifted + 'a';
}

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

	std::cout << "_" << std::endl;
	for (int i = 0; i < 26; i++) {
		char c = i + 'a';
		std::cout << c << " " << frequencies[i] << std::endl;
	}
	std::cout << "_" << std::endl;

	int sorted_size = 0;
	int size = 26;
	while (size > 0) {
		// Comparing Values, Want Indexes
		int most_freq_idx = 0;
		for (int i = 1; i < size; i++) {
			if (frequencies[i] > frequencies[most_freq_idx]) {
				most_freq_idx = i;
			}
		}

		// Add most_freq_idx to sorted
		sorted[sorted_size] = most_freq_idx + 'a';
		sorted_size++;

		// left-shift the array to close the gap
		for(int j = most_freq_idx; j < size - 1; j++) {
			frequencies[j] = frequencies[j + 1];
		}
		size--;
	}

	std::cout << "_" << std::endl;
	for (int i = 0; i < 26; i++) {
		std::cout << sorted[i] << ",";
	}
	std::cout << "_" << std::endl;
	return sorted;
}


