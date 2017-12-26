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

    int a, b, c, d;
    int res = 0;
    cin >> a >> b >> c >> d;

    if (a <= c && d <= b)
        cout << d - c << endl;
    else if (c <= a && b <= d)
        cout << b - a << endl;
    else if (a <= c && c <= b && b <= d)
        cout << b - c << endl;
    else if (c <= a && a <= d && d <= b)
        cout << d - a << endl;
    else
        cout << 0 << endl;

    return 0;
}