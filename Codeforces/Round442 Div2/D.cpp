#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 1000 + 10;

char board[SIZE][SIZE] = {0};
vector<vector<bitset<4>>> vis(SIZE, vector<bitset<4>>(SIZE));

int n, m, sx, sy, ex, ey, k;

int dir[4][2] = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0}};

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
    if (s.x > n || s.x < 1 || s.y > m || s.y < 1)
        return false;
    else
        return board[s.x][s.y] != '#';
}

int bfs()
{
    queue<Node> q;
    Node s(sx, sy);
    Node n, t;
    vis[s.x][s.y] = 1111;
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (t.x == ex && t.y == ey)
            return t.step;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                n = t;
                n.x += dir[i][0] * j;
                n.y += dir[i][1] * j;
                if (vis[n.x][n.y][i])
                    break;
                if (check(n))
                {
                    vis[n.x][n.y][i] = 1;
                    n.step++;
                    q.push(n);
                }
                else
                    break;
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

    cin >> n >> m >> k;
    cin.get();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            board[i][j] = cin.get();
        cin.get();
    }

    cin >> sx >> sy >> ex >> ey;
    cout << bfs() << endl;

    return 0;
}