// Day 20: ParticleSwarm.h
// Declarations for the class that computes particle movements.

#include <string>
#include <vector>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day20 {
	class ParticleSwarm {
		public:
		/// Constructs a ParticleSwarm object with a file inputting the diagram.
		ParticleSwarm(const std::string& inputFile);

		/// Returns the particle closest to the origin in the long run. This result is cached.
		int Closest();

		/// Returns the number of particles remaining after all the collisions have occurred. This
		/// result is cached.
		int Remaining();

		private:
		// This would be a great class to generalise.
		struct Int3 {
			Int3();
			Int3(int x, int y, int z);

			Int3& operator+=(const Int3& o);
			bool operator==(const Int3& o);

			int Manhatten() const;

			int x;
			int y;
			int z;
		};

		struct Particle {
			Particle(Int3 position, Int3 velocity, Int3 acceleration);

			void Next();

			Int3 position;
			Int3 velocity;
			Int3 acceleration;
			bool collided;

			bool operator<(const Particle& o);
		};

		CachedValue<int> closestCache;
		CachedValue<int> remainingCache;

		/// Calculates the particle closest to the origin in the long run. This result is not cached.
		int CalculateClosest();

		/// Calculates the number of particles remaining after all the collisions have occurred.
		/// This result is not cached.
		int CalculateRemaining();

		std::vector<Particle> initialState;
	};
}