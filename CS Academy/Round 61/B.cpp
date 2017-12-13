#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int ham(const vi &a, const vi &b)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] ^ b[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v(2 * n), r1(2 * n), r2(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        if (i & 1)
            r1[i] = 1;
        else
            r2[i] = 1;
    }
    int res = min(ham(v, r1), ham(v, r2)) / 2;

    cout << res << endl;

    return 0;
}