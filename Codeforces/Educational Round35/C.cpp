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
    vi v(3);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    if (v[0] == 1)
        cout << "YES" << endl;
    else if (v[0] == 2 && v[1] == 2)
        cout << "YES" << endl;
    else if (v[0] == 2 && v[1] == 4 && v[2] == 4)
        cout << "YES" << endl;
    else if (v[0] == v[1] && v[1] == v[2] && v[0] == 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}