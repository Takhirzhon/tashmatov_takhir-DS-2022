#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>

using namespace std;

TEST_CASE("back()")
{
    vector<int> v = {1, 2, 3, 4};

    REQUIRE(v.back() == 4);

    v.back() = 20;

    REQUIRE(v[3] == 20);
}

TEST_CASE("front()")
{
    vector<int> v = {1, 2, 3, 4};

    REQUIRE(v.front() == 1);

    v.front() = 10;

    REQUIRE(v[0] == 10);
}

TEST_CASE("subscript")
{
    vector<int> v = {44, 53, 67, 24};
    vector<int> v2 = v;

    REQUIRE(v2.size() == 4);
    v[0] = 35;
    v2[0] = 61;
}

TEST_CASE("at")
{
    vector<int> v = {1, 2, 3, 4};
    REQUIRE_THROWS_AS(v.at(4), out_of_range);
}