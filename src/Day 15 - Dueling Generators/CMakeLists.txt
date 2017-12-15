# Day 15

set(SourceFiles DuelingGenerators.cpp Main.cpp)
set(HeaderFiles DuelingGenerators.h)

add_executable(Day15-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day15-1 PUBLIC "../Common/include")
target_link_libraries(Day15-1 PUBLIC Common)
install (TARGETS Day15-1 DESTINATION "../../bin")

add_executable(Day15-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day15-2 PUBLIC AOC_PART2)
target_include_directories(Day15-2 PUBLIC "../Common/include")
target_link_libraries(Day15-2 PUBLIC Common)
install (TARGETS Day15-2 DESTINATION "../../bin")