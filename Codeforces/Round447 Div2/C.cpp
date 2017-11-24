#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int sgcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a % 2 == 0 && b % 2 == 0)
        return 2 * sgcd(a >> 1, b >> 1);
    else if (a % 2 == 0)
        return sgcd(a >> 1, b);
    else if (b % 2 == 0)
        return sgcd(a, b >> 1);
    else
        return sgcd(abs(a - b), min(a, b));
}

int lcm(int a, int b)
{
    return a * b / sgcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    bool found = true;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;

    int t = v[0];

    for (int i = 1; i < n; i++)
        t = sgcd(t, v[i]);

    if (t != v[0])
        cout << -1 << endl;
    else
    {
        cout << 2 * n - 1 << endl;
        for (int i = 0; i < n - 1; i++)
            cout << v[i] << " " << v[0] << " ";
        cout << v.back() << endl;
    }

    return 0;
}