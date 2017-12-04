# Common library

set(CommonSourceFiles StringFunctions.cpp)
set(CommonHeaderFiles include/CachedValue.h include/StringFunctions.h)

add_library(Common STATIC ${CommonSourceFiles} ${CommonHeaderFiles})
target_include_directories(Common PUBLIC include)
install (TARGETS Common DESTINATION "../../lib")