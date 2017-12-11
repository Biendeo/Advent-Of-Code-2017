# Day 10

set(SourceFiles HexEd.cpp Main.cpp)
set(HeaderFiles HexEd.h)

add_executable(Day11-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day11-1 PUBLIC "../Common/include")
target_link_libraries(Day11-1 PUBLIC Common)
install (TARGETS Day11-1 DESTINATION "../../bin")

add_executable(Day11-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day11-2 PUBLIC AOC_PART2)
target_include_directories(Day11-2 PUBLIC "../Common/include")
target_link_libraries(Day11-2 PUBLIC Common)
install (TARGETS Day11-2 DESTINATION "../../bin")