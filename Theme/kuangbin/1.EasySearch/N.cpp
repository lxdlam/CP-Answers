#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 200 + 10;
const int MAX = 1000;
int n, m, ans;
int yx, yy, mx, my;

char board[SIZE][SIZE] = {0};
bool vis[SIZE][SIZE] = {false};
int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<pii, int> res;

struct Node
{
    int x;
    int y;
    int step;

    Node() : x(0), y(0), step(0) {}

    Node(int _x, int _y) : x(_x), y(_y), step(0) {}
};

bool check(Node s)
{
    if (s.x < 0 || s.x >= n || s.y < 0 || s.y >= m)
        return false;
    return !vis[s.x][s.y] && board[s.x][s.y] != '#';
}

void bfs()
{
    queue<Node> q;
    Node n, t;

    // Y
    memset(vis, false, sizeof(vis));
    Node ys(yx, yy);
    vis[ys.x][ys.y] = true;
    q.push(ys);

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (board[t.x][t.y] == '@')
            res[make_pair(t.x, t.y)] = t.step;

        for (int i = 0; i < 4; i++)
        {
            n = t;
            n.x += dir[i][0];
            n.y += dir[i][1];
            if (check(n))
            {
                vis[n.x][n.y] = true;
                n.step++;
                q.push(n);
            }
        }
    }

    // M
    memset(vis, false, sizeof(vis));
    Node ms(mx, my);
    vis[ms.x][ms.y] = true;
    q.push(ms);

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (board[t.x][t.y] == '@')
            res[make_pair(t.x, t.y)] += t.step;

        for (int i = 0; i < 4; i++)
        {
            n = t;
            n.x += dir[i][0];
            n.y += dir[i][1];
            if (check(n))
            {
                vis[n.x][n.y] = true;
                n.step++;
                q.push(n);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> m)
    {
        cin.get();
        res.clear();
        ans = MAX;
        memset(board, 0, sizeof(board));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = cin.get();
                if (board[i][j] == 'Y')
                    yx = i, yy = j;
                if (board[i][j] == 'M')
                    mx = i, my = j;
            }
            cin.get();
        }
        bfs();
        for (map<pii, int>::iterator it = res.begin(); it != res.end(); it++)
            ans = min(ans, it->second);
        cout << 11 * ans << endl;
    }

    return 0;
}