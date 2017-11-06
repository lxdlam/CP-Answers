#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t, res;
    while (cin >> n)
    {
        res = 1;
        while (n--)
        {
            cin >> t;
            if (t % 2)
                res *= t;
        }
        cout << res << endl;
    }
    return 0;
}