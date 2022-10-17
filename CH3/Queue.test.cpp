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
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        SECTION("Testing Utility") {
            REQUIRE(queue.getSize() == 3);
            REQUIRE(queue.getFront() == 1);
            REQUIRE(!queue.isEmpty());
            REQUIRE(!queue.isFull());
        }

        SECTION("Testing DeQueue") {
            REQUIRE(queue.dequeue() == 1);
            REQUIRE(queue.dequeue() == 2);
            REQUIRE(queue.dequeue() == 3);
            REQUIRE(queue.isEmpty());
        }

        SECTION("Testing Make Empty") {
            queue.makeEmpty();
            REQUIRE(queue.isEmpty());
        }

        SECTION("Testing Exception") {
            queue.makeEmpty();
            REQUIRE_THROWS_AS(queue.dequeue(), const char *);
            REQUIRE_THROWS_AS(queue.getFront(), const char *);
        }
    }
}
