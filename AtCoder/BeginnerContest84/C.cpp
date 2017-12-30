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
    ll cur = 0;
    cin >> n;
    vi c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> c[i] >> s[i] >> f[i];
    for (int i = 0; i <= n - 1; i++)
    {
        int st = i;
        cur = 0;
        while (st < n - 1)
        {
            if (cur >= s[st] && cur % f[st] == 0)
                cur += c[st];
            else if (cur >= s[st])
            {
                while (cur % f[st])
                    cur++;
                cur += c[st];
            }
            else
                cur = s[st] + c[st];

            st++;
        }

        cout << cur << endl;
    }

    //cout << 0 << endl;

    return 0;
}