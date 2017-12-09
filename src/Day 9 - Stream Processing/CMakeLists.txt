# Day 9

set(SourceFiles Main.cpp StreamProcessing.cpp)
set(HeaderFiles StreamProcessing.h)

add_executable(Day09-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day09-1 PUBLIC "../Common/include")
target_link_libraries(Day09-1 PUBLIC Common)
install (TARGETS Day09-1 DESTINATION "../../bin")

add_executable(Day09-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day09-2 PUBLIC AOC_PART2)
target_include_directories(Day09-2 PUBLIC "../Common/include")
target_link_libraries(Day09-2 PUBLIC Common)
install (TARGETS Day09-2 DESTINATION "../../bin")