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

    SUBCASE("positive + positive, test#1")
    {
        BigInt x("193");
        BigInt y("59");
        sout << x + y;
        REQUIRE(sout.str() == "252");
    }

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

    SUBCASE("positive + negative")
    {
        BigInt x("999");
        BigInt y("-5");
        sout << x + y;
        REQUIRE("994");
    }

    SUBCASE("negative + positive")
    {
    }
    SUBCASE("negative + negative")
    {
        BigInt a("-2");
        BigInt b("-5");
        sout << (a) + (b);
        REQUIRE(sout.str() == "-7");
    }
}

TEST_CASE("Substraction")
{
    SUBCASE("positive - negative")
    {
        BigInt x1(3);
        BigInt y1(-2);
        REQUIRE(x1 - y1 == 5);

        for (int x2 = 0; x2 <= 100; ++x2)
        {
            for (int y2 = -100; y2 < 0; ++y2)
            {
                BigInt a(x2);
                BigInt b(y2);
                REQUIRE(a - b == x2 - y2);
            }
        }
    }

    SUBCASE("negative - positive")
    {
        BigInt x1(-3);
        BigInt y1(2);
        REQUIRE(x1 - y1 == -5);
        for (int x2 = -100; x2 < 0; ++x2)
        {
            for (int y2 = 0; y2 <= 100; ++y2)
            {
                BigInt a(x2);
                BigInt b(y2);
                REQUIRE(a - b == x2 - y2);
            }
        }
    }

    SUBCASE("positive - positive")
    {
        BigInt x1(1024);
        BigInt y1(526);
        REQUIRE(x1 - y1 == 1024 - 526);

        BigInt x2(5657);
        BigInt y2(767);
        REQUIRE(x2 - y2 == 5657 - 767);

        BigInt x3(1000);
        BigInt y3(1);
        REQUIRE(x3 - y3 == 999);

        BigInt x4(526);
        BigInt y4(1024);
        REQUIRE(x4 - y4 == (-498));
    }

    SUBCASE("negative - negative")
    {
        BigInt x1(-1024);
        BigInt y1(-526);
        REQUIRE(x1 - y1 == (-498));

        BigInt x2(-526);
        BigInt y2(-1024);
        REQUIRE(x2 - y2 == 498);
    }
}

TEST_CASE("constructor with long parametr")
{
    ostringstream sout;
    for (int i = -1000; i <= 1000; i++)
    {
        BigInt x(i);
        sout << x;
        REQUIRE(sout.str() == to_string(i));
        sout.str("");
    }
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

    SUBCASE("+0 and -0")
    {
        BigInt x("+000000000000");
        BigInt y("-00000");
        REQUIRE(x == y);
    }
}

TEST_CASE("Comparison tests")
{
    SUBCASE("<")
    {
        REQUIRE(BigInt("-123") < BigInt("1"));
        REQUIRE(BigInt("-123") < BigInt("0"));
        REQUIRE(BigInt("-123") < BigInt("123"));
        REQUIRE_FALSE(BigInt("1") < BigInt("-123"));
        REQUIRE_FALSE(BigInt("0") < BigInt("-123"));
        REQUIRE_FALSE(BigInt("123") < BigInt("-123"));
        REQUIRE(BigInt("909") < BigInt("981"));
        REQUIRE(BigInt("99") < BigInt("9999"));
    }

    SUBCASE(">")
    {
        REQUIRE(BigInt("123") > BigInt("1"));
        REQUIRE(BigInt("123") > BigInt("0"));
        REQUIRE(BigInt("123") > BigInt("-123"));
        REQUIRE_FALSE(BigInt("123456789") > BigInt("987654321"));
        REQUIRE_FALSE(BigInt("-123156") > BigInt("-13"));
        REQUIRE_FALSE(BigInt("-123") > BigInt("0"));
        REQUIRE(BigInt("132456798") > BigInt("12312346"));
        REQUIRE(BigInt("123456789") > BigInt("-123456789"));
    }

    SUBCASE(">=")
    {
        REQUIRE(BigInt("123") >= BigInt("1"));
        REQUIRE(BigInt("1456") >= BigInt("1451"));
        REQUIRE(BigInt("0") >= BigInt("0"));
        REQUIRE(BigInt("123456789") >= BigInt("123456789"));
        REQUIRE(BigInt("11") >= BigInt("11"));
        REQUIRE_FALSE(BigInt("14") >= BigInt("15"));
        REQUIRE_FALSE(BigInt("123") >= BigInt("132"));
        REQUIRE_FALSE(BigInt("123456789") >= BigInt("987654321"));
    }

    SUBCASE("<=")
    {
        REQUIRE(BigInt("123") <= BigInt("124"));
        REQUIRE(BigInt("1456") <= BigInt("1500"));
        REQUIRE(BigInt("0") <= BigInt("0"));
        REQUIRE(BigInt("123456789") <= BigInt("123456789"));
        REQUIRE(BigInt("-11") <= BigInt("11"));
        REQUIRE_FALSE(BigInt("14") <= BigInt("11"));
        REQUIRE_FALSE(BigInt("1243") <= BigInt("132"));
        REQUIRE_FALSE(BigInt("123456789") <= BigInt("97654321"));
    }
}

TEST_CASE("input operator")
{
    ostringstream sout;

    SUBCASE("correct input TEST #3")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }
    SUBCASE("correct input TEST #1")
    {
        istringstream sinp("123x123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
    }
    SUBCASE("correct input TEST #5")
    {
        istringstream sinp("+ 123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("correct input TEST #2")
    {
        istringstream sinp("123x");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
        char ch;
        sinp.clear();
        sinp >> ch;
        REQUIRE(ch == 'x');
    }

    SUBCASE("correct input TEST #3")
    {
        istringstream sinp("    -123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == -123);
    }
    SUBCASE("correct input TEST")
    {
        istringstream sinp("     +123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }
    SUBCASE("correct input TEST")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }

    SUBCASE("incorrect input")
    {
        istringstream sinp("+ 123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("incorrect input #2")
    {
        istringstream sinp("hello");
        BigInt x;
        char ch;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
        sinp.clear();
        sinp >> ch;
        REQUIRE(ch == 'h');
    }

    SUBCASE("incorrect input #3")
    {
        istringstream sinp("++123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("incorrect input #4")
    {
        istringstream sinp("");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(sinp.eof());
        REQUIRE(x == 0);
    }
}