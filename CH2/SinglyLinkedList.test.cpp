//
// Created by yn on 19/9/2022.
//

#include "SinglyLinkedList.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("SinglyLinkedList SetUp", "[SinglyLinkedList]") {
    SinglyLinkedList<int> LL;
    REQUIRE(LL.getCurrentLength() == 0);

    SECTION("Inserting numbers") {
        REQUIRE(LL.insertAfterPosition(0, 10));
        REQUIRE_FALSE(LL.insertAfterPosition(10, 100));
        REQUIRE(LL.getCurrentLength() == 1);

        SECTION("Testing Utilities") {
            REQUIRE(LL.getDataAtPosition(0) == 10);
            REQUIRE(LL.search(5) == -1);
            REQUIRE(LL.insertAfterPosition(0, 10));
            REQUIRE(LL.search(10) == 0);
        }
    }

    SECTION("Testing Sort and remove duplicates") {
        LL.insertAfterPosition(0, 10);
        LL.insertAfterPosition(0, 5);
        LL.insertAfterPosition(0, 5);
        LL.insertAfterPosition(0, 5);
        LL.insertAfterPosition(0, 2);
        LL.insertAfterPosition(0, 4);
        LL.insertAfterPosition(0, 6);
        LL.insertAfterPosition(0, 7);
        LL.insertAfterPosition(0, 8);
        LL.insertAfterPosition(0, 9);
        LL.insertAfterPosition(0, 0);
        LL.print();
        LL.sort();
        LL.print();
        LL.removeDuplicates();
        LL.print();
    }

    SECTION("Removing numbers") {
        REQUIRE(LL.insertAfterPosition(0, 0));
        REQUIRE(LL.getCurrentLength() == 1);
        REQUIRE(LL.remove(0));
        REQUIRE(LL.getCurrentLength() == 0);
    }
}
