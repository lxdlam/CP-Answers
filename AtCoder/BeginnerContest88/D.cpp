#include <bits/stdc++.h>

using namespace std;

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
#define FOR(_i, _begin, _end) \
  for (auto _i = _begin - (_begin > _end); _i != _end - (_begin > _end); _i += 1 - 2 * (_begin > _end))
#define FORE(_i, _c) for (auto _i : _c)
#define FORER(_i, _c) for (auto& _i : _c)
#else
#define FOR(_i, _begin, _end) \
  for (__typeof(_end) _i = _begin - (_begin > _end); _i != _end - (_begin > _end); _i += 1 - 2 * (_begin > _end))
#define FORE(_i, _c)
#define FORER(_i, _c)
#define nullptr NULL
#endif
#if __cplusplus >= 201402L
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
//====================END=====================

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

// Constants here
const int SIZE = 50 + 5;
int h, w;
struct Node {
  int x, y, step;

  Node() : x(0), y(0), step(0) {}

  Node(int _x, int _y) : x(_x), y(_y), step(0) {}
};
char grid[SIZE][SIZE] = {0};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool check(Node n) {
  if (n.x < 0 || n.x >= h) return false;
  if (n.y < 0 || n.y >= w) return false;
  if (grid[n.x][n.y] == '#') return false;
  return true;
}

int bfs() {
  queue<Node> q;
  Node s(0, 0);
  Node t, n;
  grid[s.x][s.y] = '#';
  q.push(s);
  while (q.size()) {
    t = q.front();
    q.pop();
    if (t.x == h - 1 && t.y == w - 1) return t.step;
    FOR(i, 0, 4) {
      n = t;
      n.x += dir[i][0];
      n.y += dir[i][1];
      if (!check(n)) continue;
      grid[n.x][n.y] = '#';
      n.step++;
      q.push(n);
    }
  }
  return -1;
}

// Pre-Build Function
void build() {}

// Actual Solver
void solve() {
  readln(h, w);
  cin.get();
  int cnt = 0;  // number of #
  int len = 0;
  FOR(i, 0, h) {
    FOR(j, 0, w) {
      grid[i][j] = cin.get();
      if (grid[i][j] == '#') cnt++;
    }
    cin.get();
  }
  len = bfs();
  if (len == -1)
    cout << -1 << endl;
  else
    cout << h * w - 1 - cnt - len << endl;
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
  cerr << "Elapsed Time: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

  return 0;
}