// Day 3: SpiralMemory.h
// Declarations for the class that determines the spiral path.

#include <map>
#include <string>
#include <vector>

#include "CachedValue.h"

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
		enum class Direction {
			Up,
			Left,
			Down,
			Right
		};

		struct Pos2 {
			Pos2(int x, int y) {
				this->x = x;
				this->y = y;
			}

			friend bool operator<(const Pos2& a, const Pos2& b) {
				return a.x == b.x ? a.y < b.y : a.x < b.x;
			}

			int x;
			int y;
		};

		int targetSquare;

		CachedValue<int> cacheOne;
		CachedValue<int> cacheTwo;

		std::map<Pos2, int> generatedValues;

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateStepsToTarget();

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateFirstGreaterSquare();

		/// Finds the value of the square at the given positions.
		int GetValueAtSquare(Pos2 pos);
	};
}