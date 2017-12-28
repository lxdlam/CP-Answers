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
    int n;
    cin >> n;
    if (n & 1)
    {
        for (ll i = 1; i <= 3500; i++)
            for (ll j = 1; j <= 3500; j++)
            {
                ll a = (n * i * j);
                ll b = (5 * i * j - n * j - n * i);
                if (b > 0 && a % b == 0)
                    return cout << i << " " << j << " " << a / b << endl, 0;
            }
    }
    else
        cout << n << " " << n << " " << n / 2 << endl;
    return 0;
}