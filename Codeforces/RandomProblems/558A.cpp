#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

template <class T, class U>
inline auto mp(T t, U u) { return make_pair(t, u); }

bool cmp(const pii &a, const pii &b)
{
    return a.first < b.first;
}

bool cmpp(const pii &a, const pii &b)
{
    return b.first < a.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int t, a;
    vector<pii> l, r;
    cin >> n;
    while (n--)
    {
        cin >> t >> a;
        if (t <= 0)
            l.emplace_back(mp(t, a));
        else
            r.emplace_back(mp(t, a));
    }
    sort(l.begin(), l.end(), cmpp);
    sort(r.begin(), r.end(), cmp);
    int mx = min(l.size(), r.size());
    bool lb = l.size() > r.size();
    int res = 0;
    for (int i = 0; i < mx; i++)
        res += l[i].second + r[i].second;
    if (l.size() != r.size())
    {
        if (lb)
            res += l[mx].second;
        else
            res += r[mx].second;
    }
    cout << res << endl;
    return 0;
}