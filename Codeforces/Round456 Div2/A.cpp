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
    ll a, b;
    cin >> a >> b;
    ll x, y, z;
    cin >> x >> y >> z;
    a -= x * 2 + y;
    b -= z * 3 + y;
    if (a > 0)
        a = 0;
    if (b > 0)
        b = 0;
    cout << -(a + b) << endl;
    return 0;
}