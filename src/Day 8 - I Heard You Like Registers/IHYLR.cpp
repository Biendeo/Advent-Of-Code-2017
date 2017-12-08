// Day 8: IHYLR.cpp
// Definitions for the class that simulates instructions.

#include "IHYLR.h"

#include <fstream>
#include <limits>
#include <map>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day8::IHYLR::IHYLR(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string line;

	while (std::getline(f, line)) {
		std::vector<std::string> lineSplit = Split(line);
		Instruction currentInstruction;
		currentInstruction.registerName = lineSplit[0];
		currentInstruction.isIncrement = lineSplit[1] == "inc";
		currentInstruction.incrementAmount = std::stoi(lineSplit[2]);
		currentInstruction.conditionalRegisterName = lineSplit[4];
		currentInstruction.equalityAmount = std::stoi(lineSplit[6]);
		if (lineSplit[5] == "<") {
			currentInstruction.equalityOperator = EqualityOperator::Less;
		} else if (lineSplit[5] == "<=") {
			currentInstruction.equalityOperator = EqualityOperator::LessEqual;
		} else if (lineSplit[5] == ">") {
			currentInstruction.equalityOperator = EqualityOperator::Greater;
		} else if (lineSplit[5] == ">=") {
			currentInstruction.equalityOperator = EqualityOperator::GreaterEqual;
		} else if (lineSplit[5] == "==") {
			currentInstruction.equalityOperator = EqualityOperator::Equal;
		} else if (lineSplit[5] == "!=") {
			currentInstruction.equalityOperator = EqualityOperator::NotEqual;
		}

		instructions.push_back(currentInstruction);
	}
}

int Biendeo::AdventOfCode2017::Day8::IHYLR::LargestValueAtEnd() {
	return cache.Get([&] {
		return CalculateLargestValues();
	}).first;
}

int Biendeo::AdventOfCode2017::Day8::IHYLR::LargestValueAtAnyPoint() {
	return cache.Get([&] {
		return CalculateLargestValues();
	}).second;
}

std::pair<int, int> Biendeo::AdventOfCode2017::Day8::IHYLR::CalculateLargestValues() {
	// First, we scan all the instructions so that we know what the registers are, and initialise
	// them all to zero.
	std::map<std::string, int> registers;
	for (const Instruction& instruction : instructions) {
		if (registers.find(instruction.registerName) == registers.end()) {
			registers.insert(std::make_pair(instruction.registerName, 0));
		}
		if (registers.find(instruction.conditionalRegisterName) == registers.end()) {
			registers.insert(std::make_pair(instruction.conditionalRegisterName, 0));
		}
	}

	std::string highestRegisterAtAnyPoint;
	int highestValueAtAnyPoint = std::numeric_limits<int>::lowest();

	// Now, we just run the instructions.
	for (const Instruction& instruction : instructions) {
		bool successfulComparison = false;
		int comparedValue = registers[instruction.conditionalRegisterName];

		switch (instruction.equalityOperator) {
			case EqualityOperator::Less:
				if (comparedValue < instruction.equalityAmount) successfulComparison = true;
				break;
			case EqualityOperator::LessEqual:
				if (comparedValue <= instruction.equalityAmount) successfulComparison = true;
				break;
			case EqualityOperator::Greater:
				if (comparedValue > instruction.equalityAmount) successfulComparison = true;
				break;
			case EqualityOperator::GreaterEqual:
				if (comparedValue >= instruction.equalityAmount) successfulComparison = true;
				break;
			case EqualityOperator::Equal:
				if (comparedValue == instruction.equalityAmount) successfulComparison = true;
				break;
			case EqualityOperator::NotEqual:
				if (comparedValue != instruction.equalityAmount) successfulComparison = true;
				break;
		}

		if (successfulComparison) {
			int increment = instruction.isIncrement ? instruction.incrementAmount : -instruction.incrementAmount;
			registers[instruction.registerName] += increment;
			if (registers[instruction.registerName] > highestValueAtAnyPoint) {
				highestValueAtAnyPoint = registers[instruction.registerName];
				highestRegisterAtAnyPoint = instruction.registerName;
			}
		}
	}

	// Now we just find the greatest register at the end.
	std::string highestRegisterAtEnd;
	int highestValueAtEnd = std::numeric_limits<int>::lowest();

	for (const auto& pair : registers) {
		if (highestValueAtEnd < pair.second) {
			highestValueAtEnd = pair.second;
			highestRegisterAtEnd = pair.first;
		}
	}

	return std::make_pair(highestValueAtEnd, highestValueAtAnyPoint);
}
