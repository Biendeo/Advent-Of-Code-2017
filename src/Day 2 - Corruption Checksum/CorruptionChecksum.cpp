// Day 2: CorruptionChecksum.cpp
// Definitions for the class that determines the corruption checksum.

#include "CorruptionChecksum.h"

#include <fstream>
#include <limits>
#include <string>

Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::CorruptionChecksum(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	while (std::getline(f, line)) {
		std::vector<int> currentRow;
		std::string currentTerm;
		for (auto c : line) {
			// In the example, the separating characters were spaces, but in the input, they're
			// tabs. Tweak this if the input changes.
			if (c != '\t') {
				currentTerm += c;
			} else {
				currentRow.push_back(std::stoi(currentTerm));
				currentTerm = "";
			}
		}
		// I'm relying on the fact that each row has at least one element and does not have any
		// trailing characters.
		currentRow.push_back(std::stoi(currentTerm));
		spreadsheet.push_back(currentRow);
	}

	f.close();
}

int Biendeo::AdventOfCode2017::Day2::CorruptionChecksum::ChecksumOne() {
	if (!checksumOne.calculated) {
		checksumOne.value = CalculateChecksumOne();
		checksumOne.calculated = true;
	}
	return checksumOne.value;
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
	if (!checksumTwo.calculated) {
		checksumTwo.value = CalculateChecksumTwo();
		checksumTwo.calculated = true;
	}
	return checksumTwo.value;
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
