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
    cin >> n;
    while (n--)
    {
        cin >> t;
        if (t % 4 == 0)
            m[4]++;
        else if (t & 1)
            m[1]++;
        else
            m[2]++;
    }
    if (m[1] <= m[4] || (m[1] <= m[4] + 1 && !m[2]))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}