cmake_minimum_required(VERSION 3.14)
project(Assignment5)

set(CMAKE_CXX_STANDARD 17)

# Copies Beowulf
file(COPY beowulf.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY payload.txt DESTINATION ${CMAKE_BINARY_DIR})
add_executable(Assignment5 main.cpp)
