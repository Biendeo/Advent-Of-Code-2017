# Day 14

set(SourceFiles DiskDefragmentation.cpp Main.cpp)
set(HeaderFiles DiskDefragmentation.h)

add_executable(Day14-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day14-1 PUBLIC "../Common/include")
target_link_libraries(Day14-1 PUBLIC Common)
install (TARGETS Day14-1 DESTINATION "../../bin")

add_executable(Day14-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day14-2 PUBLIC AOC_PART2)
target_include_directories(Day14-2 PUBLIC "../Common/include")
target_link_libraries(Day14-2 PUBLIC Common)
install (TARGETS Day14-2 DESTINATION "../../bin")