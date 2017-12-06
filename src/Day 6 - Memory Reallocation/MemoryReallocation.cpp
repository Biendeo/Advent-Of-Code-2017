// Day 6: MemoryReallocation.cpp
// Definitions for the class that calculates the number of steps to exit the maze.

#include "MemoryReallocation.h"

#include <fstream>
#include <map>
#include <set>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day6::MemoryReallocation::MemoryReallocation(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	std::getline(f, line);
	auto lineSplit = Split(line, '\t');
	for (size_t pos = 0; pos < NUM_BANKS; ++pos) {
		initial[pos] = std::stoi(lineSplit[pos]);
	}

	f.close();
}

std::pair<int, int> Biendeo::AdventOfCode2017::Day6::MemoryReallocation::Cycles() {
	return cache.Get([&] {
		return CalculateCycles();
	});
}

std::pair<int, int> Biendeo::AdventOfCode2017::Day6::MemoryReallocation::CalculateCycles() {
	// I never knew arrays had in-built lexographic comparison operators. That's nice.
	std::set<std::array<int, NUM_BANKS>> seenBanks;
	// For part 2, I'll store the arrays as keys, and when I saw them as a value. This is a bit
	// memory inefficient, but it provides a quick lookup at the end.
	std::map<std::array<int, NUM_BANKS>, int> bankSeenPosition;

	int cycles = 0;
	std::array<int, NUM_BANKS> currentBank = initial;

	while (seenBanks.find(currentBank) == seenBanks.end()) {
		seenBanks.insert(currentBank);
		bankSeenPosition.insert(std::make_pair(currentBank, cycles));
		// First, find the element with the highest value.
		int highestValue = 0;
		size_t highestPos = 0;
		// I'm using ints here just to ensure the equality check here works.
		for (int pos = NUM_BANKS - 1; pos >= 0; --pos) {
			if (currentBank[pos] >= highestValue) {
				highestValue = currentBank[pos];
				highestPos = pos;
			}
		}
		// Then, we make it zero and spread the value it has.
		std::array<int, NUM_BANKS> newBank = currentBank;
		newBank[highestPos] = 0;
		size_t pos = highestPos + 1;
		for (int i = 0; i < currentBank[highestPos]; ++i) {
			while (pos >= NUM_BANKS) {
				pos -= NUM_BANKS;
			}
			// Doing ++newBank[pos] doesn't work, which is quite interesting.
			newBank[pos] += 1;
			++pos;
		}
		currentBank = newBank;
		++cycles;
	};

	// It's convenient to return both parts at the same time.
	return std::make_pair(cycles, cycles - bankSeenPosition.at(currentBank));
}
