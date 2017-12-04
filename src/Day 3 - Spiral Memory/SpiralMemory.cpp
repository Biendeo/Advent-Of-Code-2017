// Day 3: SpiralMemory.cpp
// Definitions for the class that determines the spiral path.

#include "SpiralMemory.h"

#include <cmath>
#include <map>

Biendeo::AdventOfCode2017::Day3::SpiralMemory::SpiralMemory(int targetSquare) {
	this->targetSquare = targetSquare;
	this->generatedValues.insert(std::make_pair(Pos2(0, 0), 1));
	this->generatedValues.insert(std::make_pair(Pos2(1, 0), 1));
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::StepsToTarget() {
	return cacheOne.Get([&] {
		return CalculateStepsToTarget();
	});
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::FirstGreaterSquare() {
	return cacheTwo.Get([&] {
		return CalculateFirstGreaterSquare();
	});
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::CalculateStepsToTarget() {
	// Brute force calculating this isn't too bad until you get into the billions.
	Pos2 pos(0, 0);
	int ring = 0;
	Direction direction = Direction::Right;

	for (int currentSquare = 1; currentSquare < targetSquare; ++currentSquare) {
		// At a corner...
		if (std::abs(pos.x) == ring && std::abs(pos.y) == ring) {
			switch (direction) {
				case Direction::Up:
					--pos.x;
					direction = Direction::Left;
					break;
				case Direction::Left:
					--pos.y;
					direction = Direction::Down;
					break;
				case Direction::Down:
					++pos.x;
					direction = Direction::Right;
					break;
				case Direction::Right:
					// When going right at a corner, we go over one more space to move to the next
					// ring.
					++pos.x;
					++ring;
					direction = Direction::Up;
					break;
			}
		// Not at a corner...
		} else {
			switch (direction) {
				case Direction::Up:
					++pos.y;
					break;
				case Direction::Left:
					--pos.x;
					break;
				case Direction::Down:
					--pos.y;
					break;
				case Direction::Right:
					++pos.x;
					break;
			}
		}
	}

	return std::abs(pos.x) + std::abs(pos.y);
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::CalculateFirstGreaterSquare() {
	// This is very copy-paste, there's gotta be a better way to do this.
	Pos2 pos(0, 0);
	int ring = 0;
	Direction direction = Direction::Right;

	int lastValue = 1;

	while (lastValue <= targetSquare) {
		if (std::abs(pos.x) == ring && std::abs(pos.y) == ring) {
			switch (direction) {
				case Direction::Up:
					--pos.x;
					direction = Direction::Left;
					break;
				case Direction::Left:
					--pos.y;
					direction = Direction::Down;
					break;
				case Direction::Down:
					++pos.x;
					direction = Direction::Right;
					break;
				case Direction::Right:
					++pos.x;
					++ring;
					direction = Direction::Up;
					break;
			}
		} else {
			switch (direction) {
				case Direction::Up:
					++pos.y;
					break;
				case Direction::Left:
					--pos.x;
					break;
				case Direction::Down:
					--pos.y;
					break;
				case Direction::Right:
					++pos.x;
					break;
			}
		}
		lastValue = GetValueAtSquare(pos);
		generatedValues.insert(std::make_pair(pos, lastValue));
	}

	return lastValue;
}

int Biendeo::AdventOfCode2017::Day3::SpiralMemory::GetValueAtSquare(Pos2 pos) {
	if (generatedValues.find(pos) != generatedValues.end()) {
		return generatedValues.at(pos);
	} else {
		if (pos.x == -pos.y + 1 && pos.y < 0) {
			// The first value in each ring only needs to get the square to the left and up-left. The
			// exception is (1, 0), which doesn't define up-left, so it's just left, which is the
			// centre.
			return generatedValues.at(Pos2(pos.x - 1, pos.y)) + generatedValues.at(Pos2(pos.x - 1, pos.y + 1));
		} else if (std::abs(pos.x) == std::abs(pos.y)) {
			if (pos.x > 0 && pos.y > 0) {
				// The top-right corner needs to get the squares down and down-left.
				return generatedValues.at(Pos2(pos.x, pos.y - 1)) + generatedValues.at(Pos2(pos.x - 1, pos.y - 1));
			} else if (pos.x < 0 && pos.y > 0) {
				// The top-left corner needs to get the squares right and down-right.
				return generatedValues.at(Pos2(pos.x + 1, pos.y)) + generatedValues.at(Pos2(pos.x + 1, pos.y - 1));
			} else if (pos.x < 0 && pos.y < 0) {
				// The bottom-left corner needs to get the squares up and up-right.
				return generatedValues.at(Pos2(pos.x, pos.y + 1)) + generatedValues.at(Pos2(pos.x + 1, pos.y + 1));
			} else {
				// The bottom-right corner needs to get the squares left, up-left, and up.
				return generatedValues.at(Pos2(pos.x - 1, pos.y)) + generatedValues.at(Pos2(pos.x - 1, pos.y + 1)) + generatedValues.at(Pos2(pos.x, pos.y + 1));
			}
		} else {
			if (pos.x > 0 && pos.x > std::abs(pos.y)) {
				// The right side needs to get the squares left, down-left, and down and sometimes up-left.
				return generatedValues.at(Pos2(pos.x - 1, pos.y)) + generatedValues.at(Pos2(pos.x - 1, pos.y - 1)) + generatedValues.at(Pos2(pos.x, pos.y - 1)) + (pos.x != pos.y + 1 ? generatedValues.at(Pos2(pos.x - 1, pos.y + 1)) : 0);
			} else if (pos.y > 0 && std::abs(pos.x) < pos.y) {
				// The top side needs to get the squares down, down-right, and right and sometimes down-left.
				return generatedValues.at(Pos2(pos.x, pos.y - 1)) + generatedValues.at(Pos2(pos.x + 1, pos.y - 1)) + generatedValues.at(Pos2(pos.x + 1, pos.y)) + (-pos.x != pos.y - 1 ? generatedValues.at(Pos2(pos.x - 1, pos.y - 1)) : 0);
			} else if (pos.x < 0 && pos.x < pos.y) {
				// The left side needs to get the squares right, up-right, and up and sometimes down-right.
				return generatedValues.at(Pos2(pos.x + 1, pos.y)) + generatedValues.at(Pos2(pos.x + 1, pos.y + 1)) + generatedValues.at(Pos2(pos.x, pos.y + 1)) + (pos.x != pos.y - 1 ? generatedValues.at(Pos2(pos.x + 1, pos.y - 1)) : 0);
			} else {
				// The bottom side needs to get the squares up, up-left, and left and sometimes up-right.
				return generatedValues.at(Pos2(pos.x, pos.y + 1)) + generatedValues.at(Pos2(pos.x - 1, pos.y + 1)) + generatedValues.at(Pos2(pos.x - 1, pos.y)) + (pos.x != pos.y - 1 ? generatedValues.at(Pos2(pos.x + 1, pos.y + 1)) : 0);
			}
		}
	}
}
