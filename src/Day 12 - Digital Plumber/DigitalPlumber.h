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

		/// Returns how many steps the child is away. This result is cached.
		int ConnectionsToZero();

		/// Returns the furthest the child ever gets. This result is cached.
		int HowManyGroups();

		private:
		struct Connection {
			int source;
			std::vector<int> connections;
		};

		CachedValue<int> connectionsToZeroCache;
		CachedValue<int> groupsCache;

		/// Calculates how many steps the child is away. This result is not cached.
		int CalculateConnectionsToZero();

		/// Calculates how many steps the child is away. This result is not cached.
		int CalculateHowManyGroups();

		/// Returns the set of people who are connected to the given person.
		std::set<int> ConnectedTo(int source);

		/// Stores the directions.
		std::vector<Connection> connections;
	};
}