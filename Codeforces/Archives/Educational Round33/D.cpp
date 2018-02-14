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

    int n, d;
    cin >> n >> d;
    int lower = 0, upper = 0, ans = 0, x;
    while (n--)
    {
        cin >> x;
        if (x)
        {
            // change the possible section
            lower += x, upper += x;
            // any deposit will make it exceed the limit
            if (lower > d)
            {
                ans = -1;
                break;
            }
            // upper bound can be maximized to d
            upper = min(upper, d);
        }
        else
        {
            // lower bound can be minimized to 0
            if (upper >= 0)
                lower = max(lower, 0);
            else // [0..d]
                ans++, lower = 0, upper = d;
        }
    }
    cout << ans << endl;
    return 0;
}