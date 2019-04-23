#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Line
{
    ll a, b;

    // a*x+b
    ll eval(ll x) { return a * x + b; };
};

// assume line's slope is sorted
// and query is also sorted
// otherwise, use Li Chao tree
struct CHT
{
    // x is in increasing order
    // while slope is in decreasing order
    deque<Line> que;
    int sz = 0;

    void add(Line l)
    {
        while (sz >= 2)
        {
            Line x = que[sz - 1], y = que[sz - 2];

            if ((l.b - x.b) * (y.a - x.a) >= (x.a - l.a) * (x.b - y.b))
                break;

            que.pop_back();
            sz--;
        }

        que.push_back(l);
        sz++;
    }

    ll query(ll x)
    {
        while (sz >= 2)
        {
            if (que[0].eval(x) <= que[1].eval(x))
                break;
            que.pop_front();
            sz--;
        }

        return que[0].eval(x);
    }
} cht;

// For a fully featured dynamic CHT
// See: https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h