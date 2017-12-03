// Day 3: SpiralMemory.cpp
// Definitions for the class that determines the spiral path.

#include "SpiralMemory.h"

#include <cmath>
#include <iostream>

Biendeo::AdventOfCode2017::Day3::SpiralMemory::SpiralMemory(int targetSquare) {
	this->targetSquare = targetSquare;
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::StepsToTarget() {
	if (!part1Cache.calculated) {
		part1Cache.value = CalculateStepsToTarget();
		part1Cache.calculated = true;
	}
	return part1Cache.value;
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::FirstGreaterSquare() {
	if (!part2Cache.calculated) {
		part2Cache.value = CalculateFirstGreaterSquare();
		part2Cache.calculated = true;
	}
	return part2Cache.value;
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::CalculateStepsToTarget() {
	// Brute force calculating this isn't too bad until you get into the billions.
	int x = 0;
	int y = 0;
	int ring = 0;
	Direction direction = Direction::Right;

	for (int currentSquare = 1; currentSquare < targetSquare; ++currentSquare) {
		// At a corner...
		if (std::abs(x) == ring && std::abs(y) == ring) {
			switch (direction) {
				case Direction::Up:
					--x;
					direction = Direction::Left;
					break;
				case Direction::Left:
					--y;
					direction = Direction::Down;
					break;
				case Direction::Down:
					++x;
					direction = Direction::Right;
					break;
				case Direction::Right:
					// When going right at a corner, we go over one more space to move to the next
					// ring.
					++x;
					++ring;
					direction = Direction::Up;
					break;
			}
		// Not at a corner...
		} else {
			switch (direction) {
				case Direction::Up:
					++y;
					break;
				case Direction::Left:
					--x;
					break;
				case Direction::Down:
					--y;
					break;
				case Direction::Right:
					++x;
					break;
			}
		}
	}

	return std::abs(x) + std::abs(y);
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::CalculateFirstGreaterSquare() {
	// This is very copy-paste, there's gotta be a better way to do this.
	int x = 0;
	int y = 0;
	int ring = 0;
	Direction direction = Direction::Right;

	int lastValue = 1;

	while (lastValue <= targetSquare) {
		if (std::abs(x) == ring && std::abs(y) == ring) {
			switch (direction) {
				case Direction::Up:
					--x;
					direction = Direction::Left;
					break;
				case Direction::Left:
					--y;
					direction = Direction::Down;
					break;
				case Direction::Down:
					++x;
					direction = Direction::Right;
					break;
				case Direction::Right:
					++x;
					++ring;
					direction = Direction::Up;
					break;
			}
		} else {
			switch (direction) {
				case Direction::Up:
					++y;
					break;
				case Direction::Left:
					--x;
					break;
				case Direction::Down:
					--y;
					break;
				case Direction::Right:
					++x;
					break;
			}
		}
		lastValue = GetValueAtSquare(x, y);
	}

	return lastValue;
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::GetValueAtSquare(int x, int y) {
	// While caching might be nice (such as storing these values in a map), a recursive system seems
	// to be the quickest to implement. Caching would make this much less hideous though, and would
	// save a lot of re-calculations. It may also be interesting to implement this as a constexpr.

	// Base cases.
	if (x == 0 && y == 0) {
		return 1;
	} else if (x == 1 && y == 0) {
		return 1;
	} else if (x == -y + 1 && y < 0) {
		// The first value in each ring only needs to get the square to the left and up-left. The
		// exception is (1, 0), which doesn't define up-left, so it's just left, which is the
		// centre.
		return GetValueAtSquare(x - 1, y) + GetValueAtSquare(x - 1, y + 1);
	} else if (std::abs(x) == std::abs(y)) {
		// Corners:
		if (x > 0 && y > 0) {
			// The top-right corner needs to get the squares down and down-left.
			return GetValueAtSquare(x, y - 1) + GetValueAtSquare(x - 1, y - 1);
		} else if (x < 0 && y > 0) {
			// The top-left corner needs to get the squares right and down-right.
			return GetValueAtSquare(x + 1, y) + GetValueAtSquare(x + 1, y - 1);
		} else if (x < 0 && y < 0) {
			// The bottom-left corner needs to get the squares up and up-right.
			return GetValueAtSquare(x, y + 1) + GetValueAtSquare(x + 1, y + 1);
		} else {
			// The bottom-right corner needs to get the squares left, up-left, and up.
			return GetValueAtSquare(x - 1, y) + GetValueAtSquare(x - 1, y + 1) + GetValueAtSquare(x, y + 1);
		}
	} else {
		if (x > 0 && x > std::abs(y)) {
			// The right side needs to get the squares left, down-left, and down and sometimes up-left.
			return GetValueAtSquare(x - 1, y) + GetValueAtSquare(x - 1, y - 1) + GetValueAtSquare(x, y - 1) + (x != y + 1 ? GetValueAtSquare(x - 1, y + 1) : 0);
		} else if (y > 0 && std::abs(x) < y) {
			// The top side needs to get the squares down, down-right, and right and sometimes down-left.
			return GetValueAtSquare(x, y - 1) + GetValueAtSquare(x + 1, y - 1) + GetValueAtSquare(x + 1, y) + (-x != y - 1 ? GetValueAtSquare(x - 1, y - 1) : 0);
		} else if (x < 0 && x < y) {
			// The left side needs to get the squares right, up-right, and up and sometimes down-right.
			return GetValueAtSquare(x + 1, y) + GetValueAtSquare(x + 1, y + 1) + GetValueAtSquare(x, y + 1) + (x != y - 1 ? GetValueAtSquare(x + 1, y - 1) : 0);
		} else {
			// The bottom side needs to get the squares up, up-left, and left and sometimes up-right.
			return GetValueAtSquare(x, y + 1) + GetValueAtSquare(x - 1, y + 1) + GetValueAtSquare(x - 1, y) + (x != y - 1 ? GetValueAtSquare(x + 1, y + 1) : 0);
		}
	}
}
