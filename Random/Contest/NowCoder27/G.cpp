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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 30 + 5;

char board[SIZE][SIZE];

int sx, sy, ex, ey;
int fx, fy;
int n, m;

int pdir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int fdir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

struct Node
{
    bool isFire;
    int x;
    int y;
    int step;

    Node() : isFire(false), x(0), y(0), step(0) {}
    Node(int _x, int _y, bool _isFire) : isFire(_isFire), x(_x), y(_y), step(0) {}
};

bool checkFire(Node s)
{
    if (s.x < 0 || s.x >= n || s.y < 0 || s.y >= m)
        return false;
    return board[s.x][s.y] != '*';
}

bool check(Node s)
{
    if (s.x < 0 || s.x >= n || s.y < 0 || s.y >= m)
        return false;
    return board[s.x][s.y] != '#' && board[s.x][s.y] != '*';
}

int bfs()
{
    queue<Node> q;
    Node s(sx, sy, false);
    Node n, t;
    q.push(s);
    board[s.x][s.y] = '#';

    Node f(fx, fy, true);
    board[f.x][f.y] = '*';
    q.push(f);

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (!t.isFire && t.x == ex && t.y == ey)
            return t.step;

        if (!t.isFire)
        {
            for (int i = 0; i < 4; i++)
            {
                n = t;
                n.x += pdir[i][0];
                n.y += pdir[i][1];
                if (!check(n))
                    continue;
                n.step++;
                board[n.x][n.y] = '#';
                q.push(n);
            }
        }
        else if (t.isFire)
        {
            for (int i = 0; i < 8; i++)
            {
                n = t;
                n.x += fdir[i][0];
                n.y += fdir[i][1];
                if (!checkFire(n))
                    continue;
                n.step++;
                board[n.x][n.y] = '*';
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
    cin >> T;
    cin.get();
    while (T--)
    {
        cin >> n >> m;
        cin.get();
        memset(board, 0, sizeof(board));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = cin.get();
                if (board[i][j] == 'S')
                    sx = i, sy = j;
                if (board[i][j] == 'E')
                    ex = i, ey = j;
                if (board[i][j] == '*')
                    fx = i, fy = j;
            }
            cin.get();
        }
        int res = bfs();
        if (res == -1)
            cout << "T_T" << endl;
        else
            cout << res << endl;
    }

    return 0;
}