// Day 9: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be a single line
// of characters.

// Same deal as yesterday for structure. This one ended up being very brief.

#include <iostream>

#include "StreamProcessing.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day9;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	StreamProcessing sp(argv[1]);

#ifndef AOC_PART2
	std::cout << sp.Score() << "\n";
#else
	std::cout << sp.Garbage() << "\n";
#endif

	return 0;
}