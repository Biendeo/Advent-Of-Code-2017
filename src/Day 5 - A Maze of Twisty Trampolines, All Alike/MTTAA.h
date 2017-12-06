// Day 5: MTTAA.h
// Declarations for the class that calculates the number of steps to exit the maze.

#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day5 {
	class MTTAA {
		public:
		/// Constructs an MTTAA with the given input file.
		MTTAA(const std::string& inputFile);

		/// Returns the number of steps to exit the maze.
		int StepsToExit();

		private:
		CachedValue<int> cache;

		std::vector<int> offsets;

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateStepsToExit();
	};
}