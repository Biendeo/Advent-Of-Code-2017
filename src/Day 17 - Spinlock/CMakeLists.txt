# Day 17

set(SourceFiles Main.cpp Spinlock.cpp)
set(HeaderFiles Spinlock.h)

add_executable(Day17-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day17-1 PUBLIC "../Common/include")
target_link_libraries(Day17-1 PUBLIC Common)
install (TARGETS Day17-1 DESTINATION "../../bin")

add_executable(Day17-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day17-2 PUBLIC AOC_PART2)
target_include_directories(Day17-2 PUBLIC "../Common/include")
target_link_libraries(Day17-2 PUBLIC Common)
install (TARGETS Day17-2 DESTINATION "../../bin")