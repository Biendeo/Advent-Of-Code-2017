// Day 6: MemoryReallocation.h
// Declarations for the class that calculates the number of steps to exit the maze.

#include <array>
#include <string>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day6 {
	class MemoryReallocation {
		public:
		/// Constructs an MTTAA with the given input file.
		MemoryReallocation(const std::string& inputFile);

		/// Returns the number of cycles to get a duplicate state, and the number of cycles it took
		/// to return to that loop.
		std::pair<int, int> Cycles();

		private:
		static const int NUM_BANKS = 16;

		std::array<int, NUM_BANKS> initial;

		CachedValue<std::pair<int, int>> cache;

		/// Calculates the number of cycles. This doesn't cache it.
		std::pair<int, int> CalculateCycles();
	};
}