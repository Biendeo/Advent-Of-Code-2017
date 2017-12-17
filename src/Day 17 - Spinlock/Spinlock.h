// Day 17: Spinlock.h
// Declarations for the class that cycles through elements.

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day17 {
	class Spinlock {
		public:
		/// Constructs a Spinlock object with the two generator start points.	
		Spinlock(int input);

		/// Returns the end value after 2017. This result is cached.
		int ValueAfter2017();

		private:
		CachedValue<int> cache;

		/// Calculates the end value after 2017. This result is not cached.
		int CalculateValueAfter2017();

		int numSteps;
	};
}