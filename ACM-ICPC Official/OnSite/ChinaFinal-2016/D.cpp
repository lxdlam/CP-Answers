#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v, t;
int T, n, m;

bool check(int k)
{
    t.clear();
    t.resize(m * k);
    for (int i = 0; i < k; i++)
        t[i] = v[i];
    int pos = k;
    for (int i = k; i < m * k; i++)
    {
        while (v[pos] < t[i - k] * 2 && pos < n)
            pos++;
        if (pos == n)
            return false;
        t[i] = v[pos];
        pos++;
    }
    return true;
}

int bs(int s, int e)
{
    int mid;
    while (s < e)
    {
        mid = (s + e + 1) >> 1;
        if (check(mid))
            s = mid;
        else
            e = mid - 1;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        v.clear();
        t.clear();
        cin >> n >> m;
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        cout << bs(0, n / m) << endl;
    }
    return 0;
}