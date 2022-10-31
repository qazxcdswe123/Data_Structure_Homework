//
// Created by yn on 26/10/2022.
//

#include <catch2/catch_test_macros.hpp>
#include "String.cpp"

TEST_CASE("String", "[String]") {
    SECTION("Init") {
        String s1("Hello");
        String s2(s1);
        String s3 = s1;
        String s4;
        s4 = s1;

        SECTION("Testing Utility") {
            REQUIRE(s1.getLen() == 5);
            REQUIRE(s2.getLen() == 5);
            REQUIRE(s3.getLen() == 5);
            REQUIRE(s4.getLen() == 5);
            REQUIRE(s1 == s2);
            REQUIRE(s1 == s3);
            REQUIRE(s1 == s4);
            REQUIRE(s2 == s3);
            REQUIRE(s2 == s4);
            REQUIRE(s3 == s4);
        }

        SECTION("Testing Operator Overloading") {
            String s5 = s1 + s2;
            String s6("HelloHello");
            REQUIRE(s5.getLen() == 10);
            REQUIRE(s5 == s6);
            REQUIRE(s5 != s1);
            REQUIRE(s5 > s1);
            REQUIRE(s1 < s5);
        }

        SECTION("Testing Substring") {
            String s5 = s1(1, 4);
            String s6("ell");
            REQUIRE(s5.getLen() == 3);
            REQUIRE(s5 == s6);
        }

        SECTION("Testing Find") {
            REQUIRE(s1.naiveFind("l") == 2);
            REQUIRE(s1.naiveFind("ll") == 2);
            REQUIRE(s1.find("H") == 0);
        }
    }
}