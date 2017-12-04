# Day 3

set(SourceFiles Main.cpp SpiralMemory.cpp)
set(HeaderFiles SpiralMemory.h)

add_executable(Day03-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day03-1 PUBLIC "../Common/include")
target_link_libraries(Day03-1 PUBLIC Common)
install (TARGETS Day03-1 DESTINATION "../../bin")

add_executable(Day03-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day03-2 PUBLIC AOC_PART2)
target_include_directories(Day03-2 PUBLIC "../Common/include")
target_link_libraries(Day03-2 PUBLIC Common)
install (TARGETS Day03-2 DESTINATION "../../bin")