cmake_minimum_required(VERSION 3.1)
project(socsim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(HEADER_FILES include/Community.h)
set(SOURCE_FILES main.cpp src/Community.cpp)

add_executable(socsim ${SOURCE_FILES} ${HEADER_FILES})