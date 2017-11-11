#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cmp(int a, int b)
{
    return a <= b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, z, w;
    int tmp, size = 0;
    cin >> n >> z >> w;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    int s = v.size();
    if (s == 1)
        cout << abs(v[0] - w) << endl;
    else
        cout << max(abs(v[s - 1] - w), abs(v[s - 1] - v[s - 2])) << endl;

    return 0;
}