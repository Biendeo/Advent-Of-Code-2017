// Day 18: Duet.h
// Declarations for the class that computes end states for a set of instructions.

#include <map>
#include <queue>
#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day18 {
	class Duet {
		public:
		/// Constructs a Duet object with a file inputting instructions.
		Duet(const std::string& inputFile);

		/// Returns the first non-zero value that is recovered. This result is cached.
		int64_t FirstRecover();

		/// Returns the number of times program one sends. This result is cached.
		int64_t ProgramOneSends();

		private:
		CachedValue<int64_t> firstRecoverCache;

		/// Calculates the first non-zero value that is recovered. This result is not cached.
		int64_t CalculateFirstRecover();

		CachedValue<int64_t> programOneSendCache;

		/// Calculates the first non-zero value that is recovered. This result is not cached.
		int64_t CalculateProgramOneSends();

		enum class InstructionType {
#ifndef AOC_PART2
			Sound,
			Recover,
#else
			Send,
			Receive,
#endif
			Set,
			Add,
			Multiply,
			Modulo,
			Jump
		};

		struct Instruction {
			Instruction(InstructionType type, bool twoRegisters, char reg1, char reg2, int value);

			InstructionType type;
			bool twoRegisters;
			char reg1;
			char reg2;
			int value;
		};

		class Program {
			public:
			Program(const std::vector<Instruction>& instructions, int64_t programId);

			void SynchroniseQueues(Program& p);

			void Next();

			bool Terminated();

			bool WasLastStepSuccessfulRecover();
			int64_t LastRecover();

			bool IsWaiting();
			int64_t Sends();

			private:
			const std::vector<Instruction>& instructions;
			std::map<char, int64_t> registers;
			int64_t programCounter;
			std::queue<int64_t>* sendQueue;
			std::queue<int64_t> receiveQueue;
			// For part 1.
			bool successfulRecover;
			int64_t lastRecover;
			// For part 2.
			bool waiting;
			int64_t sends;
		};

		std::vector<Instruction> instructions;
	};
}