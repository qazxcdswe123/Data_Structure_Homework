project(CH2)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

add_executable(CH2_tests SeqList.test.cpp SinglyLinkedList.test.cpp CircularLinkedList.test.cpp)
find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(CH2_tests PRIVATE Catch2::Catch2WithMain)