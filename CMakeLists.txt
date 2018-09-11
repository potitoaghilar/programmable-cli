cmake_minimum_required(VERSION 3.5.1)
project(CLI)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SOURCES "*.cpp")

add_executable(CLI ${SOURCES})