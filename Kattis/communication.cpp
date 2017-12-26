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
    int t;
    map<int, int> m;
    for (int i = 0; i <= 255; i++)
        m[i ^ ((i << 1) & 255)] = i;

    cin >> n;
    while (n--)
    {
        cin >> t;
        cout << m[t] << " ";
    }

    return 0;
}