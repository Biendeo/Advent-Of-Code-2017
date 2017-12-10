# Day 10

set(SourceFiles KnotHash.cpp Main.cpp)
set(HeaderFiles KnotHash.h)

add_executable(Day10-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day10-1 PUBLIC "../Common/include")
target_link_libraries(Day10-1 PUBLIC Common)
install (TARGETS Day10-1 DESTINATION "../../bin")

add_executable(Day10-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day10-2 PUBLIC AOC_PART2)
target_include_directories(Day10-2 PUBLIC "../Common/include")
target_link_libraries(Day10-2 PUBLIC Common)
install (TARGETS Day10-2 DESTINATION "../../bin")