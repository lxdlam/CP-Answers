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
const ll MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;

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

ll inv(ll a, ll mod = 1e9 + 7) { return fp(a, mod - 2); }

ll psf(ll n, ll k) {
  ll ans = ((n % MOD) * ((fp(n, k) - 1) % MOD)) % MOD;
  return (ans % MOD * inv(n - 1) % MOD) % MOD;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int T;
  cin >> T;
  FOR(i, 1, T + 1) {
    cout << "Case #" << i << ": ";
    ll n, k, x1, y1, c, d, e1, e2, f, a;
    ll t1, t2;
    readln(n, k, x1, y1, c, d, e1, e2, f);
    ll ans = 0;
    ll ps = 0;
    ll cur;
    FOR(i, 1, n + 1) {
      cur = ((x1 % f) + (y1 % f)) % f;
      cur = ((n - i + 1) % MOD * cur % MOD) % MOD;

      if (i == 1)
        ps = (1 * k % MOD) % MOD;
      else
        ps = ((ps % MOD) + psf(i, k) % MOD) % MOD;

      ans = ((ans % MOD) + (cur * ps) % MOD) % MOD;

      t1 = (((c % f) * (x1 % f)) % f + ((d % f) * (y1 % f)) % f + e1 % f) % f;
      t2 = (((c % f) * (y1 % f)) % f + ((d % f) * (x1 % f)) % f + e2 % f) % f;
      x1 = t1, y1 = t2;
    }

    cout << ans << endl;
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