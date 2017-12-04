// Day 4: HighEntropyPassphrase.cpp
// Definitions for the class that determines the validity of passphrases.

#include "HighEntropyPassphrase.h"
#include "StringFunctions.h"

#include <algorithm>
#include <fstream>

Biendeo::AdventOfCode2017::Day4::HighEntropyPassphrase::HighEntropyPassphrase(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	while (std::getline(f, line)) {
		passphrases.push_back(Split(line, ' '));
	}

	f.close();
}

int Biendeo::AdventOfCode2017::Day4::HighEntropyPassphrase::NumValid() {
	return cache.Get([&] {
		return CalculateNumValid();
	});
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
