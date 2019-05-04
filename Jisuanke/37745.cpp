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
const int SIZE = 1010;
int board[SIZE][SIZE];
int dp[SIZE][SIZE];

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n, m, x, y, v, c;
  readln(n, m, x, y, v, c);
  FOR(i, 1, n + 1)
  FOR(j, 1, m + 1)
  cin >> board[i][j];
  dp[x][y] = v;
  // First, change the row x and column y
  for (int i = x - 1; i >= 1; i--) {
    if (dp[i + 1][y] <= 0) break;
    dp[i][y] = min(dp[i + 1][y] + board[i][y], c);
  }
  for (int i = x + 1; i <= n; i++) {
    if (dp[i - 1][y] <= 0) break;
    dp[i][y] = min(dp[i - 1][y] + board[i][y], c);
  }
  for (int j = y - 1; j >= 1; j--) {
    if (dp[x][j + 1] <= 0) break;
    dp[x][j] = min(dp[x][j + 1] + board[x][j], c);
  }
  for (int j = y + 1; j <= m; j++) {
    if (dp[x][j - 1] <= 0) break;
    dp[x][j] = min(dp[x][j - 1] + board[x][j], c);
  }
  // (1,1)
  for (int i = x - 1; i >= 1; i--) {
    for (int j = y - 1; j >= 1; j--) {
      if (dp[i + 1][j] > 0) smax(dp[i][j], dp[i + 1][j] + board[i][j]);
      if (dp[i][j + 1] > 0) smax(dp[i][j], dp[i][j + 1] + board[i][j]);
      if (dp[i][j] > c) dp[i][j] = c;
    }
  }
  // (1,m)
  for (int i = x - 1; i >= 1; i--) {
    for (int j = y + 1; j <= m; j++) {
      if (dp[i + 1][j] > 0) smax(dp[i][j], dp[i + 1][j] + board[i][j]);
      if (dp[i][j - 1] > 0) smax(dp[i][j], dp[i][j - 1] + board[i][j]);
      if (dp[i][j] > c) dp[i][j] = c;
    }
  }
  // (n,1)
  for (int i = x + 1; i <= n; i++) {
    for (int j = y - 1; j >= 1; j--) {
      if (dp[i - 1][j] > 0) smax(dp[i][j], dp[i - 1][j] + board[i][j]);
      if (dp[i][j + 1] > 0) smax(dp[i][j], dp[i][j + 1] + board[i][j]);
      if (dp[i][j] > c) dp[i][j] = c;
    }
  }
  // (n,m)
  for (int i = x + 1; i <= n; i++) {
    for (int j = y + 1; j <= m; j++) {
      if (dp[i - 1][j] > 0) smax(dp[i][j], dp[i - 1][j] + board[i][j]);
      if (dp[i][j - 1] > 0) smax(dp[i][j], dp[i][j - 1] + board[i][j]);
      if (dp[i][j] > c) dp[i][j] = c;
    }
  }
  int ans = 0;
  ans = max(dp[1][1], max(dp[1][m], max(dp[n][1], dp[n][m])));
  if (ans <= 0)
    cout << "-1\n";
  else
    cout << ans << "\n";
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