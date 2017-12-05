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

    int n, m, k;
    cin >> n >> m >> k;
    vi v(n + 1);
    v.emplace_back(0);
    int pos = n - m > m ? n : 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++)
        if (abs(i - m) < abs(pos - m) && v[i] <= k && v[i] != 0)
            pos = i;

    cout << abs(pos - m) * 10 << endl;

    return 0;
}