# Day 20

set(SourceFiles Main.cpp ParticleSwarm.cpp)
set(HeaderFiles ParticleSwarm.h)

add_executable(Day20-1 ${SourceFiles} ${HeaderFiles})
target_include_directories(Day20-1 PUBLIC "../Common/include")
target_link_libraries(Day20-1 PUBLIC Common)
install (TARGETS Day20-1 DESTINATION "../../bin")

add_executable(Day20-2 ${SourceFiles} ${HeaderFiles})
target_compile_definitions(Day20-2 PUBLIC AOC_PART2)
target_include_directories(Day20-2 PUBLIC "../Common/include")
target_link_libraries(Day20-2 PUBLIC Common)
install (TARGETS Day20-2 DESTINATION "../../bin")