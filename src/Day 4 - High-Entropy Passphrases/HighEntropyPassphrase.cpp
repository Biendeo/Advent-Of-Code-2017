// Day 4: HighEntropyPassphrase.cpp
// Definitions for the class that determines the validity of passphrases.

#include "HighEntropyPassphrase.h"

#include <algorithm>
#include <fstream>

Biendeo::AdventOfCode2017::Day4::HighEntropyPassphrase::HighEntropyPassphrase(const std::string& inputFile) {
	// This is all copy-paste from day 2. The split function especially would be useful to isolate.
	std::ifstream f(inputFile);
	std::string line;

	while (std::getline(f, line)) {
		std::vector<std::string> currentRow;
		std::string currentTerm;
		for (auto c : line) {
			if (c != ' ') {
				currentTerm += c;
			} else {
				currentRow.push_back(currentTerm);
				currentTerm = "";
			}
		}
		currentRow.push_back(currentTerm);
		// For much larger sample sizes, sorting this would be more efficient.
		passphrases.push_back(currentRow);
	}

	f.close();
}

int Biendeo::AdventOfCode2017::Day4::HighEntropyPassphrase::NumValid() {
	// I really ought to turn this into a template.
	if (!part1Cache.calculated) {
		part1Cache.value = CalculateNumValid();
		part1Cache.calculated = true;
	}
	return part1Cache.value;
}

int Biendeo::AdventOfCode2017::Day4::HighEntropyPassphrase::CalculateNumValid() {
	int count = 0;

	// Just scan through each pair of words, and see if they match (either equal or are anagrams).
	for (const auto& passphrase : passphrases) {
		++count;
		bool valid = true;
		for (size_t i = 0; i < passphrase.size(); ++i) {
			for (size_t j = i + 1; j < passphrase.size(); ++j) {
#ifndef AOC_PART2
				if (passphrase[i] == passphrase[j]) {
#else
				if (IsAnagram(passphrase[i], passphrase[j])) {
#endif
					valid = false;
					--count;
					break;
				}
			}
			if (!valid) break;
		}
	}

	return count;
}

bool Biendeo::AdventOfCode2017::Day4::HighEntropyPassphrase::IsAnagram(const std::string& a, const std::string& b) {
	// First, save some time by exiting early if the strings are of different length.
	if (a.size() != b.size()) {
		return false;
	}

	// To figure out if they're anagrams, we just sort the strings internally (ie. write the
	// characters in alphabetical order), and then if the two strings are equal, you know they must
	// have the same letters.
	std::string sortedA = a, sortedB = b;
	std::sort(sortedA.begin(), sortedA.end());
	std::sort(sortedB.begin(), sortedB.end());

	return sortedA == sortedB;
}
