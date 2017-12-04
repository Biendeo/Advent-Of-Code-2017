# Day 4

set(SourceFiles Main.cpp HighEntropyPassphrase.cpp)
set(HeaderFiles HighEntropyPassphrase.h)

add_executable(Day04-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day04-1 PUBLIC "../Common/include")
target_link_libraries(Day04-1 PUBLIC Common)
install (TARGETS Day04-1 DESTINATION "../../bin")

add_executable(Day04-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day04-2 PUBLIC AOC_PART2)
target_include_directories(Day04-2 PUBLIC "../Common/include")
target_link_libraries(Day04-2 PUBLIC Common)
install (TARGETS Day04-2 DESTINATION "../../bin")