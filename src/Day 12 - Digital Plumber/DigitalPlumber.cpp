// Day 12: DigitalPlumber.cpp
// Definitions for the class that hashes the values.

#include "DigitalPlumber.h"

#include <fstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day12::DigitalPlumber::DigitalPlumber(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	while (std::getline(f, str)) {
		std::vector<std::string> splitString = Split(str, ' ');
		Connection connection;
		connection.source = std::stoi(splitString[0]);
		for (size_t pos = 2; pos < splitString.size() - 1; ++pos) {
			connection.connections.push_back(std::stoi(splitString[pos].substr(0, splitString[pos].size() - 1)));
		}
		connection.connections.push_back(std::stoi(splitString[splitString.size() - 1]));
		connections.push_back(connection);
	}
	f.close();
}

int Biendeo::AdventOfCode2017::Day12::DigitalPlumber::ConnectionsToZero() {
	return connectionsToZeroCache.Get([&] {
		return static_cast<int>(ConnectedTo(0).size());
	});
}

int Biendeo::AdventOfCode2017::Day12::DigitalPlumber::HowManyGroups() {
	return groupsCache.Get([&] {
		return CalculateHowManyGroups();
	});
}

int Biendeo::AdventOfCode2017::Day12::DigitalPlumber::CalculateHowManyGroups() {
	// This could probably just be a counter rather than needing to store whole sets. This is just
	// a remnant of a previous implementation that relied on this set.
	std::set<std::set<int>> groups;
	std::set<int> seenPeople;
	for (int startingElement = 0; startingElement < connections.size(); ++startingElement) {
		// This is an optimisation to ignore any element who has been seen already. This saves a lot
		// of time.
		if (seenPeople.find(startingElement) == seenPeople.end()) {
			std::set<int> connectedToStart = ConnectedTo(startingElement);
			groups.insert(connectedToStart);
			seenPeople.insert(connectedToStart.begin(), connectedToStart.end());
		}
	}

	return static_cast<int>(groups.size());
}

std::set<int> Biendeo::AdventOfCode2017::Day12::DigitalPlumber::ConnectedTo(int source) {
	std::set<int> oldSet;
	std::set<int> newSet;
	newSet.insert(source);

	while (oldSet.size() != newSet.size()) {
		oldSet = newSet;
		for (const int source : oldSet) {
			for (const int destination : connections[source].connections) {
				newSet.insert(destination);
			}
		}
	}

	return newSet;
}
