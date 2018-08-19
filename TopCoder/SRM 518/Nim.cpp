#include <bits/stdc++.h>

using namespace std;

#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)

template <typename T>
bool smax(T &a, const T &b)
{
    if (a > b)
        return false;
    a = b;
    return true;
}

template <typename T>
bool smin(T &a, const T &b)
{
    if (a < b)
        return false;
    a = b;
    return true;
}

template <typename T>
T cd(T a, T b)
{
    return (a + b - 1) / b;
}

template <typename T>
bool se(T &a, T &b)
{
    if (a < b)
        return false;
    swap(a, b);
    return true;
}

const int INF = 0x3f3f3f3f;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;

class Nim
{
  private:
    // Constants
    static const int SIZE = 5e4 + 10;
    static const int P = 65536;
    static const int MOD = 1e9 + 7;
    int prime[SIZE + 1] = {0};

    // Useful Inner Method
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

    void fwt_xor(int n, vll &x, bool fwt = true)
    {
        ll inv2 = fp(2, MOD - 2, MOD);
        for (int i = 2; i <= n; i <<= 1)
            for (int p = i >> 1, j = 0; j < n; j += i)
                for (int k = j; k < j + p; ++k)
                {
                    int a = x[k], b = x[k + p];
                    x[k] = (a + b) % MOD;
                    x[k + p] = (a - b + MOD) % MOD;
                    if (!fwt)
                        x[k] = 1LL * x[k] * inv2 % MOD, x[k + p] = 1LL * x[k + p] * inv2 % MOD;
                }
    }

    // Solver
    inline int solve(int L, int K)
    {
        vll f(P);
        for (int i = 1; i <= prime[0] && prime[i] <= K; i++)
            f[prime[i]] = 1;

        fwt_xor(P, f);
        FOR(i, 0, P)
        f[i] = fp(f[i], L);

        fwt_xor(P, f, false);

        return f[0] % MOD;
    }

  public:
    int count(int K, int L)
    {
        // Build
        getPrime();

        return solve(K, L);
        // return 0;
    }
};