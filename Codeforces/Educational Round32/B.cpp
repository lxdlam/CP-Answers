#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, r, d, u;
    int n;
    string t;
    cin >> n >> t;
    l = r = d = u = 0;
    for (auto i : t)
    {
        if (i == 'L')
            l++;
        if (i == 'R')
            r++;
        if (i == 'D')
            d++;
        if (i == 'U')
            u++;
    }
    cout << min(l, r) * 2 + min(d, u) * 2 << endl;
    return 0;
}