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
    int T;
    int t;
    int res = 0;
    while (cin >> T && T)
    {
        res = 0;
        while (T--)
        {
            cin >> t;
            while (t)
            {
                res += 1;
                if (t >= 100)
                    t -= 100;
                else if (t >= 50)
                    t -= 50;
                else if (t >= 20)
                    t -= 20;
                else if (t >= 10)
                    t -= 10;
                else if (t >= 5)
                    t -= 5;
                else if (t >= 1)
                    t -= 1;
            }
        }
        cout << res << endl;
    }

    return 0;
}