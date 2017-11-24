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
    int n, k;
    int res = 0;
    bool flag;
    cin >> n >> k;
    vi v(n);
    for (auto &i : v)
        cin >> i;

    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (abs(v[i] - v[j]) <= k)
                flag = false;
        }
        if (flag)
            res++;
    }

    cout << res << endl;

    return 0;
}