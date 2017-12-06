# Day 6

set(SourceFiles Main.cpp MemoryReallocation.cpp)
set(HeaderFiles MemoryReallocation.h)

add_executable(Day06-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day06-1 PUBLIC "../Common/include")
target_link_libraries(Day06-1 PUBLIC Common)
install (TARGETS Day06-1 DESTINATION "../../bin")

add_executable(Day06-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day06-2 PUBLIC AOC_PART2)
target_include_directories(Day06-2 PUBLIC "../Common/include")
target_link_libraries(Day06-2 PUBLIC Common)
install (TARGETS Day06-2 DESTINATION "../../bin")