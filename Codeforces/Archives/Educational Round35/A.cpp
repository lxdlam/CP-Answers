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
    int n;
    cin >> n;
    vi v(n);
    vi occ;
    int cnt = 0;
    int minn = 1e9 + 10;
    int d = n + 1;
    for (auto &i : v)
    {
        cin >> i;
        minn = min(i, minn);
    }

    for (int i = 0; i < n; i++)
        if (v[i] == minn)
            occ.emplace_back(i);

    for (int i = 1; i < occ.size(); i++)
        d = min(d, occ[i] - occ[i - 1]);

    cout << d << endl;

    return 0;
}