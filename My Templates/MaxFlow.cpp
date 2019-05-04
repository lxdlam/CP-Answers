#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;

// Ford-Fulkerson Series

// Edmond-Karp
/*
 * I will not implement this method. Only describe it.
 * Using BFS to find the shortest augment path on the residental network,
 * then for each augment path, set all edges' current flow to the minimum
 * capacity in this path. Then modify the road: add the reverse edge which
 * capacity is original capacity minus current capacity. When there are no more
 * augment paths, the algorithm terminates.
 */

// Dinic
const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;

struct Dinic {
  int s, t, n, m;
  int cnt;

  struct Edge {
    int to, next, rev;
    ll cap;
  } E[MAXM << 1];

  int last[MAXN];
  int dep[MAXN];
  int arc[MAXN];

  Dinic() {
    cnt = 0;
    memset(E, 0, sizeof E);
    memset(last, 0, sizeof last);
    memset(dep, 0, sizeof dep);
  }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    E[++cnt].next = last[u];
    E[cnt].to = v;
    E[cnt].cap = cap;
    E[cnt].rev = cnt + 1;
    last[u] = cnt;

    // reverse edge
    E[++cnt].next = last[v];
    E[cnt].to = u;
    E[cnt].cap = rcap;
    E[cnt].rev = cnt - 1;
    last[v] = cnt;
  }

  bool bfs() {
    queue<int> q;

    memset(dep, 0, sizeof dep);
    dep[s] = 1;
    q.push(s);

    while (q.size()) {
      int x = q.front();
      q.pop();
      for (int i = last[x]; i; i = E[i].next) {
        if (E[i].cap && !dep[E[i].to]) {
          dep[E[i].to] = dep[x] + 1;
          q.push(E[i].to);
        }
      }
    }
    if (!dep[t]) return false;
    return true;
  }

  ll dfs(int cur, ll flow) {
    if (cur == t) return flow;
    for (int &i = arc[cur]; i; i = E[i].next) {
      if (dep[E[i].to] == dep[cur] + 1 && E[i].cap) {
        ll ret = dfs(E[i].to, min(flow, E[i].cap));
        if (ret) {
          E[i].cap -= ret;
          E[E[i].rev].cap += ret;
          return ret;
        }
      }
    }
    return 0;
  }

  ll operator()() {
    ll ans = 0;
    while (bfs()) {
      for (int i = 1; i <= n; i++) arc[i] = last[i];
      while (ll ret = dfs(s, INFLL)) ans += ret;
    }
    return ans;
  }

} dinic;

// Using vector Linked Forward Star
struct Dinic {
  int s, t, n, m;

  struct Edge {
    int to, rev;
    ll cap;
  };

  vector<Edge> E[MAXN];
  int dep[MAXN];
  int arc[MAXN];

  Dinic() { memset(dep, 0, sizeof dep); }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    E[u].push_back({v, (int)E[v].size(), cap});
    E[v].push_back({u, (int)E[u].size() - 1, rcap});
  }

  bool bfs() {
    queue<int> q;

    memset(dep, 0, sizeof dep);
    dep[s] = 1;
    q.push(s);

    while (q.size()) {
      int x = q.front();
      q.pop();
      for (auto it : E[x]) {
        if (it.cap && !dep[it.to]) {
          dep[it.to] = dep[x] + 1;
          q.push(it.to);
        }
      }
    }
    if (!dep[t]) return false;
    return true;
  }

  ll dfs(int cur, ll flow) {
    if (cur == t) return flow;
    auto &c = E[cur];
    for (int &i = arc[cur]; i < c.size(); i++) {
      if (dep[c[i].to] == dep[cur] + 1 && c[i].cap) {
        ll ret = dfs(c[i].to, min(flow, c[i].cap));
        if (ret) {
          c[i].cap -= ret;
          E[c[i].to][c[i].rev].cap += ret;
          return ret;
        }
      }
    }
    return 0;
  }

  ll operator()() {
    ll ans = 0;
    while (bfs()) {
      for (int i = 1; i <= n; i++) arc[i] = 0;
      while (ll ret = dfs(s, INFLL)) ans += ret;
    }
    return ans;
  }

} dinic;

// ISAP
// Will not implement SAP.
// The fasterest in FF series
struct ISAP {
  int s, t, n, m;
  int cnt;

  struct Edge {
    int to, next, rev;
    ll cap;
  } E[MAXM << 1];

  int last[MAXN];
  int dep[MAXN];
  int arc[MAXN];
  int gap[MAXN];

  ISAP() {
    cnt = 0;
    memset(E, 0, sizeof E);
    memset(last, 0, sizeof last);
    memset(dep, 0, sizeof dep);
    memset(gap, 0, sizeof gap);
  }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    E[++cnt].next = last[u];
    E[cnt].to = v;
    E[cnt].cap = cap;
    E[cnt].rev = cnt + 1;
    last[u] = cnt;

    // reverse edge
    E[++cnt].next = last[v];
    E[cnt].to = u;
    E[cnt].cap = rcap;
    E[cnt].rev = cnt - 1;
    last[v] = cnt;
  }

  void bfs() {
    queue<int> q;

    dep[t] = 1;
    gap[dep[t]] = 1;
    q.push(t);

    while (q.size()) {
      int x = q.front();
      q.pop();
      for (int i = last[x]; i; i = E[i].next) {
        if (!dep[E[i].to]) {
          dep[E[i].to] = dep[x] + 1;
          gap[dep[E[i].to]]++;
          q.push(E[i].to);
        }
      }
    }
  }

  ll dfs(int cur, ll flow) {
    if (cur == t) return flow;
    ll cf = 0;
    for (int &i = arc[cur]; i; i = E[i].next) {
      if (E[i].cap && dep[cur] == dep[E[i].to] + 1) {
        ll ret = dfs(E[i].to, min(flow - cf, E[i].cap));
        E[i].cap -= ret;
        E[E[i].rev].cap += ret;
        cf += ret;
        if (cf == flow) return cf;
      }
    }

    gap[dep[cur]]--;
    if (!gap[dep[cur]]) dep[s] = n + 1;
    arc[cur] = last[cur];
    gap[++dep[cur]]++;

    return cf;
  }

  ll operator()() {
    ll ans = 0;
    bfs();
    for (int i = 1; i <= n; i++) arc[i] = last[i];
    while (dep[s] <= n) ans += dfs(s, INFLL);
    return ans;
  }
} isap;

// Using vector Linked Forward Star
struct ISAP {
  int s, t, n, m;

  struct Edge {
    int to, rev;
    ll cap;
  };

  vector<Edge> E[MAXN];
  int dep[MAXN];
  int arc[MAXN];
  int gap[MAXN];

  ISAP() {
    memset(dep, 0, sizeof dep);
    memset(gap, 0, sizeof gap);
  }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    E[u].push_back({v, (int)E[v].size(), cap});
    E[v].push_back({u, (int)E[u].size() - 1, rcap});
  }

  void bfs() {
    queue<int> q;

    dep[t] = 1;
    gap[dep[t]] = 1;
    q.push(t);

    while (q.size()) {
      int x = q.front();
      q.pop();
      for (auto it : E[x]) {
        if (!dep[it.to]) {
          dep[it.to] = dep[x] + 1;
          gap[dep[it.to]]++;
          q.push(it.to);
        }
      }
    }
  }

  ll dfs(int cur, ll flow) {
    if (cur == t) return flow;
    ll cf = 0;
    auto &c = E[cur];
    for (int &i = arc[cur]; i < c.size(); i++) {
      if (dep[c[i].to] + 1 == dep[cur] && c[i].cap) {
        ll ret = dfs(c[i].to, min(flow - cf, c[i].cap));
        c[i].cap -= ret;
        E[c[i].to][c[i].rev].cap += ret;
        cf += ret;
        if (cf == flow) return cf;
      }
    }

    gap[dep[cur]]--;
    if (!gap[dep[cur]]) dep[s] = n + 1;
    arc[cur] = 0;
    gap[++dep[cur]]++;

    return cf;
  }

  ll operator()() {
    ll ans = 0;
    bfs();
    for (int i = 1; i <= n; i++) arc[i] = 0;
    while (dep[s] <= n) ans += dfs(s, INFLL);
    return ans;
  }
} isap;

// Push-Relabel
// HLPP
// Faster than ISAP
struct HLPP {
  int s, t, n, m;

  struct Edge {
    int to, rev;
    ll cap;
  };

  vector<Edge> E[MAXN];
  int last[MAXN];
  int h[MAXN];
  int gap[MAXN << 1];
  bool inq[MAXN];
  ll flow[MAXN];

  struct Atom {
    int x, h;
    bool operator<(const Atom &a) const { return h < a.h; }
  };

  priority_queue<Atom> pq;

  HLPP() {
    memset(h, 0x3f, sizeof h);
    memset(gap, 0, sizeof gap);
    memset(inq, 0, sizeof inq);
    memset(flow, 0, sizeof flow);
  }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    E[u].push_back({v, (int)E[v].size(), cap});
    E[v].push_back({u, (int)E[u].size() - 1, rcap});
  }

  bool bfs() {
    queue<int> q;
    int cur;
    h[t] = 0;
    q.push(t);

    while (q.size()) {
      cur = q.front();
      q.pop();
      for (auto it : E[cur]) {
        if (h[it.to] > h[cur] + 1 && E[it.to][it.rev].cap) {
          h[it.to] = h[cur] + 1;
          q.push(it.to);
        }
      }
    }

    return h[s] != INF;
  }

  void push(int x) {
    ll d;
    for (auto &it : E[x]) {
      int u = it.to;
      if (it.cap && h[u] + 1 == h[x]) {
        d = min(flow[x], it.cap);
        it.cap -= d;
        E[u][it.rev].cap += d;
        flow[x] -= d;
        flow[u] += d;
        if (u != s && u != t && !inq[u]) {
          pq.push({u, h[u]});
          inq[u] = true;
        }
        if (!flow[x]) break;
      }
    }
  }

  void relabel(int x) {
    h[x] = INF;
    for (auto it : E[x])
      if (it.cap && h[it.to] + 1 < h[x]) h[x] = h[it.to] + 1;
  }

  ll operator()() {
    int u;
    if (!bfs()) return 0LL;
    h[s] = n;
    for (int i = 1; i <= n; i++)
      if (h[i] < INF) gap[h[i]]++;

    for (auto it : E[s]) {
      ll d = it.cap;
      u = it.to;
      if (d) {
        it.cap -= d;
        E[u][it.rev].cap += d;
        flow[s] -= d;
        flow[u] += d;
        if (u != s && u != t && !inq[u]) {
          pq.push({u, h[u]});
          inq[u] = true;
        }
      }
    }

    while (pq.size()) {
      u = pq.top().x;
      pq.pop();
      inq[u] = false;
      push(u);
      if (flow[u]) {
        if (!--gap[h[u]])
          for (int i = 1; i <= n; i++)
            if (i != s && i != t && h[i] > h[u] && h[i] < n + 1) h[i] = n + 1;

        relabel(u);
        gap[h[u]]++;
        pq.push({u, h[u]});
        inq[u] = true;
      }
    }

    return flow[t];
  }

} hlpp;

// xehoth Optimized HLPP
// Run incredibly fast
// Thanks to xehoth
// See https://loj.ac/user/104 and https://loj.ac/submission/69505
struct XHLPP {
  int n, m, s, t;
  int highest, highestActive;

  struct Edge {
    int to, rev;
    ll cap;
  };

  vector<Edge> E[MAXN];
  int h[MAXN];
  int count[MAXN];
  ll ex[MAXN];
  vector<int> ve[MAXN];
  list<int> li[MAXN];
  list<int>::iterator iters[MAXN];

  XHLPP() : highest(0), highestActive(0) {
    memset(count, 0, sizeof count);
    memset(ex, 0, sizeof ex);
    memset(h, 0, sizeof h);
  }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    E[u].push_back({v, (int)E[v].size(), cap});
    E[v].push_back({u, (int)E[u].size() - 1, rcap});
  }

  void globalRelabel() {
    int x;
    fill(h, h + MAXN, n);
    h[t] = 0;

    queue<int> q;
    q.push(t);

    while (q.size()) {
      x = q.front();
      q.pop();
      int ch = h[x] + 1;
      for (auto it : E[x]) {
        if (h[it.to] == n && E[it.to][it.rev].cap > 0) {
          h[it.to] = ch;
          count[ch]++;
          q.push(it.to);
        }
      }
    }

    for (int i = 0; i <= n; i++) {
      ve[i].clear();
      li[i].clear();
    }

    for (int u = 1; u <= n; u++) {
      if (h[u] < n) {
        iters[u] = li[h[u]].insert(li[h[u]].begin(), u);
        if (ex[u] > 0) ve[h[u]].push_back(u);
      }
    }

    highest = highestActive = h[x];
  }

  void push(int u, Edge &e) {
    int x = e.to;
    ll df = min(ex[u], e.cap);
    e.cap -= df;
    E[x][e.rev].cap += df;
    ex[u] -= df;
    ex[x] += df;
    if (ex[x] > 0 && ex[x] <= df) ve[h[x]].push_back(x);
  }

  void discharge(int u) {
    int nh = n;
    for (auto &it : E[u]) {
      if (it.cap > 0) {
        if (h[u] == h[it.to] + 1) {
          push(u, it);
          if (!ex[u]) return;
        } else
          nh = min(nh, h[it.to] + 1);
      }
    }

    int ch = h[u];
    if (count[ch] == 1) {
      for (int i = ch; i <= highest; i++) {
        while (li[i].size()) {
          int el = li[i].front();
          count[h[el]]--;
          h[el] = n;
          li[i].pop_front();
        }
      }
      highest = ch - 1;
    } else {
      count[ch]--;
      iters[u] = li[ch].erase(iters[u]);
      h[u] = nh;
      if (nh == n) return;
      count[nh]++;
      iters[u] = li[nh].insert(li[nh].begin(), u);
      highest = max(highest, highestActive = nh);
      ve[nh].push_back(u);
    }
  }

  ll operator()() {
    if (s == t) return 0LL;
    h[s] = n;

    for (int i = 1; i <= n; i++)
      if (i != s) iters[i] = li[h[i]].insert(li[h[i]].begin(), i);

    count[0] = n - 1;
    ex[s] = INFLL;
    ex[t] = -INFLL;

    for (auto &it : E[s]) push(s, it);

    globalRelabel();

    int u;
    while (highestActive >= 0) {
      if (ve[highestActive].empty()) {
        highestActive--;
        continue;
      }
      u = ve[highestActive].back();
      ve[highestActive].pop_back();
      discharge(u);
    }

    return ex[t] + INFLL;
  }

} xhlpp;