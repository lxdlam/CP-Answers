#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

vector<pll> pp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b, c, d, start, len;
    ll p, q;
    ll x, y, z;
    int l;

    cin >> n >> a >> b >> c >> d >> start >> len;

    for (int i = 0; i < n; i++)
    {
        cin >> p >> q;
        pp.emplace_back(make_pair(p, q));
    }

    // First: check if can be done at zero
    l = 0, x = y = z = start;
    while (l < n && pp[l].first < len)
    {
        if (pp[l].second == 1)
            x += c;
        else
            x -= d;
        y = min(x, y);
        l++;
    }
    if (y >= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // TODO:
    // Solve it

    cout << -1 << endl; // no solution
    return 0;
}