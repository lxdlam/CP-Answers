#define CATCH_CONFIG_MAIN
#include "catch.hpp"

string reverse(string src)
{
    string res = "";
    for (auto it = src.begin(); it != src.end(); it++)
        res += *it;
    return res;
}