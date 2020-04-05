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
const int MAXN = 260;

int r, c;
int dist[MAXN][MAXN];
int board[MAXN][MAXN];
int dir[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

struct Node {
  int x, y, d;
};

int bfs(int i, int j, vector<Node> v) {
  int ret = 0;
  queue<Node> q;

  for (auto it : v) q.push(it);

  if (i != -1 && j != -1) q.push({i, j, 0});

  memset(dist, -1, sizeof dist);

  while (q.size()) {
    auto t = q.front();
    q.pop();
    if (t.x >= r || t.x < 0 || t.y >= c || t.y < 0) continue;
    if (dist[t.x][t.y] != -1) continue;
    dist[t.x][t.y] = t.d;
    smax(ret, t.d);

    for (int i = 0; i < 4; i++) {
      auto n = t;
      n.x += dir[i][0];
      n.y += dir[i][1];
      n.d++;

      q.push(n);
    }
  }

  return ret;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    cout << "Case #" << kase << ": ";

    memset(board, 0, sizeof board);
    cin >> r >> c;

    queue<Node> q;
    vector<Node> v;

    string s;
    for (int i = 0; i < r; i++) {
      cin >> s;
      for (int j = 0; j < c; j++) {
        if (s[j] == '1') {
          board[i][j] = 1;
          v.pb({i, j, 0});
        }
      }
    }

    int ans = bfs(-1, -1, v);

    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        if (!board[i][j]) smin(ans, bfs(i, j, v));

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