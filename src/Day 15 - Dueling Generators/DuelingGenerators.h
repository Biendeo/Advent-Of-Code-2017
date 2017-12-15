// Day 15: DuelingGenerators.h
// Declarations for the class that finds matching values between generators.

#include <string>
#include <utility>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day15 {
	class DuelingGenerators {
		public:
		/// Constructs a DuelingGenerators object with the two generator start points.	
		DuelingGenerators(uint32_t aStart, uint32_t bStart);

		/// Returns the judge's final count. This result is cached.
		int FinalCount();

		private:
		CachedValue<int> cache;

		/// Calculates the judge's final count. This result is not cached.
		int CalculateFinalCount();

		uint32_t aStart;
		uint32_t bStart;

		struct Generator {
			Generator(int startingValue, int factor);
			uint32_t NextValue();

			uint32_t previousValue;
			uint32_t currentValue;
			uint32_t factor;
		};
	};
}