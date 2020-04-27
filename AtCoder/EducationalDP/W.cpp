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
const int MAXN = 2e5 + 10;
const ll MIN = -3e14;

struct Line {
  int l, r;
  ll a;
} ls[MAXN];

ll seg[MAXN << 2], flag[MAXN << 2];

void pushup(int pos) { seg[pos] = max(seg[pos << 1], seg[pos << 1 | 1]); }

void pushdown(int pos) {
  if (flag[pos] != 0) {
    flag[pos << 1] += flag[pos];
    flag[pos << 1 | 1] += flag[pos];
    seg[pos << 1] += flag[pos];
    seg[pos << 1 | 1] += flag[pos];
    flag[pos] = 0;
  }
}

void update(int ul, int ur, ll val, int l, int r, int cur) {
  if (ul <= l && r <= ur) {
    seg[cur] += val;
    flag[cur] += val;
    return;
  }

  int m = ((r - l) >> 1) + l;
  pushdown(cur);

  if (ul <= m) {
    update(ul, ur, val, l, m, cur << 1);
  }
  if (ur > m) {
    update(ul, ur, val, m + 1, r, cur << 1 | 1);
  }

  pushup(cur);
}

ll query(int ql, int qr, int l, int r, int cur) {
  if (ql <= l && r <= qr) {
    return seg[cur];
  }

  int m = ((r - l) >> 1) + l;
  pushdown(cur);

  ll ans = MIN;
  if (ql <= m) {
    smax(ans, query(ql, qr, l, m, cur << 1));
  }

  if (qr > m) {
    smax(ans, query(ql, qr, m + 1, r, cur << 1 | 1));
  }

  return ans;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  map<int, vector<int>> s, e;
  int N, M;

  readln(N, M);
  N++;

  for (int i = 0; i < M; i++) {
    readln(ls[i].l, ls[i].r, ls[i].a);
    ls[i].l++, ls[i].r++;

    s[ls[i].l].pb(i);
    e[ls[i].r].pb(i);
  }

  for (int i = 2; i <= N; i++) {
    for (auto p : s[i]) {
      update(1, ls[p].l - 1, ls[p].a, 1, N, 1);
    }

    ll tmp = query(1, i - 1, 1, N, 1);
    update(i, i, tmp, 1, N, 1);

    for (auto p : e[i]) {
      update(1, ls[p].l - 1, -ls[p].a, 1, N, 1);
    }
  }

  writeln(max(0LL, query(1, N, 1, N, 1)));
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