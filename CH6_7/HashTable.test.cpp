//
// Created by yn on 23/11/2022.
//

#include "HashTable.cpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("HashTable", "[HashTable]") {
    SECTION("init") {
        // use prime number for capacity to reduce collisions
        HashTable<std::string> table(23);
        table.insert("hello");
        table.insert("world");
        table.insert("this");
        table.insert("is");
        table.insert("a");
        table.insert("test");
        table.insert("for");
        table.insert("hash");
        table.insert("table");
        table.insert("implementation");
        table.insert("using");
        table.insert("linear");
        table.insert("probing");
        table.print();
        std::cout << std::endl;

        SECTION("search") {
            REQUIRE(table.search("hello"));
            REQUIRE(table.search("world"));
            REQUIRE(table.search("this"));
            REQUIRE(table.search("is"));
            REQUIRE(table.search("a"));
            REQUIRE(table.search("test"));
            REQUIRE(table.search("for"));
            REQUIRE(table.search("hash"));
            REQUIRE(table.search("table"));
            REQUIRE(table.search("implementation"));
            REQUIRE(table.search("using"));
            REQUIRE(table.search("linear"));
            REQUIRE(table.search("probing"));
        }

        SECTION("remove") {
            REQUIRE(table.remove("hello"));
            REQUIRE(table.remove("world"));
            REQUIRE(table.remove("this"));
            REQUIRE(table.remove("is"));
            REQUIRE(table.remove("a"));
            REQUIRE(table.remove("test"));
            table.print();
            std::cout << std::endl;
        }
    }
}