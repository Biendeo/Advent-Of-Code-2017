// Day 3: SpiralMemory.h
// Declarations for the class that determines the spiral path.

#include <string>
#include <vector>

// I've noticed all three days so far have very similar setups. Perhaps I should generalise it.

namespace Biendeo::AdventOfCode2017::Day3 {
	class SpiralMemory {
		public:
		/// Constructs a SpiralMemory with the given target square.
		SpiralMemory(int targetSquare);

		/// Returns the target number of steps, and uses a cached value if calculated before.
		int StepsToTarget();

		/// Returns the first square greater than the target using the second part's structure. This
		/// value is cached for future uses.
		int FirstGreaterSquare();

		private:
		struct CachedValue {
			CachedValue() {
				this->calculated = false;
			}

			bool calculated;
			int value;
		};

		enum class Direction {
			Up,
			Left,
			Down,
			Right
		};

		int targetSquare;

		struct CachedValue part1Cache;
		struct CachedValue part2Cache;

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateStepsToTarget();

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateFirstGreaterSquare();

		/// Finds the value of the square at the given positions.
		int GetValueAtSquare(int x, int y);
	};
}