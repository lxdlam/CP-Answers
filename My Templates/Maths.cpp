#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e6 + 10;

// Factorials
long long n[SIZE] = {1};

void getFac()
{
    for (int i = 1; i < SIZE; i++)
        n[i] = n[i - 1] * i;
}

// Combinations
long long c[SIZE][SIZE] = {0};

void getCom()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        // Will be extremely large!
    }
}

// GCD for small integers
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Prime check
bool notprime[SIZE] = {false};

void init()
{
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < SIZE; i++)
        if (!notprime[i])
        {
            if (i > SIZE / i)
                continue;
            for (int j = i * i; j < SIZE; j += i)
                notprime[j] = true;
        }
}

// Primes Table
int prime[SIZE + 1] = {0};
void getPrime()
{
    for (int i = 2; i <= SIZE; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= SIZE / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

// Factors
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatCnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}

// Extend GCD
long long extend_gcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// Inverse element
long long mod_reverse(long long a, long long n)
{
    long long x, y;
    long long d = extend_gcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}

// Fast pow
long long fp(long long base, long long expr, long long mod = 1e9 + 7)
{
    long long ans = 1;
    base %= mod;
    while (expr)
    {
        if (expr & 1)
            ans = (ans * base) % mod;
        base *= base % mod;
        expr >>= 1;
    }
    return ans;
}