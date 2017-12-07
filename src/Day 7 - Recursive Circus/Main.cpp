// Day 7: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be of a specifc
// format describing a node's name, weight, and the names of its children.

// This one was done using two functions as before. Interestingly, it was useful to use the value
// from part 1 in part 2, so part 2 will cache both values nicely.

#include <iostream>

#include "RecursiveCircus.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day7;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	RecursiveCircus rc(argv[1]);

#ifndef AOC_PART2
	std::cout << rc.RootName() << "\n";
#else
	std::cout << rc.IncorrectWeight() << "\n";
#endif

	return 0;
}