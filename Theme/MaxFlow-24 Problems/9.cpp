// LOJ 6008 / Luogu 1251
#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.4.1"
// Useful Marcos
//====================START=====================
// Compile use C++11 and above
#ifdef LOCAL
#define debug(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
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
const int MAXN = 2010;
const int BASE = 1000;

struct ZKW {
  int n, m, s, t;
  ll MaxFlow, MinCost, delta;

  struct Edge {
    int to, rev;
    ll cap, cost;
  };

  vector<Edge> E[MAXN];
  bool vis[MAXN];

  ZKW() : MaxFlow(0), MinCost(0), delta(0) {}

  void add_edge(int u, int v, ll cap, ll cost) {
    E[u].push_back({v, (int)E[v].size(), cap, cost});
    E[v].push_back({u, (int)E[u].size() - 1, 0, -cost});
  }

  ll Augment(int u, ll a) {
    if (u == t) {
      MinCost += a * delta;
      return a;
    }

    vis[u] = true;
    ll f = a;

    for (auto& e : E[u]) {
      if (!e.cost && e.cap && !vis[e.to]) {
        ll d = Augment(e.to, min(f, e.cap));
        e.cap -= d;
        E[e.to][e.rev].cap += d;
        f -= d;
        if (!f) return a;
      }
    }

    return a - f;
  }

  void operator()() {
    while (true) {
      while (true) {
        memset(vis, 0, sizeof vis);
        ll f = Augment(s, INFLL);
        if (!f) break;
        MaxFlow += f;
      }
      ll d = INFLL;
      for (int u = 1; u <= n; u++)
        if (vis[u])
          for (auto& e : E[u])
            if (e.cap && !vis[e.to]) d = min(d, e.cost);
      if (d == INFLL) return;
      for (int u = 1; u <= n; u++)
        if (vis[u])
          for (auto& e : E[u]) {
            e.cost -= d;
            E[e.to][e.rev].cost += d;
          }
      delta += d;
    }
  }
} zkw;

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n, P, M, F, N, S, t;
  readln(n, P, M, F, N, S);
  zkw.n = 2009;
  zkw.s = 2008;
  zkw.t = 2009;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    zkw.add_edge(zkw.s, i + BASE, t, 0);
    zkw.add_edge(i, zkw.t, t, 0);

    zkw.add_edge(zkw.s, i, INF, P);
  }

  for (int i = 1; i <= n; i++) {
    if (i + 1 <= n) zkw.add_edge(i + BASE, i + 1 + BASE, INF, 0);
    if (i + M <= n) zkw.add_edge(i + BASE, i + M, INF, F);
    if (i + N <= n) zkw.add_edge(i + BASE, i + N, INF, S);
  }

  zkw();

  cout << zkw.MinCost << '\n';
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