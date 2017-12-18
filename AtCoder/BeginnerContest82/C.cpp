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
    map<int, int> m;
    int res = 0;
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        m[t]++;
    }
    for (auto i : m)
    {
        if (i.first == i.second)
            continue;
        else if (i.first < i.second)
            res += i.second - i.first;
        else
            res += i.second;
    }
    cout << res << endl;
    return 0;
}