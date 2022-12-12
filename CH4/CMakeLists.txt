project(CH4)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

add_executable(CH4_tests String.test.cpp)
find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(CH4_tests PRIVATE Catch2::Catch2WithMain)
