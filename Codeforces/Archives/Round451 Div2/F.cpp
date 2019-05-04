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
const int SIZE = 1e6 + 10LL;
const int MOD = 1e9 + 7;

ll h[SIZE];
ll base[SIZE] = {1};

string s;
int len;

ll fp(ll base, ll expr, ll mod = 1e9 + 7) {
  ll ans = 1;
  base %= mod;
  while (expr) {
    if (expr & 1LL) ans = (ans * base) % mod;
    base = (base * base) % mod;
    expr >>= 1LL;
  }
  return ans % mod;
}

ll get(int l, int r) {
  return (h[r] - h[l - 1] * base[r - l + 1] % MOD + MOD) % MOD;
}

inline bool check(int l, int r) {
  if (s[0] == 0 && l != 0) return false;
  if (s[l + 1] == '0' && r - l != 1) return false;
  if (s[r + 1] == '0' && len - r != 2) return false;

  int t = max(l + 1, r - l), tt = len - r - 1;
  if (t + 1 != tt && t != tt) return false;

  return (get(1, l + 1) + get(l + 2, r + 1)) % MOD == get(r + 2, len);
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  cin >> s;
  len = s.size();

  for (int i = 1; i <= len; i++) base[i] = (base[i - 1] * 10) % MOD;

  for (int i = 1; i <= len; i++)
    h[i] = (h[i - 1] * 10 + s[i - 1] - '0' + MOD) % MOD;

  int l, r;
  for (int i = 0; i < len; i++) {
    l = i;

    r = len - l - 3;
    if (check(l, r)) break;

    r = len - l - 2;
    if (check(l, r)) break;

    r = len - (len - l) / 2 - 1;
    if (check(l, r)) break;
  }

  for (int i = 0; i < len; i++) {
    cout << s[i];
    if (i == l)
      cout << '+';
    else if (i == r)
      cout << '=';
  }

  cout << '\n';
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