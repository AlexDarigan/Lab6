// Student Name	: David Darigan
// Student ID	: C00263218
#pragma once
#include <fstream>
#include <string>
#include <vector>

bool is_whitespace(char character) { return (character == ' ') || (character == '\n'); };

std::string read_file(const std::string& filepath) {
	std::string text;
	std::string line;
	std::ifstream file(filepath);
	while (std::getline(file, line)) {
		text += line;
		text += "\n";
	}
	return text;
}

int skip_whitespace(const std::string& text, int position) {
	// We exit out at -1 because the ++ in the for loop will reach the next word
	while(is_whitespace(text.at(position)) && position < text.length() - 1) {
		position++;
	}
	return position;
}

std::vector<std::string> split_text(const std::string& text) {
	std::vector<std::string> words;
	std::string word = "";
	for (int pos = 0; pos < text.length(); pos++) {
		char current = text.at(pos);
		if (is_whitespace(current)) {
			words.push_back(word);
			word = "";
			pos = skip_whitespace(text, pos);
		}
		else {
			word += text.at(pos);
		}
	}
	std::cout << words.size();
	/*for (int i = 0; i < words.size(); i++) {
		std::cout << "|" << words.at(i) << "|" << std::endl;
	}*/
	return words;
}

//std::map<std::string, bool> get_words() {
//	std::string text = read_file("words.txt");
//	std::string line;
//	while (std::getline, )
//
//}