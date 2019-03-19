#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &i : v)
    {
        int x;
        cin >> x >> i;
    }

    sort(v.begin(), v.end());

    long long ans = 0;

    for (int i = 0; i < n / 2; i++)
        ans += v[n - i - 1] - v[i];

    cout << ans << '\n';

    return 0;
}