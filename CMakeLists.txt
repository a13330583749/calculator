#cmake_minimum_required(VERSION 2.6)
PROJECT (STACK CXX C)

set(SRC_LIST test.cpp MyStack.cpp)

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

MESSAGE(STATUS "THIS IS BINARY dir")
MESSAGE(STATUS "THIS IS SOURCE dir")

add_executable(../test ${SRC_LIST})