#include <iostream>
#include <string>

using namespace std;

long long toBase(long long, long long);
bool isPali(string);
long long reverse(long long);

int main()
{
}

long long toBase(long long a, long long b)
{
    return 0;
}

bool isPail(string src)
{
    string dest = "";
    for (int i = src.size() - 1; i >= 0; i--)
        dest += src[i];
    return src == dest;
}

long long reverse(long long num)
{
    long long res = 0;
    while (num)
    {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}