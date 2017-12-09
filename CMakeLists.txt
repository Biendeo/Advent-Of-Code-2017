cmake_minimum_required (VERSION 3.9)

project(AdventOfCode2017)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_property(GLOBAL PROPERTY CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

# Not too sure why Visual Studio doesn't automatically do C++17 from the previous statement, this ensures it.
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	add_compile_options("/std:c++latest")
endif()

include_directories("src/Common/include")

add_subdirectory("src/Common")
add_subdirectory("src/Day 1 - Inverse Captcha")
add_subdirectory("src/Day 2 - Corruption Checksum")
add_subdirectory("src/Day 3 - Spiral Memory")
add_subdirectory("src/Day 4 - High-Entropy Passphrases")
add_subdirectory("src/Day 5 - A Maze of Twisty Trampolines, All Alike")
add_subdirectory("src/Day 6 - Memory Reallocation")
add_subdirectory("src/Day 7 - Recursive Circus")
add_subdirectory("src/Day 8 - I Heard You Like Registers")
add_subdirectory("src/Day 9 - Stream Processing")