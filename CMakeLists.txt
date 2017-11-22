cmake_minimum_required(VERSION 3.8)
project(rop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

SET(CMAKE_CXX_FLAGS "-fno-stack-protector")

add_executable(rop ${SOURCE_FILES})