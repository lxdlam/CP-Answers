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

    int n;
    cin >> n;
    vi p(n), k(n);
    for (auto &i : p)
        cin >> i;

    int sa, sb;
    int res = INT_MAX;
    int i;
    for (int j = 0; j < n; j++)
    {
        sa = sb = 0;
        i = j;
        for (;; i = (i + 1) % n)
        {
            sa += p[i];
            if (sa >= 180)
                break;
        }

        i = (i + 1) % n;
        for (; sa + sb < 360; i = (i + 1) % n)
            sb += p[i];

        res = min(abs(sa - sb), res);
    }

    cout << res << endl;

    return 0;
}