#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <ctime>
#include <iterator>

using namespace std;
typedef long long ll;

// Recursive version
const int SIZE = 1e5 + 10;

ll flag[SIZE << 2], sum[SIZE << 2];
ll num[SIZE];

void pushup(int pos)
{
    sum[pos] = sum[pos << 1] + sum[pos << 1 | 1];
}

void pushdown(int pos, int lcnt, int rcnt)
{
    if (flag[pos])
    {
        flag[pos << 1] += flag[pos];
        flag[pos << 1 | 1] += flag[pos];
        sum[pos << 1] += flag[pos] * lcnt;
        sum[pos << 1 | 1] += flag[pos] * rcnt;
        flag[pos] = 0;
    }
}

void build(int l, int r, int cur)
{
    if (l == r)
    {
        sum[cur] = num[l];
        return;
    }

    int m = ((r - l) >> 1) + l;
    build(l, m, cur << 1);
    build(m + 1, r, cur << 1 | 1);
    pushup(cur);
}

void update(int pos, ll val, int l, int r, int cur)
{
    if (l == r)
    {
        sum[cur] += val;
        return;
    }

    int m = ((r - l) >> 1) + l;

    // if mixed
    // pushdown(cur, m - l + 1, r - m);

    if (pos <= m)
        update(pos, val, l, m, cur << 1);
    else
        update(pos, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
}

void update(int ul, int ur, ll val, int l, int r, int cur)
{
    if (ul <= l && r <= ur)
    {
        sum[cur] += val * (r - l + 1);
        flag[cur] += val;
        return;
    }

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);

    if (ul <= m)
        update(ul, ur, val, l, m, cur << 1);
    if (ur > m)
        update(ul, ur, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
}

ll query(int ql, int qr, int l, int r, int cur)
{
    if (ql <= l && r <= qr)
        return sum[cur];

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);

    ll ans = 0;
    if (ql <= m)
        ans += query(ql, qr, l, m, cur << 1);
    if (qr > m)
        ans += query(ql, qr, m + 1, r, cur << 1 | 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    string op;
    ll t, l, r, a;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    build(1, n, 1);

    while (q--)
    {
        cin >> op;
        if (op == "Q")
        {
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << endl;
        }
        else
        {
            cin >> l >> r >> a;
            update(l, r, a, 1, n, 1);
        }
    }
}