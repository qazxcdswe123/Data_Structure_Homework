//
// Created by yn on 19/9/2022.
//

#include "LinkedList.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("LinkedList SetUp", "[LinkedList]") {
    LinkedList<int> LL;
    REQUIRE(LL.getCurrentLength() == 0);

    SECTION("Inserting numbers") {
        REQUIRE(LL.insert(0, 10));
        REQUIRE_FALSE(LL.insert(10, 100));
        REQUIRE(LL.getCurrentLength() == 1);

        SECTION("Testing Utilities") {
            REQUIRE(LL.getDataAtPosition(0) == 10);
            REQUIRE(LL.search(5) == -1);
            REQUIRE(LL.insert(0, 10));
            REQUIRE(LL.search(10) == 0);
        }
    }

    SECTION("Removing numbers") {
        REQUIRE(LL.insert(0, 0));
        REQUIRE(LL.getCurrentLength() == 1);
        REQUIRE(LL.remove(0));
        REQUIRE(LL.getCurrentLength() == 0);
    }

}
