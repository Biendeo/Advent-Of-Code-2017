// Day 10: KnotHash.cpp
// Definitions for the class that hashes the values.

#include "KnotHash.h"

#include <array>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day10::KnotHash::KnotHash(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	std::getline(f, str);
	std::vector<std::string> splitString = Split(str, ',');
	for (const std::string& s : splitString) {
		lengths.push_back(std::stoi(s));
	}
	for (const char c : str) {
		lengthsASCII.push_back(c);
	}
	lengthsASCII.push_back(17);
	lengthsASCII.push_back(31);
	lengthsASCII.push_back(73);
	lengthsASCII.push_back(47);
	lengthsASCII.push_back(23);
	f.close();
}

int Biendeo::AdventOfCode2017::Day10::KnotHash::FirstTwoProducts() {
	return firstTwoProductsCache.Get([&] {
		return CalculateFirstTwoProducts();
	});
}

std::string Biendeo::AdventOfCode2017::Day10::KnotHash::Hash() {
	return hashCache.Get([&] {
		return CalculateHash();
	});
}

int Biendeo::AdventOfCode2017::Day10::KnotHash::CalculateFirstTwoProducts() {
	std::array<int, NUM_ELEMENTS> elements;
	for (int i = 0; i < NUM_ELEMENTS; ++i) {
		elements[i] = i;
	}
	size_t currentPosition = 0;
	for (int skipSize = 0; skipSize < lengths.size(); ++skipSize) {
		std::array<int, NUM_ELEMENTS> copiedElements{elements};
		for (size_t pos = 0; pos < lengths[skipSize]; ++pos) {
			copiedElements[(currentPosition + pos) % NUM_ELEMENTS] = elements[(currentPosition + lengths[skipSize] - pos - 1) % NUM_ELEMENTS];
		}
		std::copy(copiedElements.begin(), copiedElements.end(), elements.begin());
		(currentPosition += (lengths[skipSize] + skipSize)) %= NUM_ELEMENTS;
	}

	return elements[0] * elements[1];
}

std::string Biendeo::AdventOfCode2017::Day10::KnotHash::CalculateHash() {
	// I'm just lazy and copy-pasting this from the first part with some minor tweaks.
	std::array<int, NUM_ELEMENTS> elements;
	for (int i = 0; i < NUM_ELEMENTS; ++i) {
		elements[i] = i;
	}
	size_t currentPosition = 0;
	int skipSize = 0;
	for (int j = 0; j < NUM_LOOPS; ++j) {
		for (int i = 0; i < lengthsASCII.size(); ++i) {
			std::array<int, NUM_ELEMENTS> copiedElements{elements};
			for (size_t pos = 0; pos < lengthsASCII[i]; ++pos) {
				copiedElements[(currentPosition + pos) % NUM_ELEMENTS] = elements[(currentPosition + lengthsASCII[i] - pos - 1) % NUM_ELEMENTS];
			}
			std::copy(copiedElements.begin(), copiedElements.end(), elements.begin());
			(currentPosition += (lengthsASCII[i] + skipSize)) %= NUM_ELEMENTS;
			++skipSize;
		}
	}
	// Now, to generate the hash.
	std::stringstream ss;

	ss << std::setfill('0') << std::setw(2) << std::hex;

	for (int i = 0; i < NUM_ELEMENTS; i += 16) {
		int hexDigit = elements[i];
		for (int j = i + 1; j < i + 16; ++j) {
			hexDigit ^= elements[j];
		}
		ss << hexDigit;
	}

	return ss.str();
}