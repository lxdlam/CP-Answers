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
const int SIZE = 1e6 + 10;
const int MSIZE = 1333331;
const ll MOD = 1e9 + 7;
const ll INV2 = 500000004;
const ll INV6 = 166666668;

struct Hash {
  int h[MSIZE + 10], cnt, nxt[100010];
  ll st[100010], S[100010];
  void push(ll k, ll v) {
    int key = k % MSIZE;
    for (int i = h[key]; i; i = nxt[i]) {
      if (S[i] == k) return;
    }
    ++cnt;
    nxt[cnt] = h[key];
    h[key] = cnt;
    S[cnt] = k;
    st[cnt] = v;
  }
  ll ask(ll k) {
    int key = k % MSIZE;
    for (int i = h[key]; i; i = nxt[i]) {
      if (S[i] == k) return st[i];
    }
    return -1;
  }
} memo;

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

ll phi[SIZE], sum[SIZE];

inline ll Add(ll a, ll b) { return (a + b) % MOD; }

inline ll Sub(ll a, ll b) { return (a - b) % MOD + MOD; }

inline ll Mul(ll a, ll b) { return a * b % MOD; }

inline ll Div(ll a, ll b) {
  if (b == 2) return Mul(a, INV2);
  if (b == 6) return Mul(a, INV6);
  return a * fp(b, MOD - 2, MOD) % MOD;
}

void getPhi() {
  for (int i = 1; i < SIZE; i++) {
    phi[i] = i;
  }
  for (int i = 2; i < SIZE; i++) {
    if (phi[i] == i) {
      for (int j = i; j < SIZE; j += i) {
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }

  sum[1] = 1;
  for (int i = 2; i <= SIZE; i++) {
    sum[i] = Add(Mul(i, phi[i]), sum[i - 1]);
  }
}

ll query(ll n) {
  if (n < SIZE) return sum[n];
  ll la, A = 0;
  ll tmp = memo.ask(n);
  if (tmp != -1) {
    return tmp;
  }
  for (ll i = 2; i <= n; i = la + 1) {
    ll now = n / i;
    la = n / now;
    ll B = Div(Mul(la + i, la - i + 1), 2LL);
    B = Mul(B, query(now));
    A = Add(A, B);
  }
  A = Sub(Div(Mul(n, Mul(n + 1, 2 * n + 1)), 6LL), A);
  memo.push(n, A);
  return A;
}

inline void build() {}

// Actual Solver
inline void solve() {
  getPhi();

  int T, a, b, t;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d%d%d", &t, &a, &b);
    printf("%lld\n", Div(Sub(query(t), 1), 2));
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