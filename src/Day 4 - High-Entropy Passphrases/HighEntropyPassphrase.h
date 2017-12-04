// Day 4: HighEntropyPassphrase.h
// Declarations for the class that determines the validity of passphrases.

#include <string>
#include <vector>

// I've noticed all three days so far have very similar setups. Perhaps I should generalise it.

namespace Biendeo::AdventOfCode2017::Day4 {
	class HighEntropyPassphrase {
		public:
		/// Constructs a SpiralMemory with the given target square.
		HighEntropyPassphrase(const std::string& inputFile);

		/// Returns the number of valid words found.
		int NumValid();

		private:
		struct CachedValue {
			CachedValue() {
				this->calculated = false;
			}

			bool calculated;
			int value;
		};

		struct CachedValue part1Cache;

		std::vector<std::vector<std::string>> passphrases;

		/// Calculates the number of steps. This doesn't cache it.
		int CalculateNumValid();

		/// Returns whether two strings are anagrams of each other.
		bool IsAnagram(const std::string& a, const std::string& b);
	};
}