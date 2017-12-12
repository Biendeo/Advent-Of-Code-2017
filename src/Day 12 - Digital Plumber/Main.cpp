// Day 12: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should describe each
// person and who they are connected to.

// The C++ solution to this was incredibly neat because of how sets are implemented. This should be
// quite quick to run.

#include <iostream>

#include "DigitalPlumber.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day12;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	DigitalPlumber dp(argv[1]);

#ifndef AOC_PART2
	std::cout << dp.ConnectionsToZero() << "\n";
#else
	std::cout << dp.HowManyGroups() << "\n";
#endif

	return 0;
}