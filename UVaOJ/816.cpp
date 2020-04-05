#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.0"
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
//====================END=====================

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;

// Constants here
const int SIZE = 9 + 4;
bool vis[SIZE][SIZE][SIZE];
// current, direction
int dir[4][3][2] = {
    {{0, -1}, {0, 1}, {-1, 0}}, {{0, 1}, {0, -1}, {1, 0}}, {{-1, 0}, {1, 0}, {0, 1}}, {{1, 0}, {-1, 0}, {0, -1}}};
int ava[3] = {1, 2, 4};  // L R F
int board[SIZE][SIZE][SIZE];
map<char, int> m;
int sx, sy, ex, ey;
char sd;

struct Node {
  int x, y;
  int d;
  queue<pii> step;

  Node() : x(0), y(0), d(0) {}

  Node(int _x, int _y, int _d) : x(_x), y(_y), d(_d) { step.push(mp(_x, _y)); }
};

int check(Node n) {
  if (n.x > 9 || n.x <= 0) return false;
  if (n.y > 9 || n.y <= 0) return false;
  return !vis[n.x][n.y][n.d];
}

int newdir(int cur, int to) {
  if (to == 2) return cur;
  if (cur == 0) {
    if (to == 0) return m['W'];
    return m['E'];
  }
  if (cur == 1) {
    if (to == 0) return m['E'];
    return m['W'];
  }
  if (cur == 2) {
    if (to == 0) return m['N'];
    return m['S'];
  }
  if (cur == 3) {
    if (to == 0) return m['S'];
    return m['N'];
  }
  return -1;
}

queue<pii> bfs() {
  Node s(sx, sy, m[sd]);
  Node t, n;
  queue<Node> q;
  q.push(s);

  while (q.size()) {
    t = q.front();
    q.pop();
    debug(t.x, t.y, t.d);
    if (t.x == ex && t.y == ey && t.step.size() != 1) return t.step;

    FOR(i, 0, 3) {
      n = t;
      if (!(board[n.x][n.y][n.d] & ava[i])) continue;
      debug(ava[i]);
      n.x += dir[n.d][i][0];
      n.y += dir[n.d][i][1];
      n.d = newdir(n.d, i);
      if (!check(n)) continue;
      n.step.push(mp(n.x, n.y));
      vis[n.x][n.y][n.d] = true;
      q.push(n);
    }
  }

  queue<pii> em;
  return em;
}

// Pre-Build Function
void build() {
  m['N'] = 0;
  m['S'] = 1;
  m['E'] = 2;
  m['W'] = 3;
}

// Actual Solver
void solve() {
  string label;
  while (cin >> label && label != "END") {
    cout << label << endl;
    int x, y;
    string des;
    readln(sx, sy, sd, ex, ey);
    memset(vis, false, sizeof(vis));
    memset(board, 0, sizeof(board));
    while (cin >> x && x) {
      cin >> y;
      while (cin >> des && des[0] != '*') {
        int d = m[des[0]];
        for (int i = 1; i < des.size(); i++) {
          if (des[i] == 'L')
            board[x][y][d] |= ava[0];
          else if (des[i] == 'R')
            board[x][y][d] |= ava[1];
          else if (des[i] == 'F')
            board[x][y][d] |= ava[2];
        }
      }
    }
    if (!board[sx][sy][m[sd]]) board[sx][sy][m[sd]] = 4;
    queue<pii> q = bfs();
    if (q.empty())
      cout << "  No Solution Possible" << endl;
    else {
      while (q.size()) {
        cout << "  ";
        FOR(i, 0, 10) {
          if (q.empty()) break;
          cout << "(" << q.front().first << "," << q.front().second << ")";
          q.pop();
          if (i != 9 && q.size()) cout << " ";
        }
        cout << endl;
      }
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

  return 0;
}