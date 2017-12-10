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
    string t;
    cin >> t;
    int res = 0;
    for (auto i : t)
        if (i == '1')
            res++;
    cout << res << endl;
    return 0;
}