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
const ll MOD = 1e9 + 7;
const ll PHI = 1000000006;

inline ll fp(ll base, ll expr, ll mod = 1e9 + 7) {
  ll ans = 1;
  base %= mod;
  while (expr) {
    if (expr & 1LL) ans = (ans * base) % mod;
    base = (base * base) % mod;
    expr >>= 1LL;
  }
  return ans % mod;
}

struct LB {
  using ll = long long;
  int MaxL;

  vector<ll> data;

  LB(int size = 60) {
    MaxL = size;
    data.resize(size);
  }

  void insert(ll t) {
    for (int j = MaxL; j >= 0; j--) {
      if (!(t & (1LL << j))) continue;

      if (data[j])
        t ^= data[j];
      else {
        for (int k = 0; k < j; k++)
          if (t & (1LL << k)) t ^= data[k];

        for (int k = j + 1; k <= MaxL; k++)
          if (data[k] & (1LL << j)) data[k] ^= t;

        data[j] = t;

        return;
      }
    }
  }

  void merge(const LB &l) {
    for (int i = 0; i <= MaxL; i++) insert(l.data[i]);
  }

  ll queryMax() {
    ll ans = 0;
    for (auto i : data) ans ^= i;
    return ans;
  }

  int rank() {
    int ans = 0;
    for (auto i : data)
      if (i) ans++;
    return ans;
  }
};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  string n;
  ll a, b, c, d, e;
  ll k, x1;
  cin >> n >> x1;
  readln(a, b, c, d, e);
  cin >> k;
  ll m = 0;

  FOR(i, 0, n.size()) {
    m = m * 10 + (n[i] - '0');
    if (m > k) {
      m = -1;
      break;
    }
  }

  if (m == -1) {
    m = 0;
    FOR(i, 0, n.size()) {
      m = m * 10 + (n[i] - '0');
      m %= PHI;
    }
    if (m < PHI) m += PHI;
  }

  auto f = [a, b, c, d, e, k](ll num) {
    ll ans = (a % k * fp(num, 4, k)) % k;
    ans = (ans + (b % k * fp(num, 3, k)) % k) % k;
    ans = (ans + (c % k * fp(num, 2, k)) % k) % k;
    ans = (ans + (d % k * num) % k) % k;
    ans = (ans + (e - 1 + k) % k) % k;
    return ans + 1;
  };

  int p = 1;
  while ((1 << p) < k) p++;

  LB lb(p);

  lb.insert(x1);
  set<ll> vis;
  vis.insert(x1);

  for (int i = 1; i < min(m, k + 1); i++) {
    x1 = f(x1);
    if (vis.count(x1)) break;
    lb.insert(x1);
    vis.insert(x1);
  }

  ll y = m - lb.rank();
  if (y < 0) y += PHI;

  cout << (fp(2, m) - fp(2, y) + MOD) % MOD << '\n';
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