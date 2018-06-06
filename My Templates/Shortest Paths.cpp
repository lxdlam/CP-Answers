// NOT FINISH
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

// ======== Dijkstra ========
// ==== Common ====
const int SIZE = 1e5 + 10;  // Points
int dis[SIZE];              // Storage the shortest path length
const int INF = 0x3f3f3f3f; // Infinite
// Naive version
// Use adjust matrix
// O(n^2)
int vis[SIZE];
int board[SIZE][SIZE];

void dijkstra(int n, int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, m = INF;
        for (int y = 1; y <= n; y++)
        {
            if (!vis[y] && dis[y] <= m)
            {
                m = dis[y];
                x = y;
            }
        }
        vis[x] = true;
        for (int y = 1; y <= n; y++)
            dis[y] = min(dis[y], dis[x] + board[x][y]);
    }
}

// Heap version
// Use priority to speed up the process
// Use adjust table
// O(ElogV)
using pii = pair<int, int>;
vector<pii> G[SIZE];

// For the choice of heap:
// Pairing heap > STL heap (Binary heap) > thin heap (Fibonacci heap)
// Use pairing heap as default
using pqii = __gnu_pbds::priority_queue<pii, greater<pii>, __gnu_pbds::pairing_heap_tag>;

void dijkstra(int n, int s)
{
    pqii pq;
    memset(dis, 0x3f, sizeof(dis));

    dis[s] = 0;
    pq.push(make_pair(0, s));

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.second;
        if (dis[x] < p.first)
            continue;
        for (auto i : G[x])
        {
            if (dis[i.first] > dis[x] + i.second)
            {
                dis[i.first] = dis[x] + i.second;
                pq.push(make_pair(dis[i.first], i.first));
            }
        }
    }
}