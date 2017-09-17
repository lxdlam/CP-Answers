#define CATCH_CONFIG_MAIN

#include <catch>

long long nCr(int m, int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= m - i;
        res /= i + 1;
    }
    return res;
}

TEST_CASE("nCr", "[nCr]")
{
    REQUIRE(nCr(5, 0) == 1);
    REQUIRE(nCr(0, 0) == 1);
    REQUIRE(nCr(4, 2) == 6);
}