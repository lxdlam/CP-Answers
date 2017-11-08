#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int SIZE = 2e6 + 10;

typedef long long ll;
int l, r;

bool vis[SIZE] = {false};

struct Node
{
    int x;
    int step;

    Node() : x(0), step(0) {}

    Node(int _x) : x(_x), step(0) {}
};

bool check(Node n)
{
    if (n.x < 0 || n.x > SIZE)
        return false;
    return !vis[n.x];
}

int bfs()
{
    queue<Node> q;
    Node s(l);
    Node t, n;
    vis[s.x] = true;
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();
        if (t.x == r)
            return t.step;

        // Op1
        n = t;
        n.x++;
        if (check(n))
        {
            vis[n.x] = true;
            n.step++;
            q.push(n);
        }

        // Op2
        n = t;
        n.x--;
        if (check(n))
        {
            vis[n.x] = true;
            n.step++;
            q.push(n);
        }

        // Op3
        n = t;
        n.x *= 2;
        if (check(n))
        {
            vis[n.x] = true;
            n.step++;
            q.push(n);
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    cout << bfs() << endl;
    return 0;
}