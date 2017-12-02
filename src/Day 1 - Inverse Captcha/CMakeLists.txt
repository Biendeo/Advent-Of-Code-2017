# Day 1

set(SourceFiles InverseCaptcha.cpp Main.cpp)
set(HeaderFiles InverseCaptcha.h)

add_executable(Day01-1 ${SourceFiles} ${HeaderFiles})
install (TARGETS Day01-1 DESTINATION "../../bin")

add_executable(Day01-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day01-2 PUBLIC AOC_PART2)
install (TARGETS Day01-2 DESTINATION "../../bin")
