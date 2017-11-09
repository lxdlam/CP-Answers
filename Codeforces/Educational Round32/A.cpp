#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int res = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    for (int i = 1; i < v.size() - 1; i++)
    {
        if (v[i - 1] > v[i] && v[i + 1] > v[i])
            res++;
        if (v[i - 1] < v[i] && v[i + 1] < v[i])
            res++;
    }

    cout << res << endl;
    return 0;
}