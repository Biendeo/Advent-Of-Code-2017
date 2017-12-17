// Day 17: Spinlock.cpp
// Definitions for the class that cycles through elements.

#include "Spinlock.h"

#include <fstream>
#include <iostream>
#include <list>

Biendeo::AdventOfCode2017::Day17::Spinlock::Spinlock(int input) {
	numSteps = input;
}

int Biendeo::AdventOfCode2017::Day17::Spinlock::ValueAfter2017() {
	return cache.Get([&] {
		return CalculateValueAfter2017();
	});
}

int Biendeo::AdventOfCode2017::Day17::Spinlock::CalculateValueAfter2017() {
	std::list<int> buffer{0};
	auto it = buffer.begin();
#ifndef AOC_PART2
	static const int LIMIT = 2017;
#else
	// Part 2 takes way too long. Can it be faster?
	static const int LIMIT = 50000000;
#endif
	for (int i = 1; i <= LIMIT; ++i) {
		for (int j = 0; j < numSteps; ++j) {
			++it;
			if (it == buffer.end()) {
				it = buffer.begin();
			}
		}
		++it;
		buffer.insert(it, i);
		--it;

		if (i % 500000 == 0) {
			std::cout << i / 500000 << "%\n";
		}
	}
	++it;
#ifndef AOC_PART2
	if (it == buffer.end()) {
		it = buffer.begin();
	}
#else
	// For the second part, you need the value after 0. This will ALWAYS be the second element in
	// buffer.
	it = buffer.begin();
	++it;
#endif
	return *it;
}