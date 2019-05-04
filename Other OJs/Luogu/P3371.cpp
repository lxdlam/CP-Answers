#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

#define TemplateVersion "3.2.0"
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
const int SIZE = 2e5 + 10;

struct Edge {
  int next, to, w;

  Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE];
int last[SIZE];
int dis[SIZE];
int cnt = 0;

void add_edge(int u, int v, int w) {
  E[++cnt].next = last[u];  // Current edge's next edge, in a revesed order.
  E[cnt].to = v;            // Current edge's end
  E[cnt].w = w;             // Current edge's power
  last[u] = cnt;            // In a reversed order
}

using pqii =
    __gnu_pbds::priority_queue<pii, greater<pii>, __gnu_pbds::pairing_heap_tag>;

void dijkstra(int n, int s) {
  pqii pq;
  memset(dis, 0x3f, sizeof(dis));

  dis[s] = 0;
  pq.push(make_pair(0, s));

  while (pq.size()) {
    auto p = pq.top();
    pq.pop();
    int x = p.second;
    if (dis[x] < p.first) continue;
    for (int i = last[x]; i; i = E[i].next) {
      if (dis[E[i].to] > dis[x] + E[i].w) {
        dis[E[i].to] = dis[x] + E[i].w;
        pq.push(mp(dis[E[i].to], E[i].to));
      }
    }
  }
}

// Pre-Build Function
inline void build() { memset(dis, 0x3f, sizeof(dis)); }

// Actual Solver
inline void solve() {
  int n, m, s;
  int x, y, w;
  readln(n, m, s);
  while (m--) {
    readln(x, y, w);
    add_edge(x, y, w);
  }
  dijkstra(n, s);
  FOR(i, 1, n + 1)
  cout << (dis[i] == INF ? INT_MAX : dis[i]) << ' ';
  cout << '\n';
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