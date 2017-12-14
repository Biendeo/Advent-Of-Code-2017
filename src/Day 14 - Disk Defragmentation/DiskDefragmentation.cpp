// Day 14: DiskDefragmentation.cpp
// Definitions for the class that counts squares and regions.

#include "DiskDefragmentation.h"

#include <array>
#include <iomanip>
#include <queue>
#include <set>
#include <sstream>

Biendeo::AdventOfCode2017::Day14::DiskDefragmentation::DiskDefragmentation(const std::string& input) {
	this->input = input;
}

int Biendeo::AdventOfCode2017::Day14::DiskDefragmentation::Squares() {
	return cache.Get([&] {
		return CalculateSquaresAndRegions();
	}).first;
}

int Biendeo::AdventOfCode2017::Day14::DiskDefragmentation::Regions() {
	return cache.Get([&] {
		return CalculateSquaresAndRegions();
	}).second;
}

std::pair<int, int> Biendeo::AdventOfCode2017::Day14::DiskDefragmentation::CalculateSquaresAndRegions() {
	// This all gets defaulted to false (which is empty);
	std::array<std::array<bool, SIZE>, SIZE> grid;
	int squares = 0;
	for (size_t row = 0; row < SIZE; ++row) {
		std::string hash = KnotHash(input + "-" + std::to_string(row));
		for (size_t column = 0; column < SIZE / 4; ++column) {
			switch (hash[column]) {
				case '0': // 0000
					squares += 0;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = false;
					break;
				case '1': // 0001
					squares += 1;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = true;
					break;
				case '2': // 0010
					squares += 1;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = false;
					break;
				case '3': // 0011
					squares += 2;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = true;
					break;
				case '4': // 0100
					squares += 1;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = false;
					break;
				case '5': // 0101
					squares += 2;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = true;
					break;
				case '6': // 0110
					squares += 2;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = false;
					break;
				case '7': // 0111
					squares += 3;
					grid[row][4 * column + 0] = false;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = true;
					break;
				case '8': // 1000
					squares += 1;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = false;
					break;
				case '9': // 1001
					squares += 2;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = true;
					break;
				case 'a': // 1010
					squares += 2;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = false;
					break;
				case 'b': // 1011
					squares += 3;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = false;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = true;
					break;
				case 'c': // 1100
					squares += 2;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = false;
					break;
				case 'd': // 1101
					squares += 3;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = false;
					grid[row][4 * column + 3] = true;
					break;
				case 'e': // 1110
					squares += 3;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = false;
					break;
				case 'f': // 1111
					squares += 4;
					grid[row][4 * column + 0] = true;
					grid[row][4 * column + 1] = true;
					grid[row][4 * column + 2] = true;
					grid[row][4 * column + 3] = true;
					break;
			}
		}
	}

	// This is not a particularly efficient solution but it works after a few seconds, so it's good
	// enough for the problem.
	int regions = 0;
	std::set<Pos2> checkedLocations;
	std::queue<Pos2> locationsToCheck;

	Pos2 currentLocation(0, 0);
	// Try and check every space.
	while (currentLocation < Pos2(0, SIZE)) {
		locationsToCheck.push(currentLocation);
		++regions;
		while (!locationsToCheck.empty()) {
			currentLocation = locationsToCheck.front();
			locationsToCheck.pop();
			checkedLocations.insert(currentLocation);
			if (currentLocation.x < SIZE - 1 && checkedLocations.find(Pos2(currentLocation.x + 1, currentLocation.y)) == checkedLocations.end() && grid[currentLocation.x + 1][currentLocation.y]) {
				locationsToCheck.push(Pos2(currentLocation.x + 1, currentLocation.y));
			}
			if (currentLocation.x > 0 && checkedLocations.find(Pos2(currentLocation.x - 1, currentLocation.y)) == checkedLocations.end() && grid[currentLocation.x - 1][currentLocation.y]) {
				locationsToCheck.push(Pos2(currentLocation.x - 1, currentLocation.y));
			}
			if (currentLocation.y < SIZE - 1 && checkedLocations.find(Pos2(currentLocation.x, currentLocation.y + 1)) == checkedLocations.end() && grid[currentLocation.x][currentLocation.y + 1]) {
				locationsToCheck.push(Pos2(currentLocation.x, currentLocation.y + 1));
			}
			if (currentLocation.y > 0 && checkedLocations.find(Pos2(currentLocation.x, currentLocation.y - 1)) == checkedLocations.end() && grid[currentLocation.x][currentLocation.y - 1]) {
				locationsToCheck.push(Pos2(currentLocation.x, currentLocation.y - 1));
			}
		}
		// To find a new space, we just look for the next square row-wise that we haven't seen.
		currentLocation = Pos2(0, 0);
		while (currentLocation < Pos2(0, SIZE) && (checkedLocations.find(currentLocation) != checkedLocations.end() || !grid[currentLocation.x][currentLocation.y])) {
			++currentLocation;
		}
	}

	return std::make_pair(squares, regions);
}

std::string Biendeo::AdventOfCode2017::Day14::DiskDefragmentation::KnotHash(const std::string& input) {
	// This was slightly adapted from day 10's implementation.
	std::string newInput = input + static_cast<char>(17) + static_cast<char>(31) + static_cast<char>(73) + static_cast<char>(47) + static_cast<char>(23);
	static const int NUM_ELEMENTS = 256;
	static const int NUM_LOOPS = 64;
	std::array<int, NUM_ELEMENTS> elements;
	for (int i = 0; i < NUM_ELEMENTS; ++i) {
		elements[i] = i;
	}
	size_t currentPosition = 0;
	int skipSize = 0;
	for (int j = 0; j < NUM_LOOPS; ++j) {
		for (int i = 0; i < newInput.size(); ++i) {
			std::array<int, NUM_ELEMENTS> copiedElements{elements};
			for (size_t pos = 0; pos < newInput[i]; ++pos) {
				copiedElements[(currentPosition + pos) % NUM_ELEMENTS] = elements[(currentPosition + newInput[i] - pos - 1) % NUM_ELEMENTS];
			}
			std::copy(copiedElements.begin(), copiedElements.end(), elements.begin());
			(currentPosition += (newInput[i] + skipSize)) %= NUM_ELEMENTS;
			++skipSize;
		}
	}
	std::stringstream ss;

	for (int i = 0; i < NUM_ELEMENTS; i += 16) {
		int hexDigit = elements[i];
		for (int j = i + 1; j < i + 16; ++j) {
			hexDigit ^= elements[j];
		}
		ss << std::setfill('0') << std::setw(2) << std::hex << hexDigit;
	}

	return ss.str();
}