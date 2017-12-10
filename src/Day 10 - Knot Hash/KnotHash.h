// Day 10: KnotHash.h
// Declarations for the class that hashes the values.

#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day10 {
	class KnotHash {
		public:
		/// Constructs a KnotHash object with the given input file.
		KnotHash(const std::string& inputFile);

		/// Returns the product of the first two elements after applying the operations. This result
		/// is cached.
		int FirstTwoProducts();

		/// Returns the knot hash. This value is cached.
		std::string Hash();

		private:
		CachedValue<int> firstTwoProductsCache;
		CachedValue<std::string> hashCache;

		/// Calculates the product of the first two elements. This result is not cached.
		int CalculateFirstTwoProducts();

		/// Calculates the knot hash. This result is not cached.
		std::string CalculateHash();

		/// Stores the lengths.
		std::vector<int> lengths;

		/// Stores the lengths as ASCII characters.
		std::vector<int> lengthsASCII;

		static const int NUM_ELEMENTS = 256;
		static const int NUM_LOOPS = 64;
	};
}