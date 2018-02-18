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
    int n, k;
    int res = 0;
    cin >> n >> k;
    int t;
    map<int, int> m;
    si s;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        m[t]++;
        s.insert(t);
    }
    if (s.size() <= k)
        return cout << res << endl, 0;
    vi v;
    for (auto i : m)
        v.emplace_back(i.second);
    sort(v.begin(), v.end());
    for (int i = 0; i < s.size() - k; i++)
        res += v[i];
    cout << res << endl;
    return 0;
}