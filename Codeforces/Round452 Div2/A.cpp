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

    int a[3] = {0};
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        a[t]++;
    }

    int res = min(a[1], a[2]);
    a[1] -= a[2];
    if (a[1] <= 0)
        a[1] = 0;
    res += a[1] / 3;
    cout << res << endl;

    return 0;
}