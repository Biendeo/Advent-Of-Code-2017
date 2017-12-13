// Day 13: PacketScanner.h
// Declarations for the class that times through moving windows.

#include <set>
#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day13 {
	class PacketScanner {
		public:
		/// Constructs a PacketScanner object with the given input file.
		PacketScanner(const std::string& inputFile);

		/// Returns the severity of the trip. This result is cached.
		int Severity();

		/// Returns the minimum delay to get through the system. This result is cached.
		int Delay();

		private:
		CachedValue<int> severityCache;
		CachedValue<int> delayCache;

		/// Calculates the severity of the trip. This result is not cached.
		int CalculateSeverity();

		/// Calculates the minimum delay to get through the system. This result is not cached.
		int CalculateDelay();

		/// Calculates the position after zigzagging.
		int Zigzag(int range, int position);

		/// Stores the directions.
		std::vector<int> ranges;
	};
}