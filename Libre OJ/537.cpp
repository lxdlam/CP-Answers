#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;
    cin >> s >> k;
    int res = 0;

    unordered_map<string, int> m;

    for (int i = 0; i < s.size(); i++)
        m[s.substr(i, k)]++;

    for (auto i : m)
        res = max(res, i.second);

    cout << res << endl;

    return 0;
}