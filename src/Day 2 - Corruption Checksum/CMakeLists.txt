# Day 2

set(SourceFiles Main.cpp)
set(HeaderFiles "")

add_executable(Day02-1 ${SourceFiles} ${HeaderFiles})
install (TARGETS Day02-1 DESTINATION "../../bin")

add_executable(Day02-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day01-2 PUBLIC AOC_PART2)
install (TARGETS Day02-2 DESTINATION "../../bin")