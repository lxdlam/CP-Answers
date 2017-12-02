#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, k;
    cin >> n >> x >> k;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    return 0;
}