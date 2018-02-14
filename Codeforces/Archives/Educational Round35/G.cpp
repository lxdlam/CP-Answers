#include <bits/stdc++.h>

#define FOR(_i, _s, _e) for (int _i = _s; _i < _e; _i++)
#define FORE(_c) for (auto i : _c)
#define FORER(_c) for (auto &i : _c)
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : v)            \
        cin >> i;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    VIS(unsigned char, v, n);
    int q, l, r;
    unsigned char x, y;
    cin >> q;
    while (q--)
    {
        cin >> l >> r >> x >> y;
        for (l--; l < r; l++)
            v[l] = v[l] == x ? y : v[l];
    }

    for (auto i : v)
        cout << i << " ";

    cout << endl;

    return 0;
}