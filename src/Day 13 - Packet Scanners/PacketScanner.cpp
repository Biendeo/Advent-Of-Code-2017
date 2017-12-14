// Day 13: PacketScanner.cpp
// Definitions for the class that times moving through sliding windows.

#include "PacketScanner.h"

#include <fstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day13::PacketScanner::PacketScanner(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	while (std::getline(f, str)) {
		std::vector<std::string> splitString = Split(str, ' ');
		int depth = std::stoi(splitString[0]);
		int range = std::stoi(splitString[1]);
		while (ranges.size() < depth) {
			ranges.push_back(0);
		}
		ranges.push_back(range);
	}
	f.close();
}

int Biendeo::AdventOfCode2017::Day13::PacketScanner::Severity() {
	return severityCache.Get([&] {
		return CalculateSeverity();
	});
}

int Biendeo::AdventOfCode2017::Day13::PacketScanner::Delay() {
	return delayCache.Get([&] {
		return CalculateDelay();
	});
}

int Biendeo::AdventOfCode2017::Day13::PacketScanner::Zigzag(int range, int position) {
	if (range < 2) {
		return 0;
	} else {
		position %= (2 * range - 2);
		return position >= range ? 2 * range - position : position;
	}
}

int Biendeo::AdventOfCode2017::Day13::PacketScanner::CalculateSeverity() {
	int severity = 0;
	// Position 0 will always be multiplied by 0, so there's no need to calculate that.
	for (int i = 1; i < ranges.size(); ++i) {
		if (ranges[i] != 0 && Zigzag(ranges[i], i) == 0) {
			severity += ranges[i] * i;
		}
	}
	return severity;
}

int Biendeo::AdventOfCode2017::Day13::PacketScanner::CalculateDelay() {
	int delay = -1;
	bool successfulTrip = false;
	while (!successfulTrip) {
		++delay;
		successfulTrip = true;
		for (int i = 0; i < ranges.size(); ++i) {
			if (ranges[i] != 0 && Zigzag(ranges[i], i + delay) == 0) {
				successfulTrip = false;
				break;
			}
		}
	}
	return delay;
}
