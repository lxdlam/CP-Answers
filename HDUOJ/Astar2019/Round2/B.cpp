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
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof(x))
#define infty(x) memset((x), 0x3f, sizeof(x))
#define tcase() \
  int T;        \
  cin >> T;     \
  FOR(kase, 1, T + 1)

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
int cnt[26];
int ans[60];

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    int n, m;
    cin >> n >> m;

    clr(ans);

    map<int, set<int>> pos;

    map<char, set<int>> ma;
    set<int> used;

    string s, t;

    cin >> s >> t;

    for (int i = 0; i < m; i++) {
      ma[t[i]].insert(i);
    }

    for (int i = 0; i < m; i++) {
      for (const auto &it : ma[s[i]]) {
        pos[i].insert(it);
      }
    }

    for (int i = 1; i < n; i++) {
      cin >> s >> t;
      ma.clear();
      for (int i = 0; i < m; i++) {
        ma[t[i]].insert(i);
      }

      for (int i = 0; i < m; i++) {
        vector<int> rm;
        for (const auto &it : pos[i]) {
          if (!ma[s[i]].count(it)) {
            rm.push_back(it);
          }
        }

        for (const auto &it : rm) pos[i].erase(it);
      }
    }

    // for (int i = 0; i < m; i++) cout << pos[i].size() << " \n"[i == m - 1];

    bool flag = true;

    for (int i = 0; i < m; i++) {
      if (pos[i].size() == 0) {
        flag = false;
        break;
      }

      for (const auto &it : pos[i]) {
        if (used.count(it + 1)) continue;
        ans[i] = it + 1;
        used.insert(it + 1);
        break;
      }

      if (ans[i] == 0) {
        flag = false;
        break;
      }
    }

    if (flag) {
      for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
      }
    } else {
      cout << "-1\n";
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC
       << "ms." << endl;
#endif

  return 0;
}