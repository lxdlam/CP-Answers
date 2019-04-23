#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int SIZE = 1e6 + 10;

struct Line
{
    ll a, h;

    // how the line evaluates
    // for example, it's a*x+b;
    ll eval(ll x) { return a * x + b; };
};

// Based on https://cp-algorithms.com/geometry/convex_hull_trick.html
struct LiChaoTree
{
    // here, size is the maximum point coordinate
    // i.e., maximum possible x
    Line tr[SIZE << 2];

    // fill with the starting line
    void init(Line l) { fill(tr, tr + (SIZE << 2), l); }

    // in below functions
    // the initial call must using
    // the maximum possible x
    // as argument r
    // NOT THE SIZE OF THE TREE!

    void add(Line li, int l, int r, int cur)
    {
        int m = (l + r) >> 1;

        // change the behavior here to maintain maximum or minimum
        bool le = li.eval(l) > tr[cur].eval(l);
        bool mid = li.eval(m) > tr[cur].eval(m);

        if (mid)
            swap(tr[cur], li);
        if (l == r)
            return;
        else if (le != mid)
            add(li, l, m, cur << 1);
        else
            add(li, m + 1, r, cur << 1 | 1);
    }

    ll query(int pos, int l, int r, int cur)
    {
        if (l == r)
            return tr[cur].eval(pos);

        int m = (l + r) >> 1;

        // change the behavior here to query maximum or minimum
        if (pos < m)
            return max(tr[cur].eval(pos), query(pos, l, m, cur << 1));
        else
            return max(tr[cur].eval(pos), query(pos, m + 1, r, cur << 1 | 1));
    }
} LCT;