# Day 12

set(SourceFiles DigitalPlumber.cpp Main.cpp)
set(HeaderFiles DigitalPlumber.h)

add_executable(Day12-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day12-1 PUBLIC "../Common/include")
target_link_libraries(Day12-1 PUBLIC Common)
install (TARGETS Day12-1 DESTINATION "../../bin")

add_executable(Day12-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day12-2 PUBLIC AOC_PART2)
target_include_directories(Day12-2 PUBLIC "../Common/include")
target_link_libraries(Day12-2 PUBLIC Common)
install (TARGETS Day12-2 DESTINATION "../../bin")