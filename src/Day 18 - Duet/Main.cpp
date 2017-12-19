// Day 18: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. The file should describe the instructions that need to be
// computed.

// This one was pretty complex to implement, just because of all the weird edge cases and my ability
// to read instructions.

#include <iostream>
#include <string>

#include "Duet.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day18;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	Duet d(argv[1]);

#ifndef AOC_PART2
	std::cout << d.FirstRecover() << "\n";
#else
	std::cout << d.ProgramOneSends() << "\n";
#endif

	return 0;
}