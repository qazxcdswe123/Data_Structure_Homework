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

    SECTION("Inserting numbers") {
        for (int i = 0; i < 10; ++i) {
            REQUIRE(list.insert(i + 1, i));
        }

        REQUIRE(list.getCurrentLength() == 10);
        REQUIRE(list.search(5) == 6);

        SECTION("Checking search related function") {
            REQUIRE(list.search(10) == -1); // not found
            REQUIRE(*list.getDataPointer(5) == 4);
            REQUIRE(list.getDataPointer(10) == nullptr);
        }

        SECTION("Manipulating Data") {
            int x = 5;
            REQUIRE(list.setData(1, x));
            REQUIRE_FALSE(list.search(5) == 6);
            REQUIRE(list.search(5) == 1);

            SECTION("Checking sort function") {
                // imply that the list is not sorted
                REQUIRE_FALSE(*list.getDataPointer(1) <= *list.getDataPointer(2));

                list.sort();
                // check if the list is sorted
                for (int i = 1; i < 9; ++i) {
                    REQUIRE(*list.getDataPointer(i) <= *list.getDataPointer(i + 1));
                }
            }
        }

        SECTION("Removing numbers") {
            int prevLength = list.getCurrentLength();
            for (int i = 0; i < 10; ++i) {
                int x;
                REQUIRE(list.remove(1, x));
                REQUIRE(x == i);
                REQUIRE(list.getCurrentLength() == prevLength - 1);
                prevLength--;
            }
        }

        SECTION("Checking copy constructor") {
            SeqList<int> list2(list);
            REQUIRE(list2.getCurrentLength() == list.getCurrentLength());
            REQUIRE(list2.getTotalSize() == list.getTotalSize());
            REQUIRE(list2.search(5) == 6);
            REQUIRE(list2.search(10) == -1);
            REQUIRE(*list2.getDataPointer(5) == 4);
            REQUIRE(list2.getDataPointer(10) == nullptr);
        }

        SECTION("Checking assignment operator") {
            SeqList<int> list2(10);
            list2 = list;
            REQUIRE(list2.getCurrentLength() == list.getCurrentLength());
            REQUIRE(list2.getTotalSize() == list.getTotalSize());
            REQUIRE(list2.search(5) == 6);
            REQUIRE(list2.search(10) == -1);
            REQUIRE(*list2.getDataPointer(5) == 4);
            REQUIRE(list2.getDataPointer(10) == nullptr);
        }
    }

}


