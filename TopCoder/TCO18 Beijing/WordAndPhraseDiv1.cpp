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

class WordAndPhraseDiv1
{
  private:
    // Constants
    static const int SIZE = 1010;
    static const int MOD = 1e9 + 7;
    // Useful Inner Method
    ll mul(ll a, ll b) { return a * b % MOD; }

    // Solver
    inline int solve()
    {

        return 0;
    }

  public:
    int findNumberOfPhrases(string w)
    {
        vll v(SIZE);
        v[0] = 1;
        v[1] = 2;
        for (int i = 2; i < SIZE; i++)
            v[i] = (v[i - 1] + v[i - 2]) % MOD;

        int idx = 0;
        int len = w.size();
        ll ans = 1;
        while (idx < len)
        {
            if (w[idx] == '_')
            {
                if (idx > 0 && idx < len)
                {
                    int s = idx;
                    while (w[idx] == '_')
                        idx++;
                    if (isdigit(w[idx]) || idx == len)
                        ans = mul(ans, v[idx - s - 1]);
                    else
                        ans = mul(ans, v[idx - s]);
                }
            }
            idx++;
        }

        return static_cast<int>(ans);
    }
};