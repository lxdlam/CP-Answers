#include <bits/stdc++.h>

#define FOR(_i, _s, _e) for (int _i = _s; _i < _e; _i++)
#define FORE(_c) for (auto i : _c)
#define FORER(_c) for (auto &i : _c)
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : v)            \
        cin >> i;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> m >> n;
    if (m > 26)
        cout << n << endl;
    else
        cout << n % fp(2, m) << endl;

    return 0;
}