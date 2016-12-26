cmake_minimum_required(VERSION 2.8)
project(ConsoleGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


file(GLOB HEADER_FILES ${YOUR_DIRECTORY}include/*.h )

file(GLOB SOURCE_FILES ${YOUR_DIRECTORY}src/*.cpp )

set(OUTPUT_DIR ${YOUR_DIRECTORY}bin)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR})


add_executable(ConsoleGame ${SOURCE_FILES} ${HEADER_FILES})