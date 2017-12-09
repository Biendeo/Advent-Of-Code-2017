// Day 9: StreamProcessing.h
// Declarations for the class that handles the stream.

#include <string>
#include <utility>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day9 {
	class StreamProcessing {
		public:
		/// Constructs an StreamProcessing object with the given input file.
		StreamProcessing(const std::string& inputFile);

		/// Returns the score of the stream. This value is cached.
		int Score();

		/// Returns the number of garbage characters in the stream. This value is cached.
		int Garbage();

		private:

		CachedValue<std::pair<int, int>> cache;

		/// Calculates the score and number of garbage characters in the stream. This value is not
		/// cached.
		std::pair<int, int> CalculateScoreAndGarbage();

		/// Stores the stream.
		std::string stream;
	};
}