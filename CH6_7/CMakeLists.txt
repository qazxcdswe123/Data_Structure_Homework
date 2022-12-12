PROJECT(CH6_7)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

add_executable(CH6_7_Tests HashTable.test.cpp)

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(CH6_7_Tests PRIVATE Catch2::Catch2WithMain)