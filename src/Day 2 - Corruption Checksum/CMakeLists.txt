# Day 2

set(SourceFiles CorruptionChecksum.cpp Main.cpp)
set(HeaderFiles CorruptionChecksum.h)

add_executable(Day02-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day02-1 PUBLIC "../Common/include")
target_link_libraries(Day02-1 PUBLIC Common)
install (TARGETS Day02-1 DESTINATION "../../bin")

add_executable(Day02-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day02-2 PUBLIC AOC_PART2)
target_include_directories(Day02-2 PUBLIC "../Common/include")
target_link_libraries(Day02-2 PUBLIC Common)
install (TARGETS Day02-2 DESTINATION "../../bin")