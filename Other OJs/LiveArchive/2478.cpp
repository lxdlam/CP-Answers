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
const int MAXN = 60;
const int MAXM = MAXN * MAXN;

class DSU {
public:
  void init(int n) {
    id.clear();
    sz.clear();
    count = length = n;
    id.resize(n);
    for (int i = 0; i < length; i++) id[i] = i;
    sz.resize(n);
    for (int i = 0; i < length; i++) sz[i] = 1;
  }

  int getCount() { return count; }

  bool connected(int p, int q) { return find(p) == find(q); }

  int find(int p) {
    int k = p, j;
    while (p != id[p]) p = id[p];
    while (k != p) {
      j = id[k];
      id[k] = p;
      k = j;
    }
    return p;
  }

  void link(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot) return;

    if (sz[pRoot] < sz[qRoot]) {
      id[pRoot] = qRoot;
      sz[qRoot] += sz[pRoot];
    } else {
      id[qRoot] = pRoot;
      sz[pRoot] += sz[qRoot];
    }
    count--;
  }

private:
  int count;
  vector<int> id;
  vector<int> sz;
  int length;
} dsu;

struct Island {
  int x, y;
  int r;

  double dis(const Island& i) const {
    double dx = x - i.x;
    double dy = y - i.y;
    return sqrt(dx * dx + dy * dy);
  }
} islands[MAXN];

struct Edge {
  int to;
  double w;

  Edge(int _to = 0, double _w = 0.0) : to(_to), w(_w) {}
};

vector<Edge> E[MAXN];
double avail[MAXN];
bool vis[MAXN];

void add_edge(int u, int v, double w) {
  E[u].push_back({v, w});
  E[v].push_back({u, w});
}

// Pre-Build Function
inline void build() {}

void reset(int n) {
  dsu.init(n);
  for (int i = 0; i < n; i++) {
    E[i].clear();
    avail[i] = 0.0;
    vis[i] = false;
  }
}

struct Atom {
  int x, y;
  double d;

  Atom(int _x, int _y, double _d) : x(_x), y(_y), d(_d) {}

  bool operator<(const Atom& a) const { return d < a.d; }
};

void dfs(int cur, int fa, double d) {
  if (vis[cur]) {
    return;
  }

  vis[cur] = true;

  if (avail[fa] >= d) {
    avail[cur] = avail[fa];
  } else {
    avail[cur] = d;
  }

  for (const auto& node : E[cur]) {
    dfs(node.to, cur, node.w);
  }
}

// Actual Solver
inline void solve() {
  int n;
  int kase = 1;
  while (scanf("%d", &n) == 1 && n) {
    reset(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &islands[i].x, &islands[i].y, &islands[i].r);
    }

    vector<Atom> v;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        v.pb({i, j, islands[i].dis(islands[j])});
      }
    }

    sort(all(v));

    for (const auto& item : v) {
      if (!dsu.connected(item.x, item.y)) {
        dsu.link(item.x, item.y);
        add_edge(item.x, item.y, item.d);
      }

      if (dsu.getCount() == 1) {
        break;
      }
    }

    double tt = 0.0, sum = 0.0;
    dfs(0, 0, 0);

    for (int i = 0; i < n; i++) {
      tt += avail[i] * islands[i].r;
      sum += islands[i].r;
    }

    printf("Island Group: %d Average %.2f\n\n", kase++, tt / sum);
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