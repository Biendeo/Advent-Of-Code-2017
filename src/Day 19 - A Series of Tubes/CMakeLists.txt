# Day 19

set(SourceFiles Main.cpp SeriesOfTubes.cpp)
set(HeaderFiles SeriesOfTubes.h)

add_executable(Day19-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day19-1 PUBLIC "../Common/include")
target_link_libraries(Day19-1 PUBLIC Common)
install (TARGETS Day19-1 DESTINATION "../../bin")

add_executable(Day19-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day19-2 PUBLIC AOC_PART2)
target_include_directories(Day19-2 PUBLIC "../Common/include")
target_link_libraries(Day19-2 PUBLIC Common)
install (TARGETS Day19-2 DESTINATION "../../bin")