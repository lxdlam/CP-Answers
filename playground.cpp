#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <set>

using namespace std;

int sameNumber(int num1, int num2)
{
    int count = 0;
    int digit1[10] = {0}, digit2[10] = {0};
    while (num1 && num2)
    {
        digit1[num1 % 10]++;
        digit2[num2 % 10]++;
        num1 /= 10;
        num2 /= 10;
    }
    for (int i = 0; i <= 9; i++)
        if (digit1[i] && digit2[i])
            count += min(digit1[i], digit2[i]);
    return count;
}

TEST_CASE("Same number works fine.", "[same]")
{
    REQUIRE(sameNumber(2225, 4815) == 2);
    REQUIRE(sameNumber(2225, 5716) == 1);
    REQUIRE(sameNumber(2225, 7842) == 1);
    REQUIRE(sameNumber(2225, 4901) == 0);
    REQUIRE(sameNumber(2225, 8585) == 3);
    REQUIRE(sameNumber(2225, 8555) == 3);
}