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
#define L ((pos) << 1)
#define R ((pos) << 1 | 1)

const int SIZE = 1e5 + 10;
ll N, M, P;

ll s[SIZE << 2], add[SIZE << 2], mul[SIZE << 2];
ll num[SIZE];

void pushup(int pos) { s[pos] = (s[L] + s[R]) % P; }

void pushdown(int pos, int lt, int rt) {
  if (mul[pos] != 1) {
    mul[L] = (mul[L] * mul[pos]) % P;
    mul[R] = (mul[R] * mul[pos]) % P;

    if (add[L]) add[L] = (add[L] * mul[pos]) % P;
    if (add[R]) add[R] = (add[R] * mul[pos]) % P;

    s[L] = (s[L] * mul[pos]) % P;
    s[R] = (s[R] * mul[pos]) % P;

    mul[pos] = 1;
  }

  if (add[pos]) {
    add[L] = (add[L] + add[pos]) % P;
    add[R] = (add[R] + add[pos]) % P;

    s[L] = (s[L] + 1LL * lt * add[pos]) % P;
    s[R] = (s[R] + 1LL * rt * add[pos]) % P;

    add[pos] = 0;
  }
}

#undef L
#undef R

#define L ((cur) << 1)
#define R ((cur) << 1 | 1)

void update(int ul, int ur, int type, ll val, int l, int r, int cur) {
  if (ul <= l && ur >= r) {
    // multiply
    if (type == 1) {
      mul[cur] = (mul[cur] * val) % P;
      if (add[cur]) add[cur] = (add[cur] * val) % P;
      s[cur] = (s[cur] * val) % P;
    }
    // addition
    else if (type == 2) {
      add[cur] = (add[cur] + val) % P;
      s[cur] = (s[cur] + 1LL * (r - l + 1) * val) % P;
    }
    return;
  }

  int m = ((r - l) >> 1) + l;
  pushdown(cur, m - l + 1, r - m);

  if (ul <= m) update(ul, ur, type, val, l, m, L);
  if (ur > m) update(ul, ur, type, val, m + 1, r, R);

  pushup(cur);
}

void build(int l, int r, int cur) {
  add[cur] = 0;
  mul[cur] = 1;

  if (l == r) {
    s[cur] = num[l];
    return;
  }

  int m = ((r - l) >> 1) + l;

  build(l, m, L);
  build(m + 1, r, R);

  pushup(cur);
}

ll query(int ql, int qr, int l, int r, int cur) {
  if (ql <= l && r <= qr) return s[cur] % P;

  int m = ((r - l) >> 1) + l;

  pushdown(cur, m - l + 1, r - m);

  ll ans = 0;
  if (ql <= m) ans = (ans + query(ql, qr, l, m, L)) % P;
  if (qr > m) ans = (ans + query(ql, qr, m + 1, r, R)) % P;

  return ans % P;
}

#undef L
#undef R

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  readln(N, M, P);

  FOR(i, 1, N + 1)
  cin >> num[i];

  build(1, N, 1);

  while (M--) {
    int op, x, y;
    ll k;
    cin >> op;
    if (op == 3) {
      cin >> x >> y;
      cout << query(x, y, 1, N, 1) % P << '\n';
    } else {
      cin >> x >> y >> k;
      update(x, y, op, k, 1, N, 1);
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