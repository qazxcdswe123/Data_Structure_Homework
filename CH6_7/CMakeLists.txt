PROJECT(CH6_7)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

INCLUDE(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.1.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
add_executable(CH6_7_Tests HashTable.test.cpp)
target_link_libraries(CH6_7_Tests PRIVATE Catch2::Catch2WithMain)