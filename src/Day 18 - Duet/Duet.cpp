// Day 18: Duet.cpp
// Definitions for the class that computes end states for a set of instructions.

#include "Duet.h"

#include <fstream>
#include <iostream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day18::Duet::Duet(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	while (std::getline(f, str)) {
		std::vector<std::string> splitString = Split(str, ' ');
		if (splitString[0] == "snd") {
#ifndef AOC_PART2
			instructions.emplace_back(InstructionType::Sound, splitString[1], "?");
#else
			instructions.emplace_back(InstructionType::Send, splitString[1], "?");
#endif
		} else if (splitString[0] == "rcv") {
#ifndef AOC_PART2
			instructions.emplace_back(InstructionType::Recover, splitString[1], "?");
#else
			instructions.emplace_back(InstructionType::Receive, splitString[1], "?");
#endif
		} else {
			InstructionType it;
			if (splitString[0] == "set") {
				it = InstructionType::Set;
			} else if (splitString[0] == "add") {
				it = InstructionType::Add;
			} else if (splitString[0] == "mul") {
				it = InstructionType::Multiply;
			} else if (splitString[0] == "mod") {
				it = InstructionType::Modulo;
			} else if (splitString[0] == "jgz") {
				it = InstructionType::Jump;
			}
			instructions.emplace_back(it, splitString[1], splitString[2]);
		}
	}
	f.close();
}

#ifndef AOC_PART2
int64_t Biendeo::AdventOfCode2017::Day18::Duet::FirstRecover() {
	return firstRecoverCache.Get([&] {
		return CalculateFirstRecover();
	});
}
#else
int64_t Biendeo::AdventOfCode2017::Day18::Duet::ProgramOneSends() {
	return programOneSendCache.Get([&] {
		return CalculateProgramOneSends();
	});
}
#endif

int64_t Biendeo::AdventOfCode2017::Day18::Duet::CalculateFirstRecover() {
	Program p(instructions, 0);
	while (!p.WasLastStepSuccessfulRecover() && !p.Terminated()) {
		p.Next();
	}
	return p.LastRecover();
}

int64_t Biendeo::AdventOfCode2017::Day18::Duet::CalculateProgramOneSends() {
	Program one(instructions, 0);
	Program two(instructions, 1);
	one.SynchroniseQueues(two);

	while ((!one.Terminated() && !one.IsWaiting()) || (!two.Terminated() && !two.IsWaiting())) {
		one.Next();
		two.Next();
	}
	return two.Sends();
}


Biendeo::AdventOfCode2017::Day18::Duet::Instruction::Instruction(InstructionType type, const std::string& parameter1, const std::string& parameter2) {
	this->type = type;
	try {
		this->parameter1 = InstructionParameter(static_cast<int64_t>(std::stol(parameter1)));
	} catch (const std::exception& e) {
		static_cast<void>(e);
		this->parameter1 = InstructionParameter(parameter1[0]);
	}
	try {
		this->parameter2 = InstructionParameter(static_cast<int64_t>(std::stol(parameter2)));
	} catch (const std::exception& e) {
		static_cast<void>(e);
		this->parameter2 = InstructionParameter(parameter2[0]);
	}
}

Biendeo::AdventOfCode2017::Day18::Duet::Program::Program(const std::vector<Instruction>& instructions, int64_t programId) : instructions(instructions) {
	for (char c = 'a'; c <= 'z'; ++c) {
		registers.insert(std::make_pair(c, 0));
	}
	registers['p'] = programId;
	programCounter = 0;
	sendQueue = &receiveQueue;
	successfulRecover = false;
	lastRecover = 0;
	waiting = false;
	sends = 0;
	programNumber = programId;
}

void Biendeo::AdventOfCode2017::Day18::Duet::Program::SynchroniseQueues(Program& p) {
	sendQueue = &p.receiveQueue;
	p.sendQueue = &receiveQueue;
}

void Biendeo::AdventOfCode2017::Day18::Duet::Program::Next() {
	if (Terminated()) {
		return;
	}
	successfulRecover = false;
	waiting = false;
	Instruction inst = instructions[programCounter];
	// std::cout << programNumber << " - " << static_cast<int>(inst.type) << ", " << inst.parameter1.Value(registers) << ", " << inst.parameter2.Value(registers) << "\n";
	switch (inst.type) {
#ifndef AOC_PART2
		case InstructionType::Sound:
			lastRecover = inst.parameter1.Value(registers);
			break;
		case InstructionType::Recover:
			if (lastRecover != 0 && inst.parameter1.Value(registers) != 0) {
				inst.parameter1.Value(registers) = lastRecover;
				if (lastRecover != 0) {
					successfulRecover = true;
				}
			}
			break;
#else
		case InstructionType::Send:
			sendQueue->push(inst.parameter1.Value(registers));
			++sends;
			break;
		case InstructionType::Receive:
			if (receiveQueue.empty()) {
				waiting = true;
				--programCounter;
			} else {
				inst.parameter1.Value(registers) = receiveQueue.front();
				successfulRecover = true;
				lastRecover = receiveQueue.front();
				receiveQueue.pop();
			}
			break;
#endif
		case InstructionType::Set:
			inst.parameter1.Value(registers) = inst.parameter2.Value(registers);
			break;
		case InstructionType::Add:
			inst.parameter1.Value(registers) += inst.parameter2.Value(registers);
			break;
		case InstructionType::Multiply:
			inst.parameter1.Value(registers) *= inst.parameter2.Value(registers);
			break;
		case InstructionType::Modulo:
			if (inst.parameter2.Value(registers) != 0) {
				inst.parameter1.Value(registers) %= inst.parameter2.Value(registers);
			}
			break;
		case InstructionType::Jump:
			if (inst.parameter1.Value(registers) > 0) {
				programCounter += (inst.parameter2.Value(registers) - 1);
			}
			break;
	}
	++programCounter;
}

bool Biendeo::AdventOfCode2017::Day18::Duet::Program::Terminated() {
	return programCounter < 0 || static_cast<size_t>(programCounter) >= instructions.size();
}

bool Biendeo::AdventOfCode2017::Day18::Duet::Program::WasLastStepSuccessfulRecover() {
	return successfulRecover;
}

int64_t Biendeo::AdventOfCode2017::Day18::Duet::Program::LastRecover() {
	return lastRecover;
}

bool Biendeo::AdventOfCode2017::Day18::Duet::Program::IsWaiting() {
	return waiting;
}

int64_t Biendeo::AdventOfCode2017::Day18::Duet::Program::Sends() {
	return sends;
}

Biendeo::AdventOfCode2017::Day18::Duet::Instruction::InstructionParameter::InstructionParameter(char c) {
	isRegister = true;
	reg = c;
	value = -1;
}

Biendeo::AdventOfCode2017::Day18::Duet::Instruction::InstructionParameter::InstructionParameter(int64_t i) {
	isRegister = false;
	reg = '?';
	value = i;
}

int64_t& Biendeo::AdventOfCode2017::Day18::Duet::Instruction::InstructionParameter::Value(std::map<char, int64_t>& registers) {
	if (!isRegister) {
		return value;
	} else {
		return registers[reg];
	}
}
