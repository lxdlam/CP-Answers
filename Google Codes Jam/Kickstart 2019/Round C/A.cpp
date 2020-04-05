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
const int SIZE = 5e4 + 10;

map<int, int> Rs[SIZE], Re[SIZE];
map<int, int> Cs[SIZE], Ce[SIZE];

void insert(int x, int y) {
  // Insert Y
  bool l = Rs[x].count(y - 1), r = Re[x].count(y + 1);
  if (l && r) {
    int ls = Rs[x][y - 1], re = Re[x][y + 1];
    Re[x][ls] = re, Rs[x][re] = ls;
  } else if (l) {
    int ls = Rs[x][y - 1];
    Rs[x][y] = ls, Re[x][ls] = y;
  } else if (r) {
    int re = Re[x][y + 1];
    Rs[x][re] = y, Re[x][y] = re;
  } else {
    Re[x][y] = Rs[x][y] = y;
  }

  l = Cs[y].count(x - 1), r = Ce[y].count(x + 1);
  if (l && r) {
    int ls = Cs[y][x - 1], re = Ce[y][x + 1];
    Ce[y][ls] = re, Cs[y][re] = ls;
  } else if (l) {
    int ls = Cs[y][x - 1];
    Cs[y][x] = ls, Ce[y][ls] = x;
  } else if (r) {
    int re = Ce[y][x + 1];
    Cs[y][re] = x, Ce[y][x] = re;
  } else {
    Ce[y][x] = Cs[y][x] = x;
  }
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    cout << "Case #" << kase << ": ";
    int N, R, C, X, Y;
    readln(N, R, C, X, Y);
    string S;
    cin >> S;

    for (int i = 1; i <= R; i++) {
      Rs[i].clear();
      Re[i].clear();
    }
    for (int i = 1; i <= C; i++) {
      Cs[i].clear();
      Ce[i].clear();
    }

    insert(X, Y);

    for (auto it : S) {
      if (it == 'E') {
        if (Re[X].count(Y + 1)) {
          Y = Re[X][Y + 1] + 1;
        } else
          Y++;
      } else if (it == 'W') {
        if (Rs[X].count(Y - 1)) {
          Y = Rs[X][Y - 1] - 1;
        } else
          Y--;
      } else if (it == 'N') {
        if (Cs[Y].count(X - 1)) {
          X = Cs[Y][X - 1] - 1;
        } else
          X--;
      } else {
        if (Ce[Y].count(X + 1)) {
          X = Ce[Y][X + 1] + 1;
        } else
          X++;
      }

      insert(X, Y);
    }

    cout << X << ' ' << Y << '\n';
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