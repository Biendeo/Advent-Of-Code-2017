// Day 5: MTTAA.cpp
// Definitions for the class that calculates the number of steps to exit the maze.

#include "MTTAA.h"

#include <fstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day5::MTTAA::MTTAA(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	while (std::getline(f, line)) {
		offsets.push_back(std::stoi(line));
	}

	f.close();
}

int Biendeo::AdventOfCode2017::Day5::MTTAA::StepsToExit() {
	return cache.Get([&] {
		return CalculateStepsToExit();
	});
}

int Biendeo::AdventOfCode2017::Day5::MTTAA::CalculateStepsToExit() {
	// I'm going to purposefully hide the stored offsets so that they aren't changed.
	std::vector<int> offsets = this->offsets;
	size_t currentPos = 0;
	int steps = 0;

	while (currentPos >= 0 && currentPos < offsets.size()) {
#ifdef AOC_PART2
		if (offsets[currentPos] >= 3) {
			--offsets[currentPos];
			currentPos += offsets[currentPos] + 1;
		} else {
#endif
			++offsets[currentPos];
			currentPos += offsets[currentPos] - 1;
#ifdef AOC_PART2
		}
#endif
		++steps;
	}

	return steps;
}
