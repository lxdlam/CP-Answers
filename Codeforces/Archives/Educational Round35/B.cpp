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
    int n, a, b;
    cin >> n >> a >> b;
    int res = 1;
    for (int i = 1; i <= min(a, b); i++)
        if (a / i + b / i >= n)
            res = i;
    cout << res << endl;
    return 0;
}