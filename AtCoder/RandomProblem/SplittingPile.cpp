#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 2e5 + 10;

ll s[SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        s[i] = s[i - 1] + t;
    }
    ll res = LONG_MAX;
    for (int i = 1; i <= n - 1; i++)
        res = min(res, abs(s[n] - 2 * s[i]));

    cout << res << endl;

    return 0;
}