// Day 16: PermutationPromenade.cpp
// Definitions for the class that computes end states for a set of instructions.

#include "PermutationPromenade.h"

#include <array>
#include <fstream>
#include <iostream>
#include <map>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day16::PermutationPromenade::PermutationPromenade(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	std::getline(f, str);
	std::vector<std::string> splitString = Split(str, ',');
	for (const std::string& term : splitString) {
		if (term[0] == 's') {
			instructions.emplace_back(InstructionType::Spin, std::stoi(term.substr(1)), -1);
		} else if (term[0] == 'x') {
			std::vector<std::string> subSplit = Split(term.substr(1), '/');
			instructions.emplace_back(InstructionType::Exchange, std::stoi(subSplit[0]), std::stoi(subSplit[1]));
		} else if (term[0] == 'p') {
			std::vector<std::string> subSplit = Split(term.substr(1), '/');
			instructions.emplace_back(InstructionType::Partner, subSplit[0][0], subSplit[1][0]);
		}
	}
	f.close();
}

std::string Biendeo::AdventOfCode2017::Day16::PermutationPromenade::FinalPositions() {
	return cache.Get([&] {
		return CalculateFinalPositions();
	});
}

std::string Biendeo::AdventOfCode2017::Day16::PermutationPromenade::CalculateFinalPositions() {
	std::array<char, NUM_PROGRAMS> positions;
	for (int i = 0; i < NUM_PROGRAMS; ++i) {
		positions[i] = i + 'a';
	}
#ifdef AOC_PART2
	// If we've seen any state before, then we can store those states and skip having to run the
	// sequence on them. On top of that, that means that there's a loop somewhere, so we can detect
	// that and skip all the loop cycles.
	std::map<std::array<char, NUM_PROGRAMS>, std::array<char, NUM_PROGRAMS>> seenStates;
	int cycleDetection = -1;
	bool skippedCycles = false;
	std::array<char, NUM_PROGRAMS> cycleStart;
	for (int loop = 0; loop < 1000000000; ++loop) {
		if (loop % 1000000 == 0) {
			std::cout << loop << "\n";
		}
		if (seenStates.find(positions) != seenStates.end()) {
			if (!skippedCycles) {
				if (cycleDetection == -1) {
					cycleDetection = 0;
					cycleStart = positions;
				} else {
					++cycleDetection;
					if (cycleStart == positions) {
						// We've detected the cycle and can skip so many spaces ahead.
						while (loop < 1000000000 - cycleDetection) {
							loop += cycleDetection;
						}
					}
				}
			}
			positions = seenStates[positions];
			continue;
		}
		std::array<char, NUM_PROGRAMS> originalPositions = positions;
#endif
		for (const Instruction& instruction : instructions) {
			char temp;
			switch (instruction.type) {
				case InstructionType::Spin:
					std::array<char, NUM_PROGRAMS> oldPositions = positions;
					for (int i = 0; i < NUM_PROGRAMS; ++i) {
						positions[i] = oldPositions[(i + NUM_PROGRAMS - instruction.positionA) % NUM_PROGRAMS];
					}
					break;
				case InstructionType::Exchange:
					temp = positions[instruction.positionA];
					positions[instruction.positionA] = positions[instruction.positionB];
					positions[instruction.positionB] = temp;
					break;
				case InstructionType::Partner:
					int posA, posB;
					for (int i = 0; i < NUM_PROGRAMS; ++i) {
						if (positions[i] == instruction.positionA) {
							posA = i;
						} else if (positions[i] == instruction.positionB) {
							posB = i;
						}
					}
					temp = positions[posA];
					positions[posA] = positions[posB];
					positions[posB] = temp;
					break;
			}
		}
#ifdef AOC_PART2
		seenStates.insert(std::make_pair(originalPositions, positions));
	}
#endif
	std::string finalString = "";
	for (char c : positions) {
		finalString += c;
	}
	return finalString;
}

Biendeo::AdventOfCode2017::Day16::PermutationPromenade::Instruction::Instruction(InstructionType type, int positionA, int positionB) {
	this->type = type;
	this->positionA = positionA;
	this->positionB = positionB;
}
