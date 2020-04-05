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
// min exchange
template <typename T>
bool se(T& a, T& b) {
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
const int SIZE = 1e5 + 10;
struct Edge {
  int next, to, w;

  Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE << 1];
int last[SIZE];
int cnt = 0;

void add_edge(int u, int v, int w = 1) {
  E[++cnt].next = last[u];
  E[cnt].to = v;
  E[cnt].w = w;
  last[u] = cnt;
}

int din[SIZE], dout[SIZE];
bool vis[SIZE];
int Dcnt = 0;

void dfs(int idx) {
  if (vis[idx]) return;
  vis[idx] = true;
  din[idx] = ++Dcnt;
  for (int i = last[idx]; i; i = E[i].next) dfs(E[i].to);
  dout[idx] = Dcnt;
}

template <typename T>
class FenTree {
private:
  vector<T> v;
  size_t size;

  inline int lowbit(int k) { return k & -k; }

public:
  void init(size_t size) {
    this->size = size + 1;
    v.clear();
    v.resize(size + 1);
  }

  void update(int pos, T val) {
    while (pos < size) {
      v[pos] += val;
      pos += lowbit(pos);
    }
  }

  T get(int pos) {
    T res = 0;
    while (pos) {
      res += v[pos];
      pos -= lowbit(pos);
    }
    return res;
  }

  T getSeg(int l, int r) { return get(r) - get(l - 1); }
};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n, p;
  readln(n, p);
  int x, y;
  FOR(i, 0, n) {
    readln(x, y);
    add_edge(x, y);
    add_edge(y, x);
  }
  dfs(p);
  FenTree<int> ft;
  ft.init(SIZE);

  FOR(i, 1, n + 1) {
    ft.update(din[i], 1);
    cout << ft.getSeg(din[i], dout[i]) - 1 << " \n"[i == n];
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