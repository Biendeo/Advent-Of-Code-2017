// Day 11: HexEd.h
// Declarations for the class that hashes the values.

#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day11 {
	class HexEd {
		public:
		/// Constructs a HexEd object with the given input file.
		HexEd(const std::string& inputFile);

		/// Returns how many steps the child is away. This result is cached.
		int StepsAway();

		/// Returns the furthest the child ever gets. This result is cached.
		int MostStepsAway();

		private:
		enum class Direction {
			North,
			NorthWest,
			NorthEast,
			South,
			SouthWest,
			SouthEast
		};

		CachedValue<std::pair<int, int>> cache;

		/// Calculates how many steps the child is away. This result is not cached.
		std::pair<int, int> CalculateStepsAway();

		/// Stores the directions.
		std::vector<Direction> directions;
	};
}