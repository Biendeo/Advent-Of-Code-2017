// Day 4: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be several rows
// of lower-case letter strings separated by spaces.

// We're back to day 1's splitting of the parts by just having a compile-time flag in the class
// itself. It still calls another function, but it's very nice and convenient how it works.

#include <iostream>

#include "HighEntropyPassPhrase.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day4;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	HighEntropyPassphrase hep(argv[1]);

	std::cout << hep.NumValid() << "\n";

	return 0;
}