// Day 11: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be a single line
// of comma separated integers.

// This one actually was a pain to implement. The spec's a little vague on how it wants the input
// and extra characters to be treated. This should get it out in the end.

#include <iostream>

#include "HexEd.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day11;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	HexEd he(argv[1]);

#ifndef AOC_PART2
	std::cout << he.StepsAway() << "\n";
#else
	std::cout << he.MostStepsAway() << "\n";
#endif

	return 0;
}