// Day 1: InverseCaptcha.h
// Declarations for the class that determines the inverse captcha.

#include <string>

#include "CachedValue.h"

namespace Biendeo::AdventOfCode2017::Day1 {
	class InverseCaptcha {
		public:
		/// Constructs an InverseCaptcha calculator with the given string.
		InverseCaptcha(const std::string& inputString);

		/// Returns the sum calculated by the string. If the sum has been calculated already, this
		/// value is cached.
		int Sum();

		private:
		// Could I make this const?
		std::string inputString;
		// This is just for convenience, the string should also know this.
		size_t length;

		CachedValue<int> cache;

		/// Calculates the sum and returns it as a value. This doesn't cache it.
		int CalculateSum();
	};
}