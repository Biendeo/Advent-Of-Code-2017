// Day 20: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. The file should describe a diagram of paths.

// This one was much easier to implement.

#include <iostream>
#include <string>

#include "ParticleSwarm.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day20;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	ParticleSwarm ps(argv[1]);

#ifndef AOC_PART2
	std::cout << ps.Closest() << "\n";
#else
	std::cout << ps.Remaining() << "\n";
#endif

	return 0;
}