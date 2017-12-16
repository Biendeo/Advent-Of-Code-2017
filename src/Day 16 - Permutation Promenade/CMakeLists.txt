# Day 16

set(SourceFiles Main.cpp PermutationPromenade.cpp)
set(HeaderFiles PermutationPromenade.h)

add_executable(Day16-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day16-1 PUBLIC "../Common/include")
target_link_libraries(Day16-1 PUBLIC Common)
install (TARGETS Day16-1 DESTINATION "../../bin")

add_executable(Day16-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day16-2 PUBLIC AOC_PART2)
target_include_directories(Day16-2 PUBLIC "../Common/include")
target_link_libraries(Day16-2 PUBLIC Common)
install (TARGETS Day16-2 DESTINATION "../../bin")