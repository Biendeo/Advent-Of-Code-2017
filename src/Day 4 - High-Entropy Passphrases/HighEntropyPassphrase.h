// Day 4: HighEntropyPassphrase.h
// Declarations for the class that determines the validity of passphrases.

#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day4 {
	class HighEntropyPassphrase {
		public:
		/// Constructs a HighEntropyPassphrase with the 
		HighEntropyPassphrase(const std::string& inputFile);

		/// Returns the number of valid words found. The answer is cached.
		int NumValid();

		private:
		CachedValue<int> cache;

		std::vector<std::vector<std::string>> passphrases;

		/// Calculates the number of passphrases that are valid.
		int CalculateNumValid();
	};
}