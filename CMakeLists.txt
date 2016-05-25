cmake_minimum_required(VERSION 3.5)
project(AdCheckerBot)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(adcheckerbot ${SOURCE_FILES})
target_link_libraries(adcheckerbot PocoFoundation PocoUtil PocoNet PocoNetSSL PocoJSON)