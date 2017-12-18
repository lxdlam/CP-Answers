#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 1e5;

long long fp(long long base, long long expr, long long mod)
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

    ll a, n, p;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> a >> n >> p;
        cout << "Case #" << i << ": ";
        a %= p;
        for (ll j = 1; j <= n; j++)
            a = fp(a, j, p);
        cout << a << endl;
    }

    return 0;
}