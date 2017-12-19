// Day 19: SeriesOfTubes.cpp
// Definitions for the class that computes end states for a set of instructions.

#include "SeriesOfTubes.h"

#include <fstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day19::SeriesOfTubes::SeriesOfTubes(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	int y = 0;
	while (std::getline(f, str)) {
		if (y == 0) {
			for (int x = 0; x < str.size(); ++x) {
				diagram.emplace_back();
			}
		}
		for (int x = 0; x < str.size(); ++x) {
			diagram[x].push_back(str[x]);
		}
		++y;
	}
	f.close();
}

std::string Biendeo::AdventOfCode2017::Day19::SeriesOfTubes::Letters() {
	return cache.Get([&] {
		return CalculateLettersAndSteps();
	}).first;
}

int Biendeo::AdventOfCode2017::Day19::SeriesOfTubes::Steps() {
	return cache.Get([&] {
		return CalculateLettersAndSteps();
	}).second;
}

std::pair<std::string, int> Biendeo::AdventOfCode2017::Day19::SeriesOfTubes::CalculateLettersAndSteps() {
	int x = 0;
	for (int i = 0; i < diagram.size(); ++i) {
		if (diagram[i][0] != ' ') {
			x = i;
			break;
		}
	}
	int y = 0;
	int steps = 0;
	std::string currentString = "";
	bool positiveDirection = true;
	bool verticalDirection = true;
	bool pathEnded = false;
	while (!pathEnded) {
		if (diagram[x][y] == '+') {
			bool leftExit = x > 0 && diagram[x - 1][y] != ' ' && !(positiveDirection && !verticalDirection);
			bool topExit = y > 0 && diagram[x][y - 1] != ' ' && !(positiveDirection && verticalDirection);
			bool rightExit = x + 1 < diagram.size() && diagram[x + 1][y] != ' ' && !(!positiveDirection && !verticalDirection);
			bool bottomExit = y + 1 < diagram[0].size() && diagram[x][y + 1] != ' ' && !(!positiveDirection && verticalDirection);
			if (leftExit) {
				positiveDirection = false;
				verticalDirection = false;
				--x;
			} else if (topExit) {
				positiveDirection = false;
				verticalDirection = true;
				--y;
			} else if (rightExit) {
				positiveDirection = true;
				verticalDirection = false;
				++x;
			} else {
				positiveDirection = true;
				verticalDirection = true;
				++y;
			}
		} else {
			if (diagram[x][y] >= 'A' && diagram[x][y] <= 'Z') {
				currentString += diagram[x][y];
			}
			if (positiveDirection && verticalDirection) {
				++y;
			} else if (positiveDirection && !verticalDirection) {
				++x;
			} else if (!positiveDirection && verticalDirection) {
				--y;
			} else {
				--x;
			}
		}
		if (x < 0 || y < 0 || x >= diagram.size() || y >= diagram[0].size() || diagram[x][y] == ' ') {
			pathEnded = true;
		}
		++steps;
	}
	return std::make_pair(currentString, steps);
}
