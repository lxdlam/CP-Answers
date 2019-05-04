#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.1.1"
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
#define us unordered_set
#define um unordered_map
// Swap max/min
template <typename T>
bool smax(T &a, const T &b) {
  if (a >= b) return false;
  a = b;
  return true;
}
template <typename T>
bool smin(T &a, const T &b) {
  if (a <= b) return false;
  a = b;
  return true;
}
// ceil divide
template <typename T>
T cd(T a, T b) {
  return (a + b - 1) / b;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
unordered_set<int> s;
int dfs(int p, int len) {
  int k = 0;
  if (s.count(p + len - 1)) smax(k, dfs(p + len - 1, len));
  if (s.count(p + len)) smax(k, dfs(p + len, len));
  if (s.count(p + len + 1)) smax(k, dfs(p + len + 1, len));
  return k + 1;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n;
  cin >> n;
  string t;
  vi l;
  int mlen = 0;
  int c = 0;
  FOR(i, 0, n) {
    cin >> t;
    l.pb(t.size());
    c += t.size() + 1;
    smax(mlen, (int)t.size());
  }
  int ans = 0, width = mlen;
  FOR(i, mlen, c + 1) {
    if (ans * i >= c) break;
    s.clear();
    int ret = 0, p = 1;
    for (auto len : l) {
      if (ret + len <= i * p) s.insert(ret);
      if (ret % i == 0 && ret != 0)
        p++;
      else if (ret + len > i * p) {
        ret = i * p;
        p++;
      }
      ret += len;
      if (ret % i) ret += 1;
    }

    s.erase(0);

    for (auto k : s)
      if (smax(ans, dfs(k, i))) width = i;
  }

  writeln(width, ans);
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