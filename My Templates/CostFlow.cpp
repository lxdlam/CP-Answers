#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

const int MAXN = 1e4 + 10;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using pqii = __gnu_pbds::priority_queue<pii, greater<pii>, __gnu_pbds::pairing_heap_tag>;
using pqll = __gnu_pbds::priority_queue<pll, greater<pll>, __gnu_pbds::pairing_heap_tag>;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;

// SPFA
/*
 * Too slow, will not implement it.
 * Core idea: using spfa to replace dfs in EK algorithm.
 */

struct ZKW
{
    int n, m, s, t;
    ll MaxFlow, MinCost, delta;

    struct Edge
    {
        int to, rev;
        ll cap, cost;
    };

    vector<Edge> E[MAXN];
    bool vis[MAXN];

    ZKW() : MaxFlow(0), MinCost(0), delta(0) {}

    void add_edge(int u, int v, ll cap, ll cost)
    {
        E[u].push_back({v, (int)E[v].size(), cap, cost});
        E[v].push_back({u, (int)E[u].size() - 1, 0, -cost});
    }

    ll Augment(int u, ll a)
    {
        if (u == t)
        {
            MinCost += a * delta;
            return a;
        }

        vis[u] = true;
        ll f = a;

        for (auto &e : E[u])
        {
            if (!e.cost && e.cap && !vis[e.to])
            {
                ll d = Augment(e.to, min(f, e.cap));
                e.cap -= d;
                E[e.to][e.rev].cap += d;
                f -= d;
                if (!f)
                    return a;
            }
        }

        return a - f;
    }

    void operator()()
    {
        while (true)
        {
            while (true)
            {
                memset(vis, 0, sizeof vis);
                ll f = Augment(s, INFLL);
                if (!f)
                    break;
                MaxFlow += f;
            }
            ll d = INFLL;
            for (int u = 1; u <= n; u++)
                if (vis[u])
                    for (auto &e : E[u])
                        if (e.cap && !vis[e.to])
                            d = min(d, e.cost);
            if (d == INFLL)
                return;
            for (int u = 1; u <= n; u++)
                if (vis[u])
                    for (auto &e : E[u])
                    {
                        e.cost -= d;
                        E[e.to][e.rev].cost += d;
                    }
            delta += d;
        }
    }
} zkw;

struct Primal_Dual
{
    int n, m, s, t;
    ll MaxFlow, MinCost, delta;
    struct Edge
    {
        int to, rev;
        ll flow, cap, cost;
    };

    using Node = pair<ll, int>;
    using pqnode = __gnu_pbds::priority_queue<Node, greater<Node>, __gnu_pbds::pairing_heap_tag>;

    vector<Edge> E[MAXN];
    bool vis[MAXN], inq[MAXN];
    ll dis[MAXN];

    pqnode pq;
    pqnode::point_iterator it[MAXN];

    Primal_Dual() : MaxFlow(0LL), MinCost(0LL), delta(0LL)
    {
        memset(dis, 0x3f, sizeof dis);
        memset(inq, 0, sizeof inq);
    }

    void add_edge(int u, int v, ll cap, ll cost)
    {
        E[u].push_back({v, (int)E[v].size(), 0, cap, cost});
        E[v].push_back({u, (int)E[u].size() - 1, 0, 0, -cost});
    }

    void Reduce()
    {
        for (int i = 1; i <= n; i++)
            for (auto &e : E[i])
                e.cost += dis[e.to] - dis[i];
        delta += dis[s];
    }

    bool BellmanFord()
    {
        queue<int> q;

        dis[t] = 0;
        q.push(t);
        inq[t] = true;

        while (q.size())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (auto &e : E[u])
            {
                int to = e.to;
                const auto &R = E[to][e.rev];
                ll f = R.flow, c = R.cap, len = R.cost;
                if (f < c && dis[to] > dis[u] + len)
                {
                    dis[to] = dis[u] + len;
                    if (!inq[to])
                    {
                        inq[to] = true;
                        q.push(to);
                    }
                }
            }
        }

        return dis[s] != INFLL;
    }

    bool Dijkstra()
    {
        memset(dis, 0x3f, sizeof dis);
        memset(it, 0, sizeof it);
        
        dis[t] = 0;
        it[t] = pq.push({dis[t], t});

        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            int u = p.second;

            for (auto &e : E[u])
            {
                int to = e.to;
                const auto &R = E[to][e.rev];
                ll f = R.flow, c = R.cap, len = R.cost;
                if (f < c && dis[to] > dis[u] + len)
                {
                    dis[to] = dis[u] + len;
                    if (it[to] != nullptr)
                        pq.modify(it[to], {dis[to], to});
                    else
                        it[to] = pq.push({dis[to], to});
                }
            }
        }
        return dis[s] != INFLL;
    }

    ll dfs(int u, ll flow)
    {
        if (u == t || !flow)
            return flow;
        vis[u] = true;
        ll ret = flow;

        for (auto &e : E[u])
        {
            int to = e.to;
            ll f = e.flow, c = e.cap, len = e.cost;
            if (!vis[to] && f < c && !len)
            {
                ll tmp = dfs(to, min(ret, c - f));
                e.flow += tmp;
                E[to][e.rev].flow -= tmp;
                ret -= tmp;
            }
        }

        return flow - ret;
    }

    void Augment()
    {
        ll cur = 0;
        memset(vis, 0, sizeof(vis));
        while ((cur = dfs(s, INFLL)))
        {
            MaxFlow += cur;
            MinCost += cur * delta;
        }
    }

    void operator()()
    {
        if (!BellmanFord())
            return;
        do
        {
            Reduce();
            Augment();
        } while (Dijkstra());
    }
} pd;