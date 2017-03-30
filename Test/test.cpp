#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>

using namespace std;

int mod(int n, int m)
{
    return (n + m) % m;
}

bool check(string a, string b)
{
    bool res = true;
    for (int i = 0; i < a.size(); i++)
        if (mod(a[i] - a[i + 1], 27) != mod(b[i] - b[i + 1], 27))
            res = false;
    return res;
}

TEST_CASE("Check")
{
    REQUIRE(check("bcde", "zabc") == true);
}