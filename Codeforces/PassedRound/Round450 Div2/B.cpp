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
    int a, b, k;
    int t;
    cin >> a >> b >> k;
    t = 0;
    while (++t && t <= b)
    {
        if ((a * 10) / b == k)
            return cout << t << endl, 0;
        a = (10 * a) % b;
    }
    cout << -1 << endl;
    return 0;
}