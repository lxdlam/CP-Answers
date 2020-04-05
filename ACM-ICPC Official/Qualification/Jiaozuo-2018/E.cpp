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
const int SIZE = 1e5 + 10;

struct edge {
  int next, to;
} e[SIZE << 1];

int rt, n, r, cnt, head[SIZE];
int f[SIZE];
int d[SIZE];
int sizet[SIZE];
int son[SIZE];
int rk[SIZE];
int top[SIZE];
int tid[SIZE];

ull s[SIZE << 2];
ull add[SIZE << 2], mul[SIZE << 2];

void init() {
  memset(e, 0, sizeof e);
  memset(head, 0, sizeof head);
  memset(f, 0, sizeof f);
  memset(d, 0, sizeof d);
  memset(sizet, 0, sizeof sizet);
  memset(son, 0, sizeof son);
  memset(rk, 0, sizeof rk);
  memset(top, 0, sizeof top);
  memset(tid, 0, sizeof tid);
  memset(s, 0, sizeof s);
  memset(add, 0, sizeof add);
  memset(mul, 0, sizeof mul);
}

void add_edge(int x, int y) {
  e[++cnt].next = head[x];
  e[cnt].to = y;
  head[x] = cnt;
}

void dfs1(int u, int fa, int depth) {
  f[u] = fa;
  d[u] = depth;
  sizet[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs1(v, u, depth + 1);
    sizet[u] += sizet[v];
    if (sizet[v] > sizet[son[u]]) {
      son[u] = v;
    }
  }
}

void dfs2(int u, int t) {
  top[u] = t;
  tid[u] = ++cnt;
  rk[cnt] = u;
  if (!son[u]) return;
  dfs2(son[u], t);

  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v != son[u] && v != f[u]) {
      dfs2(v, v);
    }
  }
}

void pushup(int pos) { s[pos] = s[pos << 1] + s[pos << 1 | 1]; }

void pushdown(int pos, int lt, int rt) {
  if (mul[pos] != 1) {
    mul[pos << 1] = mul[pos << 1] * mul[pos];
    mul[pos << 1 | 1] = mul[pos << 1 | 1] * mul[pos];
    if (add[pos << 1]) add[pos << 1] = add[pos << 1] * mul[pos];
    if (add[pos << 1 | 1]) add[pos << 1 | 1] = add[pos << 1 | 1] * mul[pos];

    s[pos << 1] = s[pos << 1] * mul[pos];
    s[pos << 1 | 1] = s[pos << 1 | 1] * mul[pos];

    mul[pos] = 1;
  }
  if (add[pos]) {
    add[pos << 1] = add[pos << 1] + add[pos];
    add[pos << 1 | 1] = add[pos << 1 | 1] + add[pos];

    s[pos << 1] = s[pos << 1] + lt * add[pos];
    s[pos << 1 | 1] = s[pos << 1 | 1] + rt * add[pos];

    add[pos] = 0;
  }
}

void update(int ul, int ur, int type, ull val, int l, int r, int cur) {
  if (ul <= l && r <= ur) {
    if (type == 2) {
      mul[cur] = mul[cur] * val;
      if (add[cur]) add[cur] = add[cur] * val;
      s[cur] = s[cur] * val;
    } else {
      add[cur] = add[cur] + val;
      s[cur] = s[cur] + (r - l + 1) * val;
    }
    return;
  }

  int m = ((r - l) >> 1) + l;
  pushdown(cur, m - l + 1, r - m);
  if (ul <= m) update(ul, ur, type, val, l, m, cur << 1);
  if (ur > m) update(ul, ur, type, val, m + 1, r, cur << 1 | 1);
  pushup(cur);
}

void build(int l, int r, int cur) {
  add[cur] = 0;
  mul[cur] = 1;
  if (l == r) {
    s[cur] = 0;
    return;
  }

  int m = ((r - l) >> 1) + l;
  build(l, m, cur << 1);
  build(m + 1, r, cur << 1 | 1);
  pushup(cur);
}

ull query(int ql, int qr, int l, int r, int cur) {
  if (ql <= l && r <= qr) return s[cur];

  int m = ((r - l) >> 1) + l;
  pushdown(cur, m - l + 1, r - m);
  ull ans = 0;
  if (ql <= m) ans = ans + query(ql, qr, l, m, cur << 1);
  if (qr > m) ans = ans + query(ql, qr, m + 1, r, cur << 1 | 1);
  return ans;
}

void updateTree(int x, int y, ull val, int type) {
  int fx = top[x], fy = top[y];
  while (fx != fy) {
    if (d[fx] >= d[fy]) {
      update(tid[fx], tid[x], type, val, 1, n, 1);
      x = f[fx];
    } else {
      update(tid[fy], tid[y], type, val, 1, n, 1);
      y = f[fy];
    }
    fx = top[x];
    fy = top[y];
  }
  if (tid[x] <= tid[y])
    update(tid[x], tid[y], type, val, 1, n, 1);
  else
    update(tid[y], tid[x], type, val, 1, n, 1);
}

ull sum(int x, int y) {
  ull ans = 0;
  int fx = top[x], fy = top[y];
  while (fx != fy) {
    if (d[fx] >= d[fy]) {
      ans += query(tid[fx], tid[x], 1, n, 1);
      x = f[fx];
    } else {
      ans += query(tid[fy], tid[y], 1, n, 1);
      y = f[fy];
    }
    fx = top[x];
    fy = top[y];
  }
  if (tid[x] <= tid[y])
    ans += query(tid[x], tid[y], 1, n, 1);
  else
    ans += query(tid[y], tid[x], 1, n, 1);
  return ans;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  while (cin >> n) {
    init();
    int t, m;
    FOR(i, 1, n) {
      cin >> t;
      add_edge(t, i + 1);
      add_edge(i + 1, t);
    }
    cnt = 0;
    dfs1(1, 0, 1);
    dfs2(1, 1);
    cnt = 0;
    rt = cnt++;
    build(1, n, 1);
    cin >> m;
    while (m--) {
      int opt, u, v;
      ull z;
      readln(opt, u, v);
      if (opt == 1) {
        cin >> z;
        updateTree(u, v, z, 2);
      } else if (opt == 2) {
        cin >> z;
        updateTree(u, v, z, 1);
      } else if (opt == 3) {
        updateTree(u, v, -1, 2);
        updateTree(u, v, -1, 1);
      } else if (opt == 4)
        cout << sum(u, v) << '\n';
    }
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