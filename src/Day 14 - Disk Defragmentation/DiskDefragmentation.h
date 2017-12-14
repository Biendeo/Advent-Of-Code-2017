// Day 14: DiskDefragmentation.h
// Declarations for the class that counts squares and regions.

#include <string>
#include <utility>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day14 {
	class DiskDefragmentation {
		public:
		/// Constructs a DiskDefragmentation object with the given input string.
		DiskDefragmentation(const std::string& input);

		/// Returns the number of squares used by the system. This result is cached.
		int Squares();

		/// Returns the number of regions used by the system. This result is cached.
		int Regions();

		private:
		CachedValue<std::pair<int, int>> cache;

		/// Calculates the number of squares and regions used by the input. This result is not
		/// cached.
		std::pair<int, int> CalculateSquaresAndRegions();

		/// Stores the directions.
		std::string input;

		/// Returns the KnotHash of the input string
		std::string KnotHash(const std::string& input);

		static const size_t SIZE = 128;

		struct Pos2 {
			Pos2(int x, int y) {
				this->x = x;
				this->y = y;
			}

			friend bool operator<(const Pos2& a, const Pos2& b) {
				return a.y == b.y ? a.x < b.x : a.y < b.y;
			}

			friend bool operator<=(const Pos2& a, const Pos2& b) {
				return !(b < a);
			}

			friend bool operator>(const Pos2& a, const Pos2& b) {
				return  b < a;
			}

			friend bool operator>=(const Pos2& a, const Pos2& b) {
				return !(a < b);
			}

			friend bool operator==(const Pos2& a, const Pos2& b) {
				return !(a < b || b < a);
			}

			friend bool operator!=(const Pos2& a, const Pos2& b) {
				return !(a == b);
			}

			Pos2& operator++() {
				if (x == SIZE - 1) {
					x = 0;
					++y;
				} else {
					++x;
				}
				return (*this);
			}

			int x;
			int y;
		};
	};
}