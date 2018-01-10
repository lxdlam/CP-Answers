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
    int res = 0;
    map<int, int> m;
    int t;
    while (n--)
    {
        cin >> t;
        m[t]++;
    }

    for (auto i : m)
        res = max(res, i.second);

    cout << res << endl;

    return 0;
}