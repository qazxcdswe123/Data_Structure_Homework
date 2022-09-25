//
// Created by yn on 25/9/2022.
//

#include "CircularLinkedList.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("CircularLinkedList SetUp", "[CircularLinkedList]") {
    CircularLinkedList<int> CLL;
    REQUIRE(CLL.getCurrentLength() == 0);

    SECTION("Inserting numbers") {
        REQUIRE(CLL.insertAfterPosition(0, 10));
        REQUIRE_FALSE(CLL.insertAfterPosition(10, 100));
        REQUIRE(CLL.getCurrentLength() == 1);

        SECTION("Testing Utilities") {
            REQUIRE(CLL.getDataAtPosition(0) == 10);
            REQUIRE(CLL.search(5) == -1);
            REQUIRE(CLL.insertAfterPosition(0, 100));
            REQUIRE(CLL.search(100) == 0);
        }

        CLL.print();

        SECTION("Removing numbers") {
            REQUIRE(CLL.insertAfterPosition(0, 0));
            REQUIRE(CLL.getCurrentLength() == 2);
            REQUIRE(CLL.remove(0));
            REQUIRE(CLL.getCurrentLength() == 1);
        }
    }
}