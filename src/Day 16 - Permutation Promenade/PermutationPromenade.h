// Day 16: PermutationPromenade.h
// Declarations for the class that computes end states for a set of instructions.

#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day16 {
	class PermutationPromenade {
		public:
		/// Constructs a PermutationPromenade object with the two generator start points.	
		PermutationPromenade(const std::string& inputFile);

		/// Returns the judge's final count. This result is cached.
		std::string FinalPositions();

		private:
		CachedValue<std::string> cache;

		/// Calculates the judge's final count. This result is not cached.
		std::string CalculateFinalPositions();

		enum class InstructionType {
			Spin,
			Exchange,
			Partner
		};

		struct Instruction {
			Instruction(InstructionType type, int positionA, int positionB);

			InstructionType type;
			int positionA;
			int positionB;
		};

		std::vector<Instruction> instructions;

		static const int NUM_PROGRAMS = 16;
	};
}