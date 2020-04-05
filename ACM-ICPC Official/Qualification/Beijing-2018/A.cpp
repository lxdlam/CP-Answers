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
const int SIZE = 110;

int dp[SIZE][SIZE][6];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
vector<string> board;

struct Node {
  int x, y, s;
  int t;

  Node() : x(0), y(0), s(0), t(0){};

  Node(int _x, int _y) : x(_x), y(_y), s(0), t(0) {}
};

bool check(Node p) {
  if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) return false;
  if (p.s <= 0 && board[p.x][p.y] == '#') return false;
  return dp[p.x][p.y][p.s] > p.t;
}

int bfs(int sx, int sy) {
  int ans = INF;
  queue<Node> q;
  Node s(sx, sy), n, t;
  q.push(s);
  dp[sx][sy][0] = 0;

  while (q.size()) {
    t = q.front();
    q.pop();

    if (board[t.x][t.y] == 'T') smin(ans, dp[t.x][t.y][t.s]);
    if (board[t.x][t.y] == 'P') t.t--;
    if (board[t.x][t.y] == 'B') t.s++;
    if (board[t.x][t.y] == '#') t.s--, t.t++;

    for (int i = 0; i < 4; i++) {
      n = t;
      n.t++;
      n.x += dir[i][0];
      n.y += dir[i][1];
      if (check(n)) {
        dp[n.x][n.y][n.s] = n.t;
        q.push(n);
      }
    }
  }

  return ans;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  while (cin >> n >> m && n && m) {
    board.resize(n);
    int sx = -1, sy = -1;
    FOR(i, 0, n) {
      cin >> board[i];
      FOR(j, 0, m) {
        if (sx != -1) break;
        if (board[i][j] == 'S') sx = i, sy = j;
      }
    }
    memset(dp, 0x3f, sizeof dp);

    int ans = bfs(sx, sy);
    if (ans == INF)
      cout << "-1\n";
    else
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

  return 0;
}