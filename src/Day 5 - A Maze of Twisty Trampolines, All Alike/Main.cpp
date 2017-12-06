// Day 5: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be one integer
// for each line.

// Same deal as yesterday.

#include <iostream>

#include "MTTAA.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day5;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	MTTAA mttaa(argv[1]);

	std::cout << mttaa.StepsToExit() << "\n";

	return 0;
}