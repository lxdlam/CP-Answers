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
    int T;
    cin >> T;
    int x, y, l, r;
    l = r = 0;
    while (T--)
    {
        cin >> x >> y;
        if (x < 0)
            l++;
        if (x > 0)
            r++;
    }
    if (l <= 1 || r <= 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}