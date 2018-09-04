#include <bits/stdc++.h>

using namespace std;

struct Splay
{
    static const int SIZE = 1e5 + 10;
    int rt;          // root
    int tot;         // total nodes
    int fa[SIZE];    // father of node i
    int ch[SIZE][2]; // child of node i, 0 is left
    int val[SIZE];   // value of node i
    int cnt[SIZE];   // Count of the number of val i
    int sz[SIZE];    // size of subtree of node i

    void mt(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
    }

    bool get(int x)
    {
        return x == ch[fa[x]][1];
    }

    void reset(int x)
    {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }

    void rotate(int x)
    {
        int y = fa[x], z = fa[y], chk = get(x);

        ch[y][chk] = ch[x][chk ^ 1];
        fa[ch[x][chk ^ 1]] = y;

        ch[x][chk ^ 1] = y;
        fa[y] = x;

        fa[x] = z;
        if (z)
            ch[z][y == ch[z][1]] = x;

        mt(x);
        mt(y);
    }

    void splay(int x)
    {
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f])
                rotate(get(x) == get(f) ? f : x);
        rt = x;
    }

    void insert(int k)
    {
        if (!rt)
        {
            val[++tot] = k;
            cnt[tot]++;
            rt = tot;
            mt(rt);
            return;
        }

        int cur = rt, f = 0;
        while (true)
        {
            if (val[cur] == k)
            {
                cnt[cur]++;
                mt(cur);
                mt(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = ch[cur][val[cur] < k];
            if (!cur)
            {
                val[++tot] = k;
                cnt[tot]++;
                fa[tot] = f;
                ch[f][val[f] < k] = tot;
                mt(tot);
                mt(f);
                splay(tot);
                break;
            }
        }
    }

    void init()
    {
        tot = rt = 0;
    }

    int rk(int k)
    {
        int res = 0, cur = rt;
        while (true)
        {
            if (k < val[cur])
                cur = ch[cur][0];
            else
            {
                res += sz[ch[cur][0]];
                if (k == val[cur])
                {
                    splay(cur);
                    return res + 1;
                }
                res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }

    int kth(int k)
    {
        int cur = rt;
        while (true)
        {
            if (ch[cur][0] && k <= sz[ch[cur][0]])
                cur = ch[cur][0];
            else
            {
                k -= cnt[cur] + sz[ch[cur][0]];
                if (k <= 0)
                    return val[cur];
                cur = ch[cur][1];
            }
        }
    }

    int pred()
    {
        int cur = ch[rt][0];
        while (ch[cur][1])
            cur = ch[cur][1];
        return cur;
    }

    int succ()
    {
        int cur = ch[rt][1];
        while (ch[cur][0])
            cur = ch[cur][0];
        return cur;
    }

    void erase(int k)
    {
        rk(k);
        if (cnt[rt] > 1)
        {
            cnt[rt]--;
            mt(rt);
            return;
        }
        if (!ch[rt][0] && !ch[rt][1])
        {
            reset(rt);
            rt = 0;
            return;
        }
        if (!ch[rt][0])
        {
            int cur = rt;
            rt = ch[rt][1];
            fa[rt] = 0;
            reset(cur);
            return;
        }
        if (!ch[rt][1])
        {
            int cur = rt;
            rt = ch[rt][0];
            fa[rt] = 0;
            reset(cur);
            return;
        }
        int x = pred(), cur = rt;
        splay(x);
        fa[ch[cur][1]] = x;
        ch[x][1] = ch[cur][1];
        reset(cur);
        mt(rt);
    }

} sp;