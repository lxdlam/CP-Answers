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

const int SIZE = 1e4 + 10;

bool notprime[SIZE] = {false};
bool vis[SIZE] = {false};

void init()
{
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < SIZE; i++)
        if (!notprime[i])
        {
            if (i > SIZE / i)
                continue;
            for (int j = i * i; j < SIZE; j += i)
                notprime[j] = true;
        }
}

struct Node
{
    int num;
    int step;

    Node() {}
    Node(int _num) : num(_num), step(0) {}
};

int bfs(int start, int end)
{
    queue<Node> q;
    Node s, n, t;

    for (int i = 0; i < SIZE; i++)
        vis[i] = false;

    s = Node(start);
    vis[s.num] = true;
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();
        if (t.num == end)
            return t.step;

        for (int i = 0; i <= 9; i++)
        {
            n = t;
            n.num = n.num % 1000 + i * 1000;
            if (!notprime[n.num] && i != 0 && !vis[n.num])
            {
                vis[n.num] = true;
                n.step++;
                q.push(n);
            }
            n = t;
            n.num = (n.num / 1000) * 1000 + n.num % 100 + i * 100;
            if (!notprime[n.num] && !vis[n.num])
            {
                vis[n.num] = true;
                n.step++;
                q.push(n);
            }
            n = t;
            n.num = (n.num / 100) * 100 + n.num % 10 + i * 10;
            if (!notprime[n.num] && !vis[n.num])
            {
                vis[n.num] = true;
                n.step++;
                q.push(n);
            }
            n = t;
            n.num = (n.num / 10) * 10 + i;
            if (!notprime[n.num] && !vis[n.num])
            {
                vis[n.num] = true;
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

    init();

    int T;
    int s, e;
    int res;
    cin >> T;
    while (T--)
    {
        cin >> s >> e;
        res = bfs(s, e);
        if (res == -1)
            cout << "Impossible" << endl;
        else
            cout << res << endl;
    }

    return 0;
}