// Day 17: Main.cpp
// Just begins the program's execution. For this program, you must pass the input integer as a
// command-line argument.

// This one is another ifdef guard one.

#include <iostream>
#include <string>

#include "Spinlock.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day17;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input number]\n";
		return 1;
	}

	Spinlock s(std::stoi(argv[1]));

	std::cout << s.ValueAfter2017() << "\n";


	return 0;
}