#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int SIZE = 30 + 10;

char board[SIZE][SIZE][SIZE];
int l, r, c;

int dir[6][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1}};

struct Node
{
    int x, y, z;
    int step;

    Node() : x(0), y(0), z(0), step(0) {}

    Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z), step(0) {}
};

bool check(Node n)
{
    if (n.x < 0 || n.x >= l)
        return false;
    if (n.y < 0 || n.y >= r)
        return false;
    if (n.z < 0 || n.z >= c)
        return false;
    if (board[n.x][n.y][n.z] == '#')
        return false;
    return true;
}

int bfs(int sx, int sy, int sz, int ex, int ey, int ez)
{
    queue<Node> q;
    Node s(sx, sy, sz);
    Node t, n;
    board[s.x][s.y][s.z] = '#';
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();
        if (t.x == ex && t.y == ey && t.z == ez)
            return t.step;
        for (int i = 0; i < 6; i++)
        {
            n = t;
            n.x += dir[i][0];
            n.y += dir[i][1];
            n.z += dir[i][2];
            if (!check(n))
                continue;
            board[n.x][n.y][n.z] = '#';
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

    int sx, sy, sz, ex, ey, ez;
    int t;
    while (cin >> l >> r >> c && l)
    {
        memset(board, 0, sizeof(board));
        for (int x = 0; x < l; x++)
        {
            for (int y = 0; y < r; y++)
            {
                for (int z = 0; z < c; z++)
                {
                    cin >> board[x][y][z];
                    if (board[x][y][z] == 'S')
                        sx = x, sy = y, sz = z;
                    else if (board[x][y][z] == 'E')
                        ex = x, ey = y, ez = z;
                }
                cin.get();
            }
            cin.get();
        }
        t = bfs(sx, sy, sz, ex, ey, ez);
        if (t == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << t << " minute(s)." << endl;
    }
    return 0;
}