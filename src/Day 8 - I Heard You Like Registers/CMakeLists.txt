# Day 8

set(SourceFiles IHYLR.cpp Main.cpp)
set(HeaderFiles IHYLR.h)

add_executable(Day08-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day08-1 PUBLIC "../Common/include")
target_link_libraries(Day08-1 PUBLIC Common)
install (TARGETS Day08-1 DESTINATION "../../bin")

add_executable(Day08-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day08-2 PUBLIC AOC_PART2)
target_include_directories(Day08-2 PUBLIC "../Common/include")
target_link_libraries(Day08-2 PUBLIC Common)
install (TARGETS Day08-2 DESTINATION "../../bin")