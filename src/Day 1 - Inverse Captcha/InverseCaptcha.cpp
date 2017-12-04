// Day 1: InverseCaptcha.cpp
// Definitions for the class that determines the inverse captcha.

#include "InverseCaptcha.h"

Biendeo::AdventOfCode2017::Day1::InverseCaptcha::InverseCaptcha(const std::string& inputString) {
	this->inputString = inputString;
	this->length = inputString.size();
}

int Biendeo::AdventOfCode2017::Day1::InverseCaptcha::Sum() {
	return cache.Get([&] {
		return CalculateSum();
	});
}

int Biendeo::AdventOfCode2017::Day1::InverseCaptcha::CalculateSum() {
	int currentSum = 0;
#ifndef AOC_PART2
	// For part 1, just detect if the next number is the same and add it. This cycles around at the
	// end.
	for (size_t i = 0; i < length; ++i) {
		if (i < length - 1 && inputString[i] == inputString[i + 1] || i == length - 1 && inputString[i] == inputString[0]) {
			currentSum += inputString[i] - '0';
		}
	}
#else
	// For part 2, detect if the number half way across is the same and add it. For the first half,
	// you can add the half length to get the value. Once you're past half-way, you subtract it.
	const size_t halfLength = length / 2;
	for (size_t i = 0; i < halfLength; ++i) {
		if (inputString[i] == inputString[i + halfLength]) {
			currentSum += inputString[i] - '0';
		}
	}
	for (size_t i = halfLength; i < length; ++i) {
		if (inputString[i] == inputString[i - halfLength]) {
			currentSum += inputString[i] - '0';
		}
	}
#endif
	return currentSum;
}
