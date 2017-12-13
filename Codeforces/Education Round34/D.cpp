// Accepted Algorithm
// But Big Integer needed
// Partial Solution
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
    int t;
    int res = 0;
    cin >> n;
    map<int, int> m;
    vi v(n), k;
    for (auto &i : v)
    {
        cin >> i;
        m[i]++;
    }
    k = v;
    for (int i = n - 1; i > 0; i--)
        k[i - 1] = k[i] + k[i - 1];
    for (int i = 0; i < n - 1; i++)
    {
        res += -(n - i - 1) * v[i] + k[i + 1];
        m[v[i]]--;
        if (m[v[i] + 1])
            res += m[v[i] + 1];
        if (m[v[i] - 1])
            res -= m[v[i] - 1];
    }
    cout << res << endl;
    return 0;
}