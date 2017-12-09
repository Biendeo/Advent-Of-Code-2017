// Day 9: StreamProcessing.cpp
// Definitions for the class that handles the stream.

#include "StreamProcessing.h"

#include <fstream>

Biendeo::AdventOfCode2017::Day9::StreamProcessing::StreamProcessing(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::getline(f, stream);
	f.close();
}

int Biendeo::AdventOfCode2017::Day9::StreamProcessing::Score() {
	return cache.Get([&] {
		return CalculateScoreAndGarbage();
	}).first;
}

int Biendeo::AdventOfCode2017::Day9::StreamProcessing::Garbage() {
	return cache.Get([&] {
		return CalculateScoreAndGarbage();
	}).second;
}

std::pair<int, int> Biendeo::AdventOfCode2017::Day9::StreamProcessing::CalculateScoreAndGarbage() {
	bool inGarbage = false;
	bool inSkip = false;
	int depth = 0;
	int score = 0;
	int garbageCharacters = 0;
	for (auto c : stream) {
		if (inSkip) {
			inSkip = false;
		} else if (c == '!') {
			inSkip = true;
		} else if (inGarbage && c == '>') {
			inGarbage = false;
		} else if (inGarbage) {
			++garbageCharacters;
		} else if (c == '<') {
			inGarbage = true;
		} else if (c == '{') {
			++depth;
		} else if (c == '}') {
			score += depth;
			--depth;
		}
	}
	return std::make_pair(score, garbageCharacters);
}
