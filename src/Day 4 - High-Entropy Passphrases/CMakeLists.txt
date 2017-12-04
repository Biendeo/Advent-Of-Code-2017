# Day 4

set(SourceFiles Main.cpp HighEntropyPassphrase.cpp)
set(HeaderFiles HighEntropyPassphrase.h)

add_executable(Day04-1 ${SourceFiles} ${HeaderFiles})
install (TARGETS Day04-1 DESTINATION "../../bin")

add_executable(Day04-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day04-2 PUBLIC AOC_PART2)
install (TARGETS Day04-2 DESTINATION "../../bin")