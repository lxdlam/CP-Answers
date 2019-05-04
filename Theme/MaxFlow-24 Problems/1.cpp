// LOJ 6000
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
const int MAXN = 110;

struct XHLPP {
  int n, m, s, t;
  int cnt;
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

  XHLPP() : cnt(0), highest(0), highestActive(0) {
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

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n;
  int m;
  cin >> n >> m;
  xhlpp.n = n + 2;

  xhlpp.s = 102, xhlpp.t = 104;

  si ll, rr;

  int l, r;
  while (cin >> l >> r) {
    xhlpp.add_edge(l, r, 1LL);
    ll.insert(l);
    rr.insert(r);
  }

  for (auto i : ll) xhlpp.add_edge(102, i, 1LL);

  for (auto i : rr) xhlpp.add_edge(i, 104, 1LL);

  cout << xhlpp() << '\n';
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