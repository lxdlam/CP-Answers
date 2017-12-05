#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

ll Palind[1000000], pnum = 1;

void init()
{
    ll n, m, k, p, q, r;
    for (n = 1; n <= 9; n++)
        Palind[pnum++] = 11 * n;
    for (n = 1; n <= 9; n++)
        for (m = 0; m <= 9; m++)
            Palind[pnum++] = 1001 * n + 110 * m;
    for (n = 1; n <= 9; n++)
        for (m = 0; m <= 9; m++)
            for (k = 0; k <= 9; k++)
                Palind[pnum++] = 100001 * n + 10010 * m + 1100 * k;
    for (n = 1; n <= 9; n++)
        for (m = 0; m <= 9; m++)
            for (k = 0; k <= 9; k++)
                for (p = 0; p <= 9; p++)
                    Palind[pnum++] = 10000001 * n + 1000010 * m + 100100 * k + 11000 * p;
    for (n = 1; n <= 9; n++)
        for (m = 0; m <= 9; m++)
            for (k = 0; k <= 9; k++)
                for (p = 0; p <= 9; p++)
                    for (r = 0; r <= 9; r++)
                        Palind[pnum++] = 1000000001 * n + 100000010 * m + 10000100 * k + 1001000 * p + 110000 * r;
    Palind[pnum++] = 100000000001ll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    ll k, p;
    ll res = 0;
    cin >> k >> p;
    for (ll i = 1; i <= k; i++)
    {
        res += Palind[i] % p;
        res %= p;
    }

    cout << res % p << endl;

    return 0;
}