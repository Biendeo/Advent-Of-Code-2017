// Day 15: DuelingGenerators.cpp
// Definitions for the class that finds matching values between generators.

#include "DuelingGenerators.h"

#include <array>
#include <iomanip>
#include <queue>
#include <set>
#include <sstream>

Biendeo::AdventOfCode2017::Day15::DuelingGenerators::DuelingGenerators(uint32_t aStart, uint32_t bStart) {
	this->aStart = aStart;
	this->bStart = bStart;
}

int Biendeo::AdventOfCode2017::Day15::DuelingGenerators::FinalCount() {
	return cache.Get([&] {
		return CalculateFinalCount();
	});
}

int Biendeo::AdventOfCode2017::Day15::DuelingGenerators::CalculateFinalCount() {
	int matchingPairs = 0;
	Generator a(aStart, 16807);
	Generator b(bStart, 48271);
#ifndef AOC_PART2
	for (int i = 0; i < 40000000; ++i) {
		if ((a.NextValue() & 0xFFFF) == (b.NextValue() & 0xFFFF)) ++matchingPairs;
	}
#else
	for (int i = 0; i < 5000000; ++i) {
		uint32_t aValue = 1, bValue = 1;
		while (aValue % 4 != 0) {
			aValue = a.NextValue();
		}
		while (bValue % 8 != 0) {
			bValue = b.NextValue();
		}
		if ((aValue & 0xFFFF) == (bValue & 0xFFFF)) ++matchingPairs;
	}
#endif
	return matchingPairs;
}

Biendeo::AdventOfCode2017::Day15::DuelingGenerators::Generator::Generator(int startingValue, int factor) {
	this->currentValue = startingValue;
	this->factor = factor;
}

uint32_t Biendeo::AdventOfCode2017::Day15::DuelingGenerators::Generator::NextValue() {
	previousValue = currentValue;
	uint64_t bigValue = static_cast<uint64_t>(previousValue) * factor;
	currentValue = static_cast<uint32_t>(bigValue % 2147483647);
	return currentValue;
}
