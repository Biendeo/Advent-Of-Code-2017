// Day 15: Main.cpp
// Just begins the program's execution. For this program, you must pass both starting values as
// command-line arguments.

// Unlike yesterday, this one was very short. It just involved some ifdef guards and an encapsulated
// function to work.

#include <iostream>
#include <string>

#include "DuelingGenerators.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day15;
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " [Generator A start] [Generator B start]\n";
		return 1;
	}

	DuelingGenerators dg(std::stoi(argv[1]), std::stoi(argv[2]));

	std::cout << dg.FinalCount() << "\n";

	return 0;
}