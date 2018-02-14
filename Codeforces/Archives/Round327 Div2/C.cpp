#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int change(vector<int> &v, int l, int r)
{
    if (l == r)
        return 0;
    else if (v[l] == v[r])
    {
        for (int i = l + 1; i < r; i++)
            v[i] = v[r];
        return (r - l) / 2;
    }
    else
    {
        int m = (l + r + 1) / 2;
        for (int i = l + 1; i < m; i++)
            v[i] = v[l];
        for (int i = m; i < r; i++)
            v[i] = v[r];
        return (r - l - 1) / 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, t, l = 0;
    int ans = 0;
    vector<int> v;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> t;
        v.emplace_back(t);
    }
    for (int i = 0; i < T; i++)
    {
        if (i == T - 1 || v[i] == v[i + 1])
        {
            ans = max(ans, change(v, l, i));
            l = i + 1;
        }
    }
    cout << ans << "\n";
    for (auto i : v)
        cout << i << " ";
    return 0;
}