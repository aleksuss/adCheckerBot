cmake_minimum_required(VERSION 3.5)
project(AdCheckerBot)

include_directories(/usr/local/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(adcheckerbot ${SOURCE_FILES})
