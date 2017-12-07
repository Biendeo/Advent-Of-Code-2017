// Day 6: Main.cpp
// Just begins the program's execution. For this program, you must pass the input file as a
// commandline argument to the program. That file will be read it. The file should be one line of
// 16 tab separated integers.

// This one was a little interesting because the second part just required a bit of extra counting
// in the course of the program. It was much more convenient to return both values at the same
// time. The CachedValue class makes this especially nice because you can call for both without
// wasting time.

#include <iostream>

#include "MemoryReallocation.h"

int main(int argc, char* argv[]) {
	using namespace Biendeo::AdventOfCode2017::Day6;
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [input file]\n";
		return 1;
	}

	MemoryReallocation mr(argv[1]);

#ifndef AOC_PART2
	std::cout << mr.Cycles().first << "\n";
#else
	std::cout << mr.Cycles().second << "\n";
#endif

	return 0;
}