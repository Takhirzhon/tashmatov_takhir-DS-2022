#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"

#include <sstream>
#include <sstream>
#include <string>
#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for (const auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");
    }
}

TEST_CASE("Constructor with  a string")
{
    ostringstream sout;

    SUBCASE("postive number")
    {
        BigInt x("123456789123456789");
        sout << x;
        REQUIRE(sout.str() == "123456789123456789");
    }

    SUBCASE("number with sign")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");

        sout.str("");
        BigInt y("+123");
        sout << y;
        REQUIRE(sout.str() == "123");

        sout.str("");
        BigInt z("-0");
        sout << z;
        REQUIRE(sout.str() == "0");
    }

    SUBCASE("leading zeroes")
    {
        BigInt x("-0000123");
        sout << x;
        REQUIRE(sout.str() == "-123");

        sout.str("");
        BigInt y("+00000000");
        sout << y;
        REQUIRE(sout.str() == "0");
    }

    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }

    SUBCASE("just sign")
    {
        REQUIRE_THROWS_AS(BigInt("+"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }

    SUBCASE("incorrect symbols")
    {
        REQUIRE_THROWS_AS(BigInt("123-1"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("123a123"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("123123b"), runtime_error);
    }
}

TEST_CASE("Addition")
{
    ostringstream sout;

    // SUBCASE("positive + positive, test#1")
    // {
    //     BigInt x("193");
    //     BigInt y("59");
    //     sout << x + y;
    //     REQUIRE(sout.str() == "252");
    // }

    // SUBCASE("positive + positive, test#2")
    // {
    //     for (int x = 0; x <= 1000; x++)
    //     {
    //         for (int y = 0; y <= 1000; y++)
    //         {
    //             BigInt a(to_string(x));
    //             BigInt b(to_string(y));
    //             sout << a + b;
    //             REQUIRE(sout.str() == to_string(x + y));
    //             sout.str("");
    //         }
    //     }
    // }

    // SUBCASE("positive + negative")
    // {
    //     BigInt x("999");
    //     BigInt y("-5");
    //     sout << x + y;
    //     REQUIRE(sout.str() == "1000");
    // }

    SUBCASE("negative + positive")
    {
    }
    // SUBCASE("negative + negative")
    // {
    //     BigInt a("-2");
    //     BigInt b("-5");
    //     sout << (a) + (b);
    //     REQUIRE(sout.str() == "7");
    // }
}

TEST_CASE("equality tests")
{
    SUBCASE("positive and positive")
    {
        BigInt x("+123");
        BigInt y("00000123");
        REQUIRE(x == y);
    }

    SUBCASE("negative and positive")
    {
        BigInt x("-123");
        BigInt y("00000123");
        REQUIRE(x != y);
    }

    SUBCASE("positive and negative")
    {
        BigInt x("-123");
        BigInt y("+00000123");
        REQUIRE(x != y);
    }

    SUBCASE("negative and negative")
    {
        BigInt x("-123");
        BigInt y("-00000123");
        REQUIRE(x == y);
    }
}