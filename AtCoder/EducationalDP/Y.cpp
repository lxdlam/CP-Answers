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
const int MAXG = 2e5 + 10;
const int MAXN = 3010;
const ll MOD = 1e9 + 7;

ll dp[MAXN];
ll fac[MAXG], inv[MAXG];

inline ll Add(ll a, ll b, ll m = MOD) { return (a % m + b) % m; }
inline ll Sub(ll a, ll b, ll m = MOD) { return (a % m + m - b % m) % m; }
inline ll Mul(ll a, ll b, ll m = MOD) { return ((a % m) * b) % m; }

ll binary_pow(ll b, ll e, ll m = MOD) {
  ll ans = 1;
  b %= m;
  while (e) {
    if (e & 1LL) {
      ans = Mul(ans, b, m);
    }
    b = Mul(b, b, m);
    e >>= 1LL;
  }

  return ans;
}

ll C(int n, int m) { return Mul(Mul(fac[n], inv[m]), inv[n - m]); }

struct Point {
  int x;
  int y;

  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

  bool left_upper(const Point& p) const { return p.x <= x && p.y <= y; }

  bool operator<(const Point& p) {
    if (x == p.x) {
      return y < p.y;
    }

    return x < p.x;
  }
};

// Pre-Build Function
inline void build() {
  fac[0] = 1;
  for (int i = 1; i < MAXG; i++) {
    fac[i] = Mul(i, fac[i - 1]);
  }

  inv[MAXG - 1] = binary_pow(fac[MAXG - 1], MOD - 2);
  for (int i = MAXG - 2; i >= 0; i--) {
    inv[i] = Mul(i + 1, inv[i + 1]);
  }
}

// Actual Solver
inline void solve() {
  int H, W, N;
  readln(H, W, N);

  vector<Point> v(N);

  for (auto& p : v) {
    readln(p.x, p.y);
  }

  sort(all(v));

  v.emplace_back(H, W);

  for (int i = 0; i <= N; i++) {
    const auto& p = v[i];
    dp[i] = C(p.x + p.y - 2, p.x - 1);
  }

  for (int i = 0; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (v[j].left_upper(v[i])) {
        dp[j] = Sub(dp[j], Mul(dp[i], C(v[j].x + v[j].y - v[i].x - v[i].y, v[j].x - v[i].x)));
      }
    }
  }

  cout << dp[N] << '\n';
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
