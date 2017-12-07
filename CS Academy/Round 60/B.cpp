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
    int n, e1, e2;
    cin >> n >> e1 >> e2;
    vector<pii> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;

    vector<pii> tt = v;

    int res = 0;
    int tmp = 0;
    int r1 = 0, r2 = 0;

    for (int t1 = n; t1 >= 1; t1--)
        if (v[t1].first <= e1 && v[t1].second >= 1 && v[t1].first >= v[t1].second)
            tmp++, v[t1] = make_pair(1e9, 1e9);
    r1 = max(tmp, r1);

    tmp = 0;
    for (int t2 = n; t2 >= 1; t2--)
        if (v[t2].first <= e2 && v[t2].second >= 1 && v[t2].first >= v[t2].second)
            tmp++;
    r2 = max(tmp, r2);

    res = max(res, r1 + r2);

    v = tt;
    tmp = 0;
    r1 = r2 = 0;
    for (int t1 = 0; t1 <= n; t1++)
        if (v[t1].first >= e1 && v[t1].second <= n && v[t1].first <= v[t1].second)
            tmp++, v[t1] = make_pair(1e9, 1e9);
    r1 = max(r1, tmp);

    tmp = 0;
    for (int t2 = 0; t2 <= n; t2++)
        if (v[t2].first >= e2 && v[t2].second <= n && v[t2].first <= v[t2].second)
            tmp++;
    r2 = max(r2, tmp);

    res = max(res, r1 + r2);

    v = tt;
    tmp = 0;
    r1 = r2 = 0;
    for (int t1 = n; t1 >= 1; t1--)
        if (v[t1].first <= e1 && v[t1].second >= 1 && v[t1].first >= v[t1].second)
            tmp++, v[t1] = make_pair(1e9, 1e9);
    r1 = max(tmp, r1);

    tmp = 0;
    for (int t2 = 0; t2 <= n; t2++)
        if (v[t2].first >= e2 && v[t2].second <= n && v[t2].first <= v[t2].second)
            tmp++;
    r2 = max(r2, tmp);

    res = max(r1 + r2, res);

    v = tt;
    tmp = 0;
    r1 = r2 = 0;
    for (int t2 = n; t2 >= 1; t2--)
        if (v[t2].first <= e2 && v[t2].second >= 1 && v[t2].first >= v[t2].second)
            tmp++;
    r2 = max(tmp, r2);

    tmp = 0;
    for (int t1 = 0; t1 <= n; t1++)
        if (v[t1].first >= e1 && v[t1].second <= n && v[t1].first <= v[t1].second)
            tmp++, v[t1] = make_pair(1e9, 1e9);
    r1 = max(r1, tmp);

    res = max(r1 + r2, res);

    cout << res << endl;

    return 0;
}