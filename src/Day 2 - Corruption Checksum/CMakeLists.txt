# Day 2

set(SourceFiles CorruptionChecksum.cpp Main.cpp)
set(HeaderFiles CorruptionChecksum.h)

add_executable(Day02-1 ${SourceFiles} ${HeaderFiles})
install (TARGETS Day02-1 DESTINATION "../../bin")

add_executable(Day02-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day02-2 PUBLIC AOC_PART2)
install (TARGETS Day02-2 DESTINATION "../../bin")