#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e6 + 10;
typedef long long ll;

// Factorials
ll n[SIZE] = {1};

void getFac()
{
    for (int i = 1; i < SIZE; i++)
        n[i] = n[i - 1] * i;
}

// Combinations
ll c[SIZE][SIZE] = {0};

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

// Derangement Problem
ll d[SIZE];

void getD()
{
    ll res;
    d[1] = 0, d[2] = 1;
    for (int i = 3; i < SIZE; i++)
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
}

// GCD for small integers
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Stein GCD
ll sgcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a % 2 == 0 && b % 2 == 0)
        return 2 * sgcd(a >> 1, b >> 1);
    else if (a % 2 == 0)
        return sgcd(a >> 1, b);
    else if (b % 2 == 0)
        return sgcd(a, b >> 1);
    else
        return sgcd(abs(a - b), min(a, b));
}

// LCM
ll lcm(ll a, ll b)
{
    return a / sgcd(a, b) * b;
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
ll factor[100][2];
int fatCnt;
int getFactors(ll x)
{
    fatCnt = 0;
    ll tmp = x;
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
ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// Inverse element
ll mod_reverse(ll a, ll n)
{
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}

// Solve a*x + b*y = n
ll cal(ll a, ll b, ll n)
{
    ll x, y;
    ll gcd = extend_gcd(a, b, x, y);
    if (n % gcd != 0)
        return -1;
    x *= n / gcd;
    b /= gcd;
    if (b < 0)
        b = -b;
    ll ans = x % b;
    if (ans <= 0)
        ans += b;
    return ans;
    // answer:
    // x = ans, y = (n - ans * a) / b
}

// Fast pow
ll fp(ll base, ll expr, ll mod = 1e9 + 7)
{
    ll ans = 1;
    base %= mod;
    while (expr)
    {
        if (expr & 1LL)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        expr >>= 1LL;
    }
    return ans % mod;
}