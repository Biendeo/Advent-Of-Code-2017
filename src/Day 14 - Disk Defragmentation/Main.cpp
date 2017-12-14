// Day 14: Main.cpp
// Just begins the program's execution. For this program, you must pass the input string as an
// argument.

// This one was really long because it involved handling cases, and required a copy-paste of day
// 10's hash algorithm. Definitely this was the most cumbersome one.

#include <iostream>

#include "DiskDefragmentation.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day14;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	DiskDefragmentation dd(argv[1]);

#ifndef AOC_PART2
	std::cout << dd.Squares() << "\n";
#else
	std::cout << dd.Regions() << "\n";
#endif

	return 0;
}