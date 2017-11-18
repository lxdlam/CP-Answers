#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    ll tmp = 0;
    cin >> n;

    vector<ll> cans(n);
    while (n--)
    {
        cin >> t;
        tmp += t;
    }

    for (auto &i : cans)
        cin >> i;

    sort(cans.begin(), cans.end(), greater<ll>());

    if (cans[0] + cans[1] >= tmp)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}