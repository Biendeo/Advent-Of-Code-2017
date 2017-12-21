// Day 20: ParticleSwarm.cpp
// Definitions for the class that computes end states for a set of instructions.

#include "ParticleSwarm.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

#include "StringFunctions.h"

Biendeo::AdventOfCode2017::Day20::ParticleSwarm::ParticleSwarm(const std::string& inputFile) {
	std::ifstream f(inputFile);
	std::string str;
	int y = 0;
	while (std::getline(f, str)) {
		std::vector<std::string> splitString = Split(str, ' ');
		std::vector<std::string> positionSplit = Split(Split(Split(splitString[0], '<')[1], '>')[0], ',');
		std::vector<std::string> velocitySplit = Split(Split(Split(splitString[1], '<')[1], '>')[0], ',');
		std::vector<std::string> accelerationSplit = Split(Split(Split(splitString[2], '<')[1], '>')[0], ',');
		initialState.emplace_back(Int3(std::stoi(positionSplit[0]), std::stoi(positionSplit[1]), std::stoi(positionSplit[2])), Int3(std::stoi(velocitySplit[0]), std::stoi(velocitySplit[1]), std::stoi(velocitySplit[2])), Int3(std::stoi(accelerationSplit[0]), std::stoi(accelerationSplit[1]), std::stoi(accelerationSplit[2])));
	}
	f.close();
}

int Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Closest() {
	return closestCache.Get([&] {
		return CalculateClosest();
	});
}

int Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Remaining() {
	return remainingCache.Get([&] {
		return CalculateRemaining();
	});
}

int Biendeo::AdventOfCode2017::Day20::ParticleSwarm::CalculateClosest() {
	// The closest particle is the one with the least acceleration, then the least intial velocity,
	// and then the closest initial position. This'll get hitched on one particle that'd orbit back
	// but it seems to suit the problem enough.
	std::vector<Particle> particles = initialState;
	std::sort(particles.begin(), particles.end());
	for (int i = 0; i < particles.size(); ++i) {
		if (particles[0].position == initialState[i].position && particles[0].velocity == initialState[i].velocity && particles[0].acceleration == initialState[i].acceleration) {
			return i;
		}
	}
	return -1;
}

int Biendeo::AdventOfCode2017::Day20::ParticleSwarm::CalculateRemaining() {
	// The particles should collide after 1000 steps.
	static const int LONG_TERM = 1000;
	std::vector<Particle> particles = initialState;
	int uncollidedParticles = 1000;
	for (int loop = 0; loop < LONG_TERM; ++loop) {
		for (int i = 0; i < particles.size(); ++i) {
			if (!particles[i].collided) {
				particles[i].Next();
			}
		}
		for (int i = 0; i < particles.size(); ++i) {
			// This can be way more efficient.
			if (!particles[i].collided) {
				bool hasCollided = false;
				for (int j = 0; j < particles.size(); ++j) {
					if (i != j && !particles[j].collided && particles[i].position == particles[j].position) {
						particles[j].collided = true;
						hasCollided = true;
					}
				}
				if (hasCollided) {
					particles[i].collided = true;
				}
			}
		}
	}

	return uncollidedParticles;
}

Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Int3::Int3() : Int3(0, 0, 0) {}

Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Int3::Int3(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Int3& Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Int3::operator+=(const Int3& o) {
	x += o.x;
	y += o.y;
	z += o.z;
	return (*this);
}

int Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Int3::Manhatten() const {
	return std::abs(x) + std::abs(y) + std::abs(z);
}

Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Particle::Particle(Int3 position, Int3 velocity, Int3 acceleration) {
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
	collided = false;
}

void Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Particle::Next() {
	velocity += acceleration;
	position += velocity;
}

bool Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Particle::operator<(const Particle& o) {
	return acceleration.Manhatten() == o.acceleration.Manhatten() ? (velocity.Manhatten() == o.velocity.Manhatten() ? position.Manhatten() < o.position.Manhatten() : velocity.Manhatten() < velocity.Manhatten()) : acceleration.Manhatten() < o.acceleration.Manhatten();
}

bool Biendeo::AdventOfCode2017::Day20::ParticleSwarm::Int3::operator==(const Int3& o) {
	return x == o.x && y == o.y && z == o.z;
}
