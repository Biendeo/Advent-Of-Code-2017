# Advent-Of-Code-2017
This is my attempt at solving each puzzle in the [Advent of Code 2017](http://adventofcode.com/2017) challenge. I've attempted all of these solutions using C++17.

I've never used CMake formally before, so I've tried to use it here. Each project should be broken up into two executables. I've made it so that the second part utilises the same codebase as the first part, but with the preprocessor definition `AOC_PART2` to separate them. Each day's task is listed down below.

### Day 1: Inverse Captcha
Take in a string of digits (given as a commandline argument), and compute a sum based on the digits.

### Day 2: Corruption Checksum
Take in a file of integers separated by tabs (given as a commandline argument), and computes a checksum based on those numbers in each row.

### Day 3: Spiral Memory
Take in an integer and compute a value of a kind (either the Manhatten Distance or the next greatest value) based on that.