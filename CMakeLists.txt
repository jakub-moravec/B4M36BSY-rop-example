cmake_minimum_required(VERSION 3.5)
project(rop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

#SET(CMAKE_CXX_FLAGS "-fno-stack-protector -z execstack -no-pie -m32")
SET(CMAKE_CXX_FLAGS "-fno-stack-protector -m32")

add_executable(rop ${SOURCE_FILES})