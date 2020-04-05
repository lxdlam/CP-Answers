#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.7.1"
// Useful Marcos
//====================START=====================
// Compile use C++11 and above
#ifdef LOCAL
#define debug(args...)                       \
  do {                                       \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  } while (0)
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
#define MSG cout << "Finished" << endl
#else
#define debug(args...)
#define MSG
#endif
#if __cplusplus >= 201703L
template <typename... Args>
void readln(Args&... args) {
  ((cin >> args), ...);
}
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
  cout << endl;
}
#elif __cplusplus >= 201103L
void readln() {}
template <typename T, typename... Args>
void readln(T& a, Args&... args) {
  cin >> a;
  readln(args...);
}
void writeln() { cout << endl; }
template <typename T, typename... Args>
void writeln(T a, Args... args) {
  cout << a << " ";
  writeln(args...);
}
#endif
#if __cplusplus >= 201103L
#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)
#else
#define FOR(_i, _begin, _end) for (int _i = (int)_begin; _i < (int)_end; _i++)
#define FORR(_i, _begin, _end) for (int _i = (int)_begin; _i > (int)_end; _i--)
#define nullptr NULL
#endif
#if __cplusplus >= 201103L
#define VIS(_kind, _name, _size) \
  vector<_kind> _name(_size);    \
  for (auto& i : _name) cin >> i;
#else
#define VIS(_kind, _name, _size) \
  vector<_kind> _name;           \
  _name.resize(_size);           \
  for (int i = 0; i < _size; i++) cin >> _name[i];
#endif
// alias
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof(x))
#define infty(x) memset((x), 0x3f, sizeof(x))
#define tcase() \
  int T;        \
  cin >> T;     \
  FOR(kase, 1, T + 1)

// Swap max/min
template <typename T>
bool smax(T& a, const T& b) {
  if (a > b) return false;
  a = b;
  return true;
}
template <typename T>
bool smin(T& a, const T& b) {
  if (a < b) return false;
  a = b;
  return true;
}
// ceil divide
template <typename T>
T cd(T a, T b) {
  return (a + b - 1) / b;
}
// min exchange
template <typename T>
bool se(T& a, T& b) {
  if (a < b) return false;
  swap(a, b);
  return true;
}
// A better MAX choice
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
const int MAXN = 20010;

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
    bool operator<(const Atom& a) const { return h < a.h; }
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
    for (auto& it : E[x]) {
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

vector<pair<int, int>> relation[210];

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    cout << "Case #" << kase << ": ";
    int N;
    cin >> N;

    for (auto& it : relation) it.clear();

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        int t;
        cin >> t;
        t += 100;
        relation[t].pb({i, j});
      }
    }

    int ans = 0;

    for (auto E : relation) {
      if (E.empty()) continue;
      HLPP hlpp;

      hlpp.s = 0, hlpp.t = 201;
      hlpp.n = 201;

      set<int> ss, ts;

      for (auto it : E) {
        int u = it.first, v = it.second + 100;
        ss.insert(u);
        ts.insert(v);
        hlpp.add_edge(u, v, 1);
      }

      for (auto it : ss) hlpp.add_edge(0, it, 1);

      for (auto it : ts) hlpp.add_edge(it, 201, 1);

      ans += hlpp();
    }

    cout << N * N - ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef LOCAL
  clock_t _begin = clock();
#endif

  build();
  solve();

#ifdef LOCAL
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

  return 0;
}