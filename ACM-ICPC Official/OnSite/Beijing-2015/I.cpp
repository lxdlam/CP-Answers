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
struct node {
  int x, y;

  node(int _x, int _y) : x(_x), y(_y) {}
};

vector<node> ans[510];
si s;

// Pre-Build Function
inline void build() {
  int k = 2;
  while (k < 500) {
    s.insert(k);
    k *= 2;
  }
}

// Actual Solver
inline void solve() {
  int n;
  while (cin >> n) {
    FOR(i, 1, n + 1)
    ans[i].clear();
    int h = (n + 1) / 2;
    int w = n * (n + 1) / (2 * h);
    writeln(h, w);
    for (int i = h; i > 0; i--) {
      int cur = 2 * (h - i) + 1;
      for (int j = 1; j <= (cur + 1) / 2; j++) ans[cur].pb(node(i, j));
      int k = (cur + 1) / 2;
      for (int j = i + 1; j <= h; j++) ans[cur].pb(node(j, k));
    }

    int sx, sy;
    if ((n + 1) % 4 <= 1) {
      for (int i = 2; i <= n; i += 2) {
        if (i % 4) {
          sx = i / 2, sy = h + 1;
          for (int j = 0; j < i / 2; j++) ans[i].pb(node(sx, sy + j));
          for (int j = i / 2 - 1; j >= 0; j--) ans[i].pb(node(sx + 1, sy + j));
        } else {
          sx = 1, sy = h + i / 2;
          for (int j = 0; j < i / 2; j++) ans[i].pb(node(sx + j, sy));
          for (int j = i / 2 - 1; j >= 0; j--) ans[i].pb(node(sx + j, sy + 1));
        }
      }
    } else {
      for (int i = 2; i <= n; i += 2) {
        if (i % 4) {
          sx = 1, sy = h + i / 2;
          for (int j = 0; j < i / 2; j++) ans[i].pb(node(sx + j, sy));
          for (int j = i / 2 - 1; j >= 0; j--) ans[i].pb(node(sx + j, sy + 1));
        } else {
          sx = i / 2, sy = h + 1;
          for (int j = 0; j < i / 2; j++) ans[i].pb(node(sx, sy + j));
          for (int j = i / 2 - 1; j >= 0; j--) ans[i].pb(node(sx + 1, sy + j));
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (auto j : ans[i]) cout << j.x << ' ' << j.y << ' ';
      cout << '\n';
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