# Advent-Of-Code-2017
This is my attempt at solving each puzzle in the [Advent of Code 2017](http://adventofcode.com/2017) challenge. I've attempted all of these solutions using C++17.

If you are also attempting the challenge, please try and solve these on your own first.

I've never used CMake formally before, so I've tried to use it here. Each project should be broken up into two executables. I've made it so that the second part utilises the same codebase as the first part, but with the preprocessor definition `AOC_PART2` to separate them. Each day's task is listed down below.

### Day 1: Inverse Captcha
Take in a string of digits (given as a commandline argument), and compute a sum based on the digits.

### Day 2: Corruption Checksum
Take in a file of integers separated by tabs (given as a commandline argument), and computes a checksum based on those numbers in each row.

### Day 3: Spiral Memory
Take in an integer and compute a value of a kind (either the Manhatten Distance or the next greatest value) based on that.

### Day 4: High-Entropy Passphrases
Take in a file of passphrases (lower-case character strings separated by spaces) (given as a commandline argument), and computes how many of those are valid.

### Day 5: A Maze of Twisty Trampolines, All Alike
Take in a file of integers, and computes how many steps it takes to leave the system.

### Day 6: Memory Reallocation
Take in a file of one row of tab separated integers, and compute how many steps it takes to reach a duplicate state using certain rules.

### Day 7: Recursive Circus
Take in a file describing a tree structure out of order, and compute the root node's name, and the correct value of an incorrect node.

### Day 8: I Heard You Like Registers
Take in a file describing register operations and conditions, and compute the highest value at the end, and at any point in the program.

### Day 9: Stream Processing
Take in a file of a stream of characters, and compute its score and the number of garbage characters in it.

### Day 10: Knot Hash
Take in a file of comma-separated integers, and compute a Knot Hash value based on that.

### Day 11: Hex Ed
Take in a file of hexagonal directions, and compute how far away the path leads.

### Day 12: Digital Plumber
Take in a file of connections and determine how many are connected to a program.