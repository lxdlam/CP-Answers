#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 10; // Number of edges

struct Edge
{
    int next, to, w;

    Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE];
int last[SIZE];
int cnt = 0;

void add_edge(int u, int v, int w = 1)
{
    E[++cnt].next = last[u];
    E[cnt].to = v;
    E[cnt].w = w;
    last[u] = cnt;
}

struct Edge
{
    int to, w;

    Edge() : to(0), w(0) {}

    Edge(int _to, int _w) : to(_to), w(_w) {}
};

vector<Edge> E[SIZE];

void add_edge(int u, int v, int w = 1)
{
    E[u].push_back({v, w});
}