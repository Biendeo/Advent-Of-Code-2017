// Day 13: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should describe which
// depths have windows, and how wide they are.

// This one involved a little bit of trickery, but it seemed to work out.

#include <iostream>

#include "PacketScanner.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day13;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	PacketScanner ps(argv[1]);

#ifndef AOC_PART2
	std::cout << ps.Severity() << "\n";
#else
	std::cout << ps.Delay() << "\n";
#endif

	return 0;
}