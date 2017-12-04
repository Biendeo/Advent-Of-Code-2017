// Day 2: CorruptionChecksum.cpp
// Definitions for the class that determines the corruption checksum.

#include "CorruptionChecksum.h"

#include <fstream>
#include <limits>
#include <string>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::CorruptionChecksum(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	while (std::getline(f, line)) {
		std::vector<std::string> currentRowStr = Split(line, '\t');
		std::vector<int> currentRowInt;
		for (const std::string& term : currentRowStr) {
			currentRowInt.push_back(std::stoi(term));
		}
		spreadsheet.push_back(currentRowInt);
	}

	f.close();
}

int Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::ChecksumOne() {
	return cacheOne.Get([&] {
		return CalculateChecksumOne();
	});
}

int Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::CalculateChecksumOne() {
	int currentChecksum = 0;

	for (const auto& row : spreadsheet) {
		int high = 0;
		int low = std::numeric_limits<int>::max();
		for (auto cell : row) {
			if (cell > high) {
				high = cell;
			}
			if (cell < low) {
				low = cell;
			}
		}
		currentChecksum += (high - low);
	}

	return currentChecksum;
}

int Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::ChecksumTwo() {
	return cacheTwo.Get([&] {
		return CalculateChecksumTwo();
	});
}

int Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::CalculateChecksumTwo() {
	int currentChecksum = 0;

	for (const auto& row : spreadsheet) {
		bool found = false;
		for (auto termOne : row) {
			for (auto termTwo : row) {
				// This is relying on every item in the row to be unique.
				if (termOne == termTwo) continue;
				if (termOne % termTwo == 0) {
					currentChecksum += (termOne / termTwo);
					found = true;
				}
				// An optimisation here.
				if (found) break;
			}
			if (found) break;
		}
	}

	return currentChecksum;
}
