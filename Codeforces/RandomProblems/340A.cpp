#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

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

ll lcm(ll a, ll b)
{
    return a / sgcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll l = lcm(x, y);
    cout << b / l - (a - 1) / l << endl;

    return 0;
}