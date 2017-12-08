// Day 8: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be of a specifc
// format describing how much a register gets incremented or decremented by, and what condition
// should be true for it to do that.

// I decided to make one function that determines both results, since that'd be very easy to slot
// in. I decided just to make the results two separate functions, but they're both cached into
// the same value, so if you were to try and access both functions, it'd only run it once, which
// is nice.

#include <iostream>

#include "IHYLR.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day8;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	IHYLR rc(argv[1]);

#ifndef AOC_PART2
	std::cout << rc.LargestValueAtEnd() << "\n";
#else
	std::cout << rc.LargestValueAtAnyPoint() << "\n";
#endif

	return 0;
}