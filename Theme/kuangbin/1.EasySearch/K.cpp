#include <iostream>
#include <cstdio>
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

const int SIZE = 5 + 1;

int board[SIZE][SIZE] = {0};
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}};

struct Node
{
    int x;
    int y;
    vector<pii> step;

    Node() : x(0), y(0){};
};

vector<pii> bfs()
{
    Node s, n, t;
    queue<Node> q;
    board[0][0] = 1;
    s.step.push_back(make_pair(0, 0));
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();
        if (t.x == 4 && t.y == 4)
            return t.step;

        for (int i = 0; i < 4; i++)
        {
            n = t;
            n.x += dir[i][0];
            n.y += dir[i][1];
            if (0 <= n.x && n.x < 5 && 0 <= n.y && n.y < 5 && board[n.x][n.y] != 1)
            {
                n.step.push_back(make_pair(n.x, n.y));
                board[n.x][n.y] = 1;
                q.push(n);
            }
        }
    }

    vector<pii> empty;
    return empty;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            scanf("%d", &board[i][j]);

    vector<pii> res = bfs();

    for (int i = 0; i < res.size(); i++)
        printf("(%d, %d)\n", res[i].first, res[i].second);

    return 0;
}