// Day 12: DigitalPlumber.h
// Declarations for the class that hashes the values.

#include <set>
#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day12 {
	class DigitalPlumber {
		public:
		/// Constructs a DigitalPlumber object with the given input file.
		DigitalPlumber(const std::string& inputFile);

		/// Returns how many nodes are connected indirectly to 0. This result is cached.
		int ConnectionsToZero();

		/// Returns how many groups are in the system. This result is cached.
		int HowManyGroups();

		private:
		struct Connection {
			int source;
			std::vector<int> connections;
		};

		CachedValue<int> connectionsToZeroCache;
		CachedValue<int> groupsCache;

		/// Calculates how many groups there are in the system. This result is not cached.
		int CalculateHowManyGroups();

		/// Returns the set of people who are connected to the given person.
		std::set<int> ConnectedTo(int source);

		/// Stores the connections.
		std::vector<Connection> connections;
	};
}