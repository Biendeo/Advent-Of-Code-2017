# Day 18

set(SourceFiles Duet.cpp Main.cpp)
set(HeaderFiles Duet.h)

add_executable(Day18-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day18-1 PUBLIC "../Common/include")
target_link_libraries(Day18-1 PUBLIC Common)
install (TARGETS Day18-1 DESTINATION "../../bin")

add_executable(Day18-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day18-2 PUBLIC AOC_PART2)
target_include_directories(Day18-2 PUBLIC "../Common/include")
target_link_libraries(Day18-2 PUBLIC Common)
install (TARGETS Day18-2 DESTINATION "../../bin")