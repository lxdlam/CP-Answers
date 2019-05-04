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
void readln(Args &... args) {
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
void readln(T &a, Args &... args) {
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
  for (auto &i : _name) cin >> i;
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
bool smax(T &a, const T &b) {
  if (a > b) return false;
  a = b;
  return true;
}
template <typename T>
bool smin(T &a, const T &b) {
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
bool se(T &a, T &b) {
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
const int MAXN = 5e4 + 10;

struct Dinic {
  int s, t, n, m;

  struct Edge {
    int to, rev;
    bool ex;
    ll cap;
  };

  vector<Edge> E[MAXN];
  int dep[MAXN];
  int arc[MAXN];

  Dinic() { memset(dep, 0, sizeof dep); }

  void add_edge(int u, int v, ll cap, bool ex = false, ll rcap = 0) {
    E[u].push_back({v, (int)E[v].size(), ex, cap});
    E[v].push_back({u, (int)E[u].size() - 1, ex, rcap});
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

  void ClearSup() {
    for (auto &e : E)
      for (auto &it : e)
        if (it.ex) it.to = 50005;
    E[s].clear();
    E[t].clear();
  }

} dinic;

ll F[MAXN] = {0};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  dinic.s = 50005;  // ss
  dinic.t = 50006;  // tt
  dinic.n = 50006;
  int n, m, s, t;
  ll sum = 0;
  readln(n, m, s, t);

  int u, v, lo, hi;

  while (m--) {
    readln(u, v, lo, hi);
    dinic.add_edge(u, v, hi - lo);
    F[u] -= lo;
    F[v] += lo;
  }

  for (int i = 1; i <= n; i++) {
    if (F[i] > 0)
      dinic.add_edge(dinic.s, i, F[i], true), sum += F[i];
    else if (F[i] < 0)
      dinic.add_edge(i, dinic.t, -F[i], true);
  }

  dinic.add_edge(t, s, INFLL, true);

  if (sum != dinic())
    cout << "please go home to sleep\n";
  else {
    auto &e = dinic.E[t].back();
    sum = dinic.E[e.to][e.rev].cap;
    dinic.ClearSup();
    dinic.s = t;
    dinic.t = s;
    dinic.n = n;
    cout << sum - dinic() << '\n';
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC
       << "ms." << endl;
#endif

  return 0;
}