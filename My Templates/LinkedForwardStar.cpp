#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 10; // Number of edges

struct Edge
{
    // next: the *previous* edge which start with the same start point
    // to: the end of the current edge
    // w: the power of current edge
    int next, to, w;

    Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE];
int last[SIZE];
int cnt = 0;

void add_edge(int u, int v, int w)
{
    E[++cnt].next = last[u]; // Current edge's next edge, in a revesed order.
    E[cnt].to = v; // Current edge's end
    E[cnt].w = w; // Current edge's power
    last[u] = cnt; // In a reversed order
}