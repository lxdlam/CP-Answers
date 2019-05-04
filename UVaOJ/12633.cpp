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
#define ALL(x) (x).begin(), (x).end()
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
namespace NTT {
typedef long long ll;
typedef std::vector<ll> vll;

/*
 * P = Rx2^K+1, G is pr
 * Three recommend choices:
 * p = 2281701377, r = 17, g = 3, k = 27
 * p = 1004535809, r = 479, g = 3, k = 21
 * p = 998244353, r = 119, g = 3, k = 23
 * For more, see NTT_table.md
 */
const int P = 998244353, R = 119, G = 3, K = 23;

ll fp(ll base, ll expr, ll mod = P) {
  ll ans = 1;
  base %= mod;
  while (expr) {
    if (expr & 1LL) ans = (ans * base) % mod;
    base = (base * base) % mod;
    expr >>= 1LL;
  }
  return ans % mod;
}

ll add(ll n, ll m) {
  n += m;
  if (n >= P) n -= P;
  return n;
}

ll sub(ll n, ll m) {
  n -= m;
  if (n < 0) n += P;
  return n;
}

ll mul(ll n, ll m) {
  n = (n * m) % P;
  return n;
}

ll div(ll n, ll m) {
  ll inv = fp(m, P - 2);
  n = (n * inv) % P;
  return n;
}

void transform(int n, vll &x, bool idft = false) {
  for (int i = 0, j = 0; i != n; ++i) {
    if (i > j) swap(x[i], x[j]);
    for (int l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
  }

  for (int i = 2; i <= n; i <<= 1) {
    int m = i >> 1;
    ll eps = fp(G, idft ? (P - 1) / i : P - 1 - (P - 1) / i, P);
    for (int j = 0; j < n; j += i) {
      ll t = 1;
      for (int k = 0; k != m; ++k) {
        ll z = (x[j + m + k] * t) % P;
        x[j + m + k] = (x[j + k] - z + P) % P;
        x[j + k] = (x[j + k] + z) % P;
        t = (t * eps) % P;
      }
    }
  }

  if (idft) {
    ll inv = fp(n, P - 2, P);
    for (int i = 0; i < n; i++) x[i] = x[i] * inv % P;
  }
}
}  // namespace NTT

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int T;
  cin >> T;
  FOR(i, 1, T + 1) {
    cout << "Case " << i << ": ";
    int r, c, q;
    readln(r, c, q);
    ll lr, lc, ans = 0;
    vi rs, cs, ds;
    while (q--) {
      readln(lr, lc);
      rs.pb(lr);
      cs.pb(lc);
      ds.pb(lr - lc + c);
    }

    sort(ALL(rs));
    sort(ALL(cs));
    sort(ALL(ds));
    rs.resize(unique(ALL(rs)) - rs.begin());
    cs.resize(unique(ALL(cs)) - cs.begin());
    ds.resize(unique(ALL(ds)) - ds.begin());

    ans += rs.size() * c;
    ans += cs.size() * r;
    int tr = r, tc = c;
    se(tr, tc);
    for (auto i : ds) {
      if (tr <= i && i <= tc)
        ans += tr;
      else {
        if (i < tr)
          ans += i;
        else
          ans += tr + tc - i;
      }
    }

    ans -= rs.size() * cs.size();

    for (auto i : rs) {
      auto tl = lower_bound(ALL(ds), i);
      auto tr = upper_bound(ALL(ds), i + c - 1);
      ans -= tr - tl;
    }

    for (auto i : cs) {
      auto tl = lower_bound(ALL(ds), c - i + 1);
      auto tr = upper_bound(ALL(ds), r + c - i);
      ans -= tr - tl;
    }

    int p = 1;
    while (p < r + c) p <<= 1;

    vll f(p), g(p);

    for (auto i : rs) f[i]++;
    for (auto i : cs) g[c - i]++;

    NTT::transform(p, f);
    NTT::transform(p, g);

    for (int i = 0; i < p; i++) f[i] = NTT::mul(f[i], g[i]);

    NTT::transform(p, f, true);

    for (auto i : ds) ans += f[i];

    cout << 1LL * r * c - ans << '\n';
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