#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int st, a, b;

const int SIZE = 100 + 5;

bool vis[SIZE][SIZE] = {false};

struct Node
{
    int x;
    int y;
    int s;
    int step;

    Node() : x(0), y(0), s(0), step(0) {}

    Node(int _s) : x(0), y(0), s(_s), step(0) {}
};

void pour(int &src, int &dest, int ld)
{
    if (src + dest > ld)
    {
        src = src + dest - ld;
        dest = ld;
    }
    else
    {
        dest += src;
        src = 0;
    }
}

int bfs()
{
    Node s(st);
    Node n, t;
    queue<Node> q;
    vis[0][0] = true;
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (t.s * 2 == st && t.y * 2 == st)
            return t.step;

        n = t;
        if (n.s && n.x != a)
            pour(n.s, n.x, a);
        if (!vis[n.x][n.y])
        {
            vis[n.x][n.y] = true;
            n.step++;
            q.push(n);
        }

        n = t;
        if (n.s && n.y != b)
            pour(n.s, n.y, b);
        if (!vis[n.x][n.y])
        {
            vis[n.x][n.y] = true;
            n.step++;
            q.push(n);
        }

        n = t;
        if (n.x && n.s != st)
            pour(n.x, n.s, st);
        if (!vis[n.x][n.y])
        {
            vis[n.x][n.y] = true;
            n.step++;
            q.push(n);
        }

        n = t;
        if (n.x && n.y != b)
            pour(n.x, n.y, b);
        if (!vis[n.x][n.y])
        {
            vis[n.x][n.y] = true;
            n.step++;
            q.push(n);
        }

        n = t;
        if (n.y && n.s != st)
            pour(n.y, n.s, st);
        if (!vis[n.x][n.y])
        {
            vis[n.x][n.y] = true;
            n.step++;
            q.push(n);
        }

        n = t;
        if (n.y && n.x != a)
            pour(n.y, n.x, a);
        if (!vis[n.x][n.y])
        {
            vis[n.x][n.y] = true;
            n.step++;
            q.push(n);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int res;
    while (cin >> st >> a >> b && st)
    {
        if (st % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        if (a > b)
            swap(a, b);
        memset(vis, false, sizeof(vis));
        res = bfs();
        if (res == -1)
            cout << "NO" << endl;
        else
            cout << res << endl;
    }

    return 0;
}