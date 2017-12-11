// Day 11: HexEd.cpp
// Definitions for the class that hashes the values.

#include "HexEd.h"

#include <algorithm>
#include <fstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day11::HexEd::HexEd(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	std::getline(f, str);
	std::vector<std::string> splitString = Split(str, ',');
	for (const std::string& dir : splitString) {
		if (dir == "n") {
			directions.push_back(Direction::North);
		} else if (dir == "ne") {
			directions.push_back(Direction::NorthEast);
		} else if (dir == "nw") {
			directions.push_back(Direction::NorthWest);
		} else if (dir == "s") {
			directions.push_back(Direction::South);
		} else if (dir == "se") {
			directions.push_back(Direction::SouthEast);
		} else if (dir == "sw") {
			directions.push_back(Direction::SouthWest);
		}
	}
	f.close();
}

int Biendeo::AdventOfCode2017::Day11::HexEd::StepsAway() {
	return cache.Get([&] {
		return CalculateStepsAway();
	}).first;
}

int Biendeo::AdventOfCode2017::Day11::HexEd::MostStepsAway() {
	return cache.Get([&] {
		return CalculateStepsAway();
	}).second;
}

std::pair<int, int> Biendeo::AdventOfCode2017::Day11::HexEd::CalculateStepsAway() {
	struct Pos2 {
		int x;
		int y;
	};
	Pos2 pos;
	pos.x = 0;
	pos.y = 0;
	int furthestDistance = 0;
	for (Direction d : directions) {
		switch (d) {
			case Direction::North:
				++pos.y;
				break;
			case Direction::NorthEast:
				++pos.x;
				++pos.y;
				break;
			case Direction::NorthWest:
				--pos.x;
				break;
			case Direction::South:
				--pos.y;
				break;
			case Direction::SouthEast:
				++pos.x;
				break;
			case Direction::SouthWest:
				--pos.x;
				--pos.y;
				break;
		}
		furthestDistance = std::max(std::abs(pos.x) + std::abs(pos.y), furthestDistance);
	}
	return std::make_pair(std::abs(pos.x) + std::abs(pos.y), furthestDistance);
}