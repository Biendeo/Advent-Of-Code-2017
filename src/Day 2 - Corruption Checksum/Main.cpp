// Day 2: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be several rows
// of integers separated by tabs.

// Similar to yesterday, the setup for both parts is the same. The difference here is not that
// fundamental with the original calculation though, so instead I made them separate functions
// entirely, and just used a pre-processor definition for which one gets called in Main instead.

#include <iostream>

#include "CorruptionChecksum.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day2;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	CorruptionChecksum cc(argv[1]);

#ifndef AOC_PART2
	std::cout << cc.ChecksumOne() << "\n";
#else
	std::cout << cc.ChecksumTwo() << "\n";
#endif

	return 0;
}