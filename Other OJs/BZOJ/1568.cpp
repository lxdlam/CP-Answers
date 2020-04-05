#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define TemplateVersion "3.6.0"
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
#define tcase()       \
  int T;              \
  cin >> T;           \
  FOR(kase, 1, T + 1) \
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
const int SIZE = 5e4 + 10;

struct Line {
  double s, p;

  // how the line evaluates
  // for example, it's a*x+b;
  double eval(int x) { return s + x * p; };
};

struct LiChaoTree {
  // here, size is the maximum point coordinate
  // i.e., maximum possible x
  Line tr[SIZE << 2];

  // fill with the starting line
  void init(Line l) { fill(tr, tr + (SIZE << 2), l); }

  // in below functions
  // the initial call must using
  // the maximum possible x
  // as argument r
  // NOT THE SIZE OF THE TREE!

  void add(Line li, int l, int r, int cur) {
    int m = (l + r) >> 1;
    bool le = li.eval(l) > tr[cur].eval(l);
    bool mid = li.eval(m) > tr[cur].eval(m);

    if (mid) swap(tr[cur], li);
    if (l == r)
      return;
    else if (le != mid)
      add(li, l, m, cur << 1);
    else
      add(li, m + 1, r, cur << 1 | 1);
  }

  double query(int pos, int l, int r, int cur) {
    if (l == r) return tr[cur].eval(pos);

    int m = (l + r) >> 1;

    // change the behavior here to query maximum or minimum
    if (pos < m)
      return max(tr[cur].eval(pos), query(pos, l, m, cur << 1));
    else
      return max(tr[cur].eval(pos), query(pos, m + 1, r, cur << 1 | 1));
  }
} LCT;

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int N;
  cin >> N;
  while (N--) {
    string q;
    cin >> q;
    if (q[0] == 'P') {
      double s, p;
      cin >> s >> p;

      Line node;
      node.s = s - p, node.p = p;
      LCT.add(node, 1, SIZE, 1);
    } else {
      int d;
      cin >> d;
      cout << (int)floor(LCT.query(d, 1, SIZE, 1) / 100.0) << '\n';
    }
  }
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

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