#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Leaf
{
    int x, y, s;
    Leaf() : x(0), y(0), s(0) {}
    Leaf(int _x, int _y, int _s) : x(_x), y(_y), s(_s) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, c, n;
    int x, y, s;
    int res = 0;
    cin >> t >> c >> n;
    vector<Leaf> v(n);
    for (auto &i : v)
    {
        cin >> x >> y >> s;
        i = Leaf(x, y, s);
    }

    for (int i = 0; i < t; i++)
    {
        res = 0;
        for (auto l : v)
        {
            if ((ll)(l.s * l.x + c * l.s * i) == (ll)(l.y * c))
                res++;
        }
        cout << res << endl;
    }

    return 0;
}