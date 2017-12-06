# Day 5

set(SourceFiles Main.cpp MTTAA.cpp)
set(HeaderFiles MTTAA.h)

add_executable(Day05-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day05-1 PUBLIC "../Common/include")
target_link_libraries(Day05-1 PUBLIC Common)
install (TARGETS Day05-1 DESTINATION "../../bin")

add_executable(Day05-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day05-2 PUBLIC AOC_PART2)
target_include_directories(Day05-2 PUBLIC "../Common/include")
target_link_libraries(Day05-2 PUBLIC Common)
install (TARGETS Day05-2 DESTINATION "../../bin")