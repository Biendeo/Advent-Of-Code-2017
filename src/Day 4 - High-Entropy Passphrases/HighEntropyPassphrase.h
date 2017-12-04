// Day 4: HighEntropyPassphrase.h
// Declarations for the class that determines the validity of passphrases.

#include <functional>
#include <string>
#include <vector>

#include "CachedValue.h"

// I've noticed all three days so far have very similar setups. Perhaps I should generalise it.

namespace Biendeo::AdventOfCode2017::Day4 {

	class HighEntropyPassphrase {
		public:
		/// Constructs a SpiralMemory with the given target square.
		HighEntropyPassphrase(const std::string& inputFile);

		/// Returns the number of valid words found. The answer is cached.
		int NumValid();

		private:
		CachedValue<int> cache;

		std::vector<std::vector<std::string>> passphrases;

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateNumValid();
	};
}