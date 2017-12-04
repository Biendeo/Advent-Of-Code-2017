// Common: StringFunctions.cpp
// Useful functions for operating on strings.

#include "StringFunctions.h"

#include <algorithm>

bool Biendeo::AdventOfCode2017::IsAnagram(const std::string& a, const std::string& b) {
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

std::vector<std::string> Biendeo::AdventOfCode2017::Split(const std::string& str, const char delimiter) {
	std::vector<std::string> splitString;
	std::string currentTerm;
	// Could this be faster?
	for (auto c : str) {
		if (c != delimiter) {
			currentTerm += c;
		} else {
			splitString.push_back(currentTerm);
			currentTerm = "";
		}
	}
	splitString.push_back(currentTerm);
	return splitString;
}