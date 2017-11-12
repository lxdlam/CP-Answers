#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    int res = 0;
    vector<pii> v;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> l >> r;
        v.push_back(make_pair(l, r));
    }

    for (auto i : v)
    {
        for (auto j : v)
        {
            if (j.first < i.first && j.second > i.second) // if j in i, we just count it once
            {
                res++;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}