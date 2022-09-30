//
// Created by yn on 25/9/2022.
//

#include "SeqStack.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("SeqStack", "[Stack]") {
    SECTION("Init") {
        SeqStack<int> stack(10);
        REQUIRE(stack.isEmpty());
        stack.push(1);
        stack.push(2);
        stack.push(3);

        SECTION("Testing Utility") {
            REQUIRE(stack.getSize() == 3);
            REQUIRE(stack.getTop() == 3);
            REQUIRE(!stack.isEmpty());
            REQUIRE(!stack.isFull());
        }

        SECTION("Testing Pop") {
            REQUIRE(stack.pop() == 3);
            REQUIRE(stack.pop() == 2);
            REQUIRE(stack.pop() == 1);
            REQUIRE(stack.isEmpty());
        }

        SECTION("Testing Make Empty") {
            stack.makeStackEmpty();
            REQUIRE(stack.isEmpty());
        }

        SECTION("Testing Double Space") {
            for (int i = 0; i < 10; ++i) {
                stack.push(i);
            }
            REQUIRE(stack.getSize() == 13);
            REQUIRE_FALSE(stack.isFull());
        }

        SECTION("Testing Exception") {
            stack.makeStackEmpty();
            REQUIRE_THROWS_AS(stack.pop(), const char *);
            REQUIRE_THROWS_AS(stack.getTop(), const char *);
        }
    }
}