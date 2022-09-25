project(CH2)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.1.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests test.cpp)
add_executable(CH2_tests SeqList.test.cpp SinglyLinkedList.test.cpp CircularLinkedList.test.cpp)
target_link_libraries(CH2_tests PRIVATE Catch2::Catch2WithMain)