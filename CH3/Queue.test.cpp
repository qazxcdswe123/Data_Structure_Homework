//
// Created by yn on 17/10/2022.
//

#include "CircularQueue.cpp"

#include <iostream>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("CircularQueue", "[Queue]") {
    SECTION("Init") {
        CircularQueue<int> queue(10);
        REQUIRE(queue.isEmpty());
        queue.enQueue(1);
        queue.enQueue(2);
        queue.enQueue(3);

        SECTION("Testing Utility") {
            REQUIRE(queue.getSize() == 3);
            REQUIRE(queue.getHead() == 1);
            REQUIRE(!queue.isEmpty());
            REQUIRE(!queue.isFull());
        }

        SECTION("Testing DeQueue") {
            REQUIRE(queue.deQueue() == 1);
            REQUIRE(queue.deQueue() == 2);
            REQUIRE(queue.deQueue() == 3);
            REQUIRE(queue.isEmpty());
        }

        SECTION("Testing Make Empty") {
            queue.makeEmpty();
            REQUIRE(queue.isEmpty());
        }

        SECTION("Testing Exception") {
            queue.makeEmpty();
            REQUIRE_THROWS_AS(queue.deQueue(), const char *);
            REQUIRE_THROWS_AS(queue.getHead(), const char *);
        }
    }
}
