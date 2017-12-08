// Day 8: IHYLR.h
// Declarations for the class that simulates instructions.

#include <string>
#include <utility>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day8 {
	class IHYLR {
		public:
		/// Constructs an IHYLR with the given input file.
		IHYLR(const std::string& inputFile);

		/// Returns the largest value of a register at the end of the instructions.
		int LargestValueAtEnd();

		/// Returns the largest value of a register at any point of the instructions.
		int LargestValueAtAnyPoint();

		private:
		enum class EqualityOperator {
			Less,
			LessEqual,
			Greater,
			GreaterEqual,
			Equal,
			NotEqual
		};

		struct Instruction {
			std::string registerName;
			bool isIncrement;
			int incrementAmount;
			std::string conditionalRegisterName;
			EqualityOperator equalityOperator;
			int equalityAmount;
		};

		CachedValue<std::pair<int, int>> cache;

		/// Calculates the largest value of a register at both the end of the instructions, and at
		/// any point. This does not cache the result.
		std::pair<int, int> CalculateLargestValues();

		/// Stores all the instructions.
		std::vector<Instruction> instructions;
	};
}