#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 1e3 + 10;

char board[SIZE][SIZE] = {0};
int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int r, c;
int jx, jy;
vector<pii> f;

struct Node
{
    bool j;
    int x;
    int y;
    int step;

    Node() : j(false), x(0), y(0), step(0) {}

    Node(bool _j, int _x, int _y) : j(_j), x(_x), y(_y), step(0){};
};

bool out(Node n)
{
    if (!n.j)
        return false;
    if (n.x == 0 || n.x == r - 1 || n.y == 0 || n.y == c - 1)
        return true;
    return false;
}

bool check(Node n)
{
    if (n.x < 0 || n.x >= r || n.y < 0 || n.y >= c)
        return false;
    return board[n.x][n.y] != '#';
}

int bfs()
{
    queue<Node> q;
    Node n, t;

    for (int i = 0; i < f.size(); i++)
    {
        Node fs(false, f[i].first, f[i].second);
        board[fs.x][fs.y] = '#';
        q.push(fs);
    }

    Node js(true, jx, jy);
    q.push(js);
    board[js.x][js.y] = '#';

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (out(t))
            return t.step;

        for (int i = 0; i < 4; i++)
        {
            n = t;
            n.x += dir[i][0];
            n.y += dir[i][1];
            if (check(n))
            {
                board[n.x][n.y] = '#';
                n.step++;
                q.push(n);
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    int res;

    cin >> T;
    while (T--)
    {
        memset(board, 0, sizeof(board));
        f.clear();
        cin >> r >> c;
        cin.get();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                board[i][j] = cin.get();
                if (board[i][j] == 'J')
                    jx = i, jy = j;
                if (board[i][j] == 'F')
                    f.push_back(make_pair(i, j));
            }
            cin.get();
        }

        res = bfs();
        if (res == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << res + 1 << endl;
    }

    return 0;
}