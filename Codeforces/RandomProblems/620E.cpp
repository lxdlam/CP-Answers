#include <bits/stdc++.h>

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
const int SIZE = 4e5 + 10;
const int MAXN = 70;

ll bm[MAXN] = {1};
int val[SIZE];

struct Edge {
  int next, to, w;

  Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE << 1];
int last[SIZE];
bool vis[SIZE];
int cnt = 0;
int din[SIZE], dout[SIZE];
int Dcnt = 0;

void add_edge(int u, int v, int w) {
  E[++cnt].next = last[u];
  E[cnt].to = v;
  E[cnt].w = w;
  last[u] = cnt;
}

void dfs(int idx) {
  if (vis[idx]) return;
  vis[idx] = true;
  din[idx] = ++Dcnt;
  for (int i = last[idx]; i; i = E[i].next) dfs(E[i].to);
  dout[idx] = Dcnt;
}

ll sum[SIZE << 2], flag[SIZE << 2];

void pushup(int pos) { sum[pos] = sum[pos << 1] | sum[pos << 1 | 1]; }

void pushdown(int pos) {
  if (flag[pos]) {
    flag[pos << 1] = flag[pos << 1 | 1] = flag[pos];
    sum[pos << 1] = flag[pos];
    sum[pos << 1 | 1] = flag[pos];

    flag[pos] = 0;
  }
}

void build(int l, int r, int cur) {
  if (l == r) {
    sum[cur] = bm[val[l]];
    return;
  }

  int m = ((r - l) >> 1) + l;
  build(l, m, cur << 1);
  build(m + 1, r, cur << 1 | 1);
  pushup(cur);
}

void update(int ul, int ur, int v, int l, int r, int cur) {
  if (ul <= l && r <= ur) {
    sum[cur] = bm[v];
    flag[cur] = bm[v];
    return;
  }

  int m = ((r - l) >> 1) + l;
  pushdown(cur);

  if (ul <= m) update(ul, ur, v, l, m, cur << 1);
  if (ur > m) update(ul, ur, v, m + 1, r, cur << 1 | 1);
  pushup(cur);
}

ll query(int ql, int qr, int l, int r, int cur) {
  if (ql <= l && r <= qr) return sum[cur];

  int m = ((r - l) >> 1) + l;
  pushdown(cur);

  ll ans = 0;

  if (ql <= m) ans |= query(ql, qr, l, m, cur << 1);
  if (qr > m) ans |= query(ql, qr, m + 1, r, cur << 1 | 1);
  return ans;
}

// Pre-Build Function
inline void build() {
  FOR(i, 1, 62) { bm[i] = 2 * bm[i - 1]; }
}

// Actual Solver
inline void solve() {
  int n, m;
  readln(n, m);

  VIS(ll, v, n);
  int x, y;
  FOR(i, 1, n) {
    readln(x, y);
    se(x, y);
    add_edge(x, y, 1);
    add_edge(y, x, 1);
  }

  dfs(1);

  // Important!!
  // This step, we use the timestamp to store the real color
  // like if vertice 6 have color 5
  // and the timestamp is 7
  // we update val[7] = 5
  FOR(i, 1, n + 1)
  val[din[i]] = v[i - 1];

  build(1, n, 1);

  int op;
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      update(din[x], dout[x], y, 1, n, 1);
    } else {
      cin >> x;
      ll ans = query(din[x], dout[x], 1, n, 1);
      int cnt = 0;
      while (ans) {
        cnt++;
        ans &= (ans - 1);
      }
      cout << cnt << endl;
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC
       << "ms." << endl;
#endif

  return 0;
}