// Day 16: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. The file should describe the instructions that need to be
// computed.

// Thjis one is another ifdef guard one.

#include <iostream>
#include <string>

#include "PermutationPromenade.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day16;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	PermutationPromenade pp(argv[1]);

	std::cout << pp.FinalPositions() << "\n";

	return 0;
}