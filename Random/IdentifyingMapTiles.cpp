// Source: http://codeforces.com/gym/101485

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string t;
    cin >> t;
    ll x = 0, y = 0;
    for (auto i : t)
    {
        x *= 2, y *= 2;
        if (i == '1')
            y += 1;
        else if (i == '2')
            x += 1;
        else if (i == '3')
            x += 1, y += 1;
    }
    cout << t.size() << " " << y << " " << x << endl;

    return 0;
}