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

const int SIZE = 10 + 5;
const int MAX = 1000;

char board[SIZE][SIZE] = {0};
char tmp[SIZE][SIZE] = {0};

int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};

vector<pii> coor;

int n, m;

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
    if (s.x >= n || s.x < 0 || s.y >= m || s.y < 0)
        return false;
    else
        return tmp[s.x][s.y] != '.';
}

int bfs(int a, int b, int x, int y)
{
    int cnt = coor.size();
    int res = 0;
    memcpy(tmp, board, sizeof(board));

    Node s1(a, b), s2(x, y);
    Node n, t;
    queue<Node> q;
    tmp[s1.x][s1.y] = '.';
    tmp[s2.x][s2.y] = '.';
    q.push(s1);
    q.push(s2);
    cnt -= 2;

    while (q.size())
    {
        t = q.front();
        q.pop();
        res = max(res, t.step);

        if (cnt == 0)
            return res;

        for (int i = 0; i < 4; i++)
        {
            n = t;
            n.x += dir[i][0];
            n.y += dir[i][1];
            n.step++;
            if (check(n))
            {
                cnt--;
                tmp[n.x][n.y] = '.';
                q.push(n);
                res = max(n.step, res);
            }
        }
    }

    return MAX;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    int res;
    cin >> T;
    for (int kase = 1; kase <= T; kase++)
    {
        cout << "Case " << kase << ": ";
        memset(board, 0, sizeof(board));
        coor.clear();
        cin >> n >> m;
        res = MAX;
        cin.get();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '#')
                    coor.push_back(make_pair(i, j));
            }
            cin.get();
        }
        int size = coor.size();
        if (size <= 2)
            cout << 0 << endl;
        else
        {
            for (int i = 0; i < size; i++)
                for (int j = i + 1; j < size; j++)
                    res = min(res, bfs(coor[i].first, coor[i].second, coor[j].first, coor[j].second));

            if (res == MAX)
                cout << -1 << endl;
            else
                cout << res << endl;
        }
    }

    return 0;
}