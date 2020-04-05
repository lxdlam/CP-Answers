#include <algorithm>
#include <cassert>
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
const int SIZE = 4e5 + 10;  // Number of edges

struct Edge {
  int next, to, w;

  Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE];
int last[SIZE];
int cnt = 0;
int ans[SIZE];
int dp[SIZE];
int deg[SIZE];

void add_edge(int u, int v, int w = 1) {
  E[++cnt].next = last[u];
  E[cnt].to = v;
  E[cnt].w = w;
  last[u] = cnt;
  deg[u]++;
}

void clear() {
  cnt = 0;
  memset(E, 0, sizeof E);
  memset(last, 0, sizeof last);
  memset(deg, 0, sizeof deg);
  memset(dp, 0, sizeof dp);
  memset(ans, 0, sizeof ans);
}

void dfs(int cur, int fa) {
  for (int i = last[cur]; i; i = E[i].next) {
    int v = E[i].to;
    int w = E[i].w;
    if (v == fa) continue;
    dfs(v, cur);
    if (deg[v] == 1)
      dp[cur] += w;
    else
      dp[cur] += min(dp[v], w);
  }
}

void update(int cur, int fa) {
  for (int i = last[cur]; i; i = E[i].next) {
    int v = E[i].to;
    int w = E[i].w;
    if (v == fa) continue;

    // assume the current flow is 1 -> 2
    // now we choose 2 to send flow to 1
    // then first, cancel the flow from 1: cancel = ans[1] - min(dp[2], w)
    // in other words, the reverse process from dfs
    // then we select the possible flow: ans[2] = min(cancel, w)
    ans[v] = dp[v] + min(ans[cur] - min(dp[v], w), w);

    update(v, cur);
  }
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    int n;
    cin >> n;
    int ret = 0;

    clear();

    for (int i = 1; i < n; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      add_edge(x, y, w);
      add_edge(y, x, w);
    }

    int root = 1;

    for (int i = 1; i <= n; i++) {
      if (deg[i] != 1) {
        root = i;
        break;
      }
    }

    dfs(root, -1);
    ans[root] = dp[root];
    update(root, -1);

    for (int i = 1; i <= n; i++) smax(ret, ans[i]);

    cout << ret << '\n';
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