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
struct Solver {
  struct Point {
    int x, y;
  };

  int tot = 0;
  int A, B;
  Point seed[5] = {{0, 0}, {0, 500000000}, {0, -500000000}, {-500000000, 0}, {500000000, 0}};

  Solver(int _A, int _B) : A(_A), B(_B) {}

  bool check(int x, int y) { return -1e9 <= x && x <= 1e9 && -1e9 <= y && y <= 1e9; }

  void run() {
    tot = 0;
    int idx = -1;
    for (int i = 0; i < 5; i++) {
      int ret = ask(seed[i]);
      if (ret == 1) {
        idx = i;
        break;
      } else if (ret == 0) {
        return;
      }
    }

    if (idx == -1) {
      cerr << "No valid seed in the circle!" << endl;
      terminate();
    }

    auto a = find_horizontal(seed[idx], true), b = find_horizontal(seed[idx], false);

    Point p{(a.x + b.x) / 2, a.y};

    auto c = find_down(p);

    find_center(c, a, b);
  }

  void find_center(Point a, Point b, Point c) {
    double px1 = (1.0 * b.x + a.x) / 2.0, py1 = (1.0 * b.y + a.y) / 2.0;
    double px2 = (1.0 * c.x + a.x) / 2.0, py2 = (1.0 * c.y + a.y) / 2.0;

    double k1 = (1.0 * a.x - b.x) / (1.0 * b.y - a.y);
    double k2 = (1.0 * a.x - c.x) / (1.0 * c.y - a.y);

    double cx = (py2 - py1 - k2 * px2 + k1 * px1) / (k1 - k2);
    double cy = py1 + k1 * (cx - px1);

    for (int x = (int)cx - 5; x <= (int)cx + 5; x++) {
      for (int y = (int)cy - 5; y <= (int)cy + 5; y++) {
        if (check(x, y) && ask({x, y}) == 0) {
          return;
        }
      }
    }

    cerr << "WRONG no valid answer for center (" << cx << ", " << cy << ")" << endl;
    terminate();
  }

  Point find_horizontal(Point p, bool left) {
    Point ret{0, p.y};
    int l, r, in;

    if (left) {
      l = -1000000000, r = p.x;
      in = 1;
    } else {
      l = p.x, r = 1000000000;
      in = 2;
    }

    while (l < r) {
      int m = (l + r) >> 1;

      if (ask({m, p.y}) == in) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    ret.x = l;
    return ret;
  }

  Point find_down(Point p) {
    Point ret{p.x, 0};
    int l = -1e9, r = p.y;

    while (l < r) {
      int m = (l + r) >> 1;

      if (ask({p.x, m}) == 1) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    ret.y = l;
    return ret;
  }

  int ask(Point p) {
    if (tot >= 300) {
      cerr << "More than 300 asks!" << endl;
      terminate();
    }

    const int &x = p.x, &y = p.y;

    string s;
    cout << x << " " << y << endl;
    cin >> s;

    tot++;

    if (s[0] == 'C') {
      return 0;
    } else if (s[0] == 'H') {
      return 1;
    } else if (s[0] == 'M') {
      return 2;
    } else {
      cerr << "WRONG with ask (" << x << ", " << y << ")" << endl;
      terminate();
    }
  }
};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int T, A, B;
  readln(T, A, B);

  Solver s(A, B);

  for (int i = 0; i < T; i++) {
    s.run();
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