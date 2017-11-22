#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

long long fp(long long base, long long expr, long long mod = 1e9 + 7)
{
    long long ans = 1;
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

    ll n, m, k;

    cin >> n >> m >> k;

    if ((n + m) & 1LL && k == -1)
        cout << 0 << endl;
    else
        cout << fp(fp(2LL, n - 1), m - 1) << endl;

    return 0;
}