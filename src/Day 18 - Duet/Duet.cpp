// Day 18: Duet.cpp
// Definitions for the class that computes end states for a set of instructions.

#include "Duet.h"

#include <fstream>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day18::Duet::Duet(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	while (std::getline(f, str)) {
		std::vector<std::string> splitString = Split(str, ' ');
		if (splitString[0] == "snd") {
#ifndef AOC_PART2
			instructions.emplace_back(InstructionType::Sound, false, splitString[1][0], '?', -1);
#else
			// The send instruction can either be a register or an integer, and has to be handled
			// separately here.
			bool twoRegisters = true;
			try {
				std::stoi(splitString[1]);
				twoRegisters = false;
			} catch (const std::exception& e) {
				// Nothing.
				static_cast<void>(e);
			}
			if (twoRegisters) {
				instructions.emplace_back(InstructionType::Send, twoRegisters, '?', splitString[1][0], -1);
			} else {
				instructions.emplace_back(InstructionType::Send, twoRegisters, '?', '?', std::stoi(splitString[1]));
			}
#endif
		} else if (splitString[0] == "rcv") {
#ifndef AOC_PART2
			instructions.emplace_back(InstructionType::Recover, false, splitString[1][0], '?', -1);
#else
			instructions.emplace_back(InstructionType::Receive, false, splitString[1][0], '?', -1);
#endif
		} else {
			bool twoRegisters = true;
			try {
				std::stoi(splitString[2]);
				twoRegisters = false;
			} catch (const std::exception& e) {
				// Nothing.
				static_cast<void>(e);
			}
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
			if (twoRegisters) {
				instructions.emplace_back(it, twoRegisters, splitString[1][0], splitString[2][0], -1);
			} else {
				instructions.emplace_back(it, twoRegisters, splitString[1][0], '?', std::stoi(splitString[2]));
			}
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
	return one.Sends();
}


Biendeo::AdventOfCode2017::Day18::Duet::Instruction::Instruction(InstructionType type, bool twoRegisters, char reg1, char reg2, int value) {
	this->twoRegisters = twoRegisters;
	this->type = type;
	this->reg1 = reg1;
	this->reg2 = reg2;
	this->value = value;
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
	int value = inst.value;
	if (inst.twoRegisters) {
		value = registers[inst.reg2];
	}
	switch (inst.type) {
#ifndef AOC_PART2
		case InstructionType::Sound:
			lastRecover = registers[inst.reg1];
			break;
		case InstructionType::Recover:
			if (lastRecover != 0 && registers[inst.reg1] != 0) {
				registers[inst.reg1] = lastRecover;
				if (lastRecover != 0) {
					successfulRecover = true;
				}
			}
			break;
#else
		case InstructionType::Send:
			sendQueue->push(value);
			++sends;
			// My answer is less than 10000, so this is a quick heads up that it's not working.
			if (sends >= 10000) {
				abort();
			}
			break;
		case InstructionType::Receive:
			if (receiveQueue.empty()) {
				waiting = true;
				--programCounter;
			} else if (registers[inst.reg1] != 0) {
				registers[inst.reg1] = receiveQueue.front();
				if (receiveQueue.front() != 0) {
					successfulRecover = true;
					lastRecover = receiveQueue.front();
				}
				receiveQueue.pop();
			}
			break;
#endif
		case InstructionType::Set:
			registers[inst.reg1] = value;
			break;
		case InstructionType::Add:
			registers[inst.reg1] += value;
			break;
		case InstructionType::Multiply:
			registers[inst.reg1] *= value;
			break;
		case InstructionType::Modulo:
			if (value != 0) {
				registers[inst.reg1] %= value;
			}
			break;
		case InstructionType::Jump:
			if (registers[inst.reg1] > 0) {
				programCounter += (value - 1);
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
