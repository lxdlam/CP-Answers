#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>

using namespace std;

string reverse(string src)
{
    string res = "";
    for (int i = src.size() - 1; i >= 0; i--)
        res += src[i];
    return res;
}

TEST_CASE("reverse")
{
    REQUIRE(reverse("") == "");
    REQUIRE(reverse("A") == "A");
    REQUIRE(reverse("123456789") == "987654321");
}