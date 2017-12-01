cmake_minimum_required(VERSION 3.8)
project(Assignment5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES proj5.cpp hashtable.hpp hashtable.h passserver.cpp passserver.h)
add_executable(Assignment5 ${SOURCE_FILES})