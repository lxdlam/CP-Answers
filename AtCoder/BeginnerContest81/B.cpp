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
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    int res = 0;
    for (;;)
    {
        for (auto &i : v)
        {
            if (i & 1)
                return cout << res << endl, 0;
            i >>= 1;
        }
        res++;
    }
}