cmake_minimum_required(VERSION 3.27)
project(course)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

#SEARCH FOR .CPP AND .H FILES
file(GLOB_RECURSE headers "*.h")
file(GLOB_RECURSE sources "*.cpp")

list(FILTER sources EXCLUDE REGEX "cmake-build-debug/.*")
list(FILTER headers EXCLUDE REGEX "cmake-build-debug/.*")

add_executable(courseMariya ${headers} ${sources})
