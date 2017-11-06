#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll square(ll a) { return a * a; }

inline ll cube(ll a) { return a * a * a; };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll ps, cs, l, r;
    while (cin >> l >> r)
    {
        if (l > r)
            swap(l, r);
        ps = cs = 0;
        for (; l <= r; l++)
        {
            if (l % 2)
                cs += cube(l);
            else
                ps += square(l);
        }
        cout << ps << " " << cs << endl;
    }

    return 0;
}