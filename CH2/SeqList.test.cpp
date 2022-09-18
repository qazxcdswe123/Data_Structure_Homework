//
// Created by yn on 18/9/2022.
//
#include "SeqList.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Set Up") {
    SeqList<int> list(10);
    REQUIRE(list.getTotalSize() == 10);
    REQUIRE(list.getCurrentLength() == 0);
    REQUIRE(list.isEmpty());
    REQUIRE_FALSE(list.isFull());
}


