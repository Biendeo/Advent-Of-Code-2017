// Day 19: SeriesOfTubes.h
// Declarations for the class that computes end states for a set of instructions.

#include <string>
#include <utility>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day19 {
	class SeriesOfTubes {
		public:
		/// Constructs a SeriesOfTubes object with a file inputting the diagram.
		SeriesOfTubes(const std::string& inputFile);

		/// Returns the letters that will be seen. This result is cached.
		std::string Letters();

		/// Returns the number of steps it takes. This result is cached.
		int Steps();

		private:
		CachedValue<std::pair<std::string, int>> cache;

		/// Calculates the letters that will be seen and the number of steps it takes. This result
		/// is not cached.
		std::pair<std::string, int> CalculateLettersAndSteps();

		std::vector<std::vector<char>> diagram;
	};
}