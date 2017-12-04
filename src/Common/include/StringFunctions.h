// Common: StringFunctions.h
// Useful functions for operating on strings.

#pragma once

#include <string>
#include <vector>

namespace Biendeo::AdventOfCode2017 {
	/// Returns whether two strings are anagrams of each other.
	bool IsAnagram(const std::string& a, const std::string& b);

	/// Returns a vector of strings splitting the original by a delimiter.
	std::vector<std::string> Split(const std::string& str, const char delimiter = ' ');
}