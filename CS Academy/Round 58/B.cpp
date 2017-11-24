#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

bool comp(const pii &a, const pii &b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pii> v(n);
    ll res = 0;
    for (auto &i : v)
        cin >> i.first >> i.second;

    sort(v.begin(), v.end(), comp);

    for (int i = n / 2; i > 0; i--)
    {
        res += v[i].first - v[i - 1].second;
        v[i - 1].first += v[i].first - v[i - 1].second;
        v[i - 1].second = v[i].first;
    }

    for (int i = n / 2; i < n - 1; i++)
    {
        res += v[i + 1].first - v[i].second;
        v[i + 1].second -= v[i + 1].first - v[i].second;
        v[i + 1].first = v[i].second;
    }

    cout << res << endl;

    return 0;
}