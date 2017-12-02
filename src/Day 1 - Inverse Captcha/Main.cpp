// Day 1: Main.cpp
// Just begins the program's execution. For this program, you must pass a number as a commandline
// argument, and the output will be the required sum for this problem.

// Both parts of this program require that the user inputs a string, and they calculate some value
// from them. The actual calculation is different for each part, but because the rest is the same,
// it's easy to just reuse this section and use a compiler flag to indicate the difference.

#include <iostream>

#include "InverseCaptcha.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day1;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input string]\n";
		return 1;                                                                                   
	}

	InverseCaptcha ic(argv[1]);
	std::cout << ic.Sum() << "\n";

	return 0;
}