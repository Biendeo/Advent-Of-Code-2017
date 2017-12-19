// Day 19: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. The file should describe a diagram of paths.

// This one was much easier to implement.

#include <iostream>
#include <string>

#include "SeriesOfTubes.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day19;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	SeriesOfTubes sot(argv[1]);

	std::cout << sot.Letters() << "\n";

	return 0;
}