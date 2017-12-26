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
    ll T, n, t;
    ll sum, mxx;
    cin >> T;
    while (T--)
    {
        mxx = sum = 0;
        cin >> n;
        while (n--)
        {
            cin >> t;
            sum += t;
            mxx = max(mxx, t);
        }
        if (2 * mxx - sum > 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}