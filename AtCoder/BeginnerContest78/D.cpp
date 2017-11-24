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
    int n, z, w;

    cin >> n >> z >> w;
    vi v(n);

    for (auto &i : v)
        cin >> i;

    if (n == 1)
        cout << abs(z - v[0]) << endl;
    else
        cout << max(abs(v[n - 1] - v[n - 2]), abs(v.back() - w)) << endl;

    return 0;
}