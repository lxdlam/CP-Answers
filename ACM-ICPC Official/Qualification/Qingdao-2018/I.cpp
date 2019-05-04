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
typedef double db;
const db EPS = 1e-8;
const db PI = acos(-1);
const db HPI = acos(0.0);
const db DT = 1e-6;

struct Simpson {
  typedef double db;

  // If supports C++11
  function<db(db)> f = [](db x) -> db {
    db t = sin(x);
    return 1.0 / (sqrt(t * t + 3) - t);
  };

  // Otherwise
  // db f(db x) { return x * x; }

  db simpson(db L, db R) {
    db m = (L + R) / 2.0;
    return (f(L) + 4.0 * f(m) + f(R)) * (R - L) / 6.0;
  }

  db go(db L, db R, db EPS) {
    db m = (L + R) / 2.0;
    db sl = simpson(L, m), sr = simpson(m, R), st = simpson(L, R);
    if (abs(sl + sr - st) <= 15.0 * EPS) return sl + sr + (sl + sr - st) / 15.0;
    return go(L, m, EPS / 2.0) + go(m, R, EPS / 2.0);
  }
} sim;

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  // Based on http://cubercsl.cn/solve/contest/Kuririn-MIRACLE/#more
  cout << fixed << setprecision(15);
  const db wh = sim.go(0, PI, EPS);

  tcase() {
    db v, r, d;
    cin >> v >> r >> d;
    db ans = d / v;
    db al = HPI, ar = PI;
    if (4 * r + 2 * r * wh >= d) {
      cout << ans << '\n';
      continue;
    }
    while (ar - al > EPS) {
      db m = (ar + al) / 2.0;
      db t = sim.go(0, m, EPS);
      db y = 2 * r * sin(PI - m);
      db x = 2 * r * cos(PI - m) + 2 * r * t + 2 * r;
      db beta = atan2(y, d - x);
      db dx = 2 * r * cos(PI - m) + 2 * v * cos(beta) * DT - v * DT;
      db dy = 2 * r * sin(PI - m) - 2 * v * sin(beta) * DT;
      if (dx * dx + dy * dy >= 4 * r * r) {
        db tmp = (d - x) * (d - x) + y * y;
        tmp = t * 2 * r / v + sqrt(tmp) / (2.0 * v);
        smin(ans, tmp);
        ar = m;
      } else
        al = m;
    }
    cout << ans << '\n';
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