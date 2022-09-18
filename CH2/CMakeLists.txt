project(CH2)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(Google_Tests_CH2_Run SeqList.test.cpp)
target_link_libraries(Google_Tests_CH2_Run GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Google_Tests_CH2_Run)