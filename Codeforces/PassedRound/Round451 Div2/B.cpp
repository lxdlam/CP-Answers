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

    ll n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; a * i <= n; i++)
    {
        if ((n - a * i) % b == 0)
        {
            cout << "YES" << endl;
            return cout << i << " " << (n - a * i) / b << endl, 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}