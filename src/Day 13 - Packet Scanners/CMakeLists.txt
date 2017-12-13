# Day 13

set(SourceFiles Main.cpp PacketScanner.cpp)
set(HeaderFiles PacketScanner.h)

add_executable(Day13-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day13-1 PUBLIC "../Common/include")
target_link_libraries(Day13-1 PUBLIC Common)
install (TARGETS Day13-1 DESTINATION "../../bin")

add_executable(Day13-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day13-2 PUBLIC AOC_PART2)
target_include_directories(Day13-2 PUBLIC "../Common/include")
target_link_libraries(Day13-2 PUBLIC Common)
install (TARGETS Day13-2 DESTINATION "../../bin")