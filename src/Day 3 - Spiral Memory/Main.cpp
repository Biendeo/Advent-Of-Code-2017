// Day 3: Main.cpp
// Just beings the program's execution. For this program, you must pass the input number as a
// commandline argument to the program.

// Same deal as yesterday's: both parts are separate functions, that are called depending on the
// preprocessor argument.

#include <iostream>

#include "SpiralMemory.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day3;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [target square]\n";
		return 1;
	}

	SpiralMemory sm(std::atoi(argv[1]));

#ifndef AOC_PART2
	std::cout << sm.StepsToTarget() << "\n";
#else
	std::cout << sm.FirstGreaterSquare() << "\n";
#endif

	return 0;
}