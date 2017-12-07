# Day 7

set(SourceFiles Main.cpp RecursiveCircus.cpp)
set(HeaderFiles RecursiveCircus.h)

add_executable(Day07-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day07-1 PUBLIC "../Common/include")
target_link_libraries(Day07-1 PUBLIC Common)
install (TARGETS Day07-1 DESTINATION "../../bin")

add_executable(Day07-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day07-2 PUBLIC AOC_PART2)
target_include_directories(Day07-2 PUBLIC "../Common/include")
target_link_libraries(Day07-2 PUBLIC Common)
install (TARGETS Day07-2 DESTINATION "../../bin")