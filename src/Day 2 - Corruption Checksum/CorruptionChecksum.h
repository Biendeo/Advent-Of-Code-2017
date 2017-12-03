// Day 2: CorruptionChecksum.h
// Declarations for the class that determines the corruption checksum.

#include <string>
#include <vector>

namespace Biendeo::AdventOfCode2017::Day2 {
	class CorruptionChecksum {
		public:
		/// Constructs a CorruptionChecksum with the given input file.
		CorruptionChecksum(const std::string& inputFile);

		/// Returns the first checksum calculated by the input file. If the sum has been calculated
		/// already, this value is cached.
		int ChecksumOne();

		/// Returns the second checksum calculated by the input file. If the sum has been calculated
		/// already, this value is cached.
		int ChecksumTwo();

		private:
		// This just encasulates the values here.
		struct Checksum {
			Checksum() {
				this->calculated = false;
			}

			bool calculated;
			int value;
		};

		std::vector<std::vector<int>> spreadsheet;

		struct Checksum checksumOne;
		struct Checksum checksumTwo;

		/// Calculates the first checksum and returns it as a value. This doesn't cache it.
		int CalculateChecksumOne();

		/// Calculates the second checksum and returns it as a value. This doesn't cache it.
		int CalculateChecksumTwo();
	};
}