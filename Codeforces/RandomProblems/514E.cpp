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
#define clr(x) memset((x), 0, sizeof(x))
#define infty(x) memset((x), 0x3f, sizeof(x))
#define tcase() \
  int T;        \
  cin >> T;     \
  FOR(kase, 1, T + 1)

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
const int SIZE = 110;
const int MOD = 1e9 + 7;

int cnt[SIZE];
ll vec[SIZE], tmp[SIZE], memo[SIZE];
ll mat[SIZE][SIZE], temp[SIZE][SIZE];

ll f(int idx) {
  if (idx == 0)
    return 1;
  else if (memo[idx] == INFLL) {
    memo[idx] = 0;
    for (int i = 1; i <= 100 && idx - i >= 0; i++) {
      memo[idx] = (memo[idx] + f(idx - i) * cnt[i]) % MOD;
    }
  }

  return memo[idx];
}

void mul() {
  for (int i = 1; i <= 101; i++) {
    for (int k = 1; k <= 101; k++) {
      auto t = mat[i][k] % MOD;
      for (int j = 1; j <= 101; j++) temp[i][j] = (temp[i][j] + t * mat[k][j]) % MOD;
    }
  }

  for (int i = 1; i <= 101; i++) {
    for (int j = 1; j <= 101; j++) {
      mat[i][j] = temp[i][j];
      temp[i][j] = 0;
    }
  }
}

void work(int x) {
  while (x) {
    if (x & 1) {
      for (int i = 1; i <= 101; i++) {
        for (int j = 1; j <= 101; j++) {
          tmp[i] = (tmp[i] + vec[j] * mat[j][i]) % MOD;
        }
      }

      for (int i = 1; i <= 101; i++) {
        vec[i] = tmp[i];
        tmp[i] = 0;
      }
    }
    mul();
    x >>= 1;
  }
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n, x, t;
  ll ans = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> t;
    cnt[t]++;
  }

  infty(memo);

  if (x <= 100) {
    for (int i = 0; i <= x; i++) {
      ans = (ans + f(i)) % MOD;
    }

    cout << ans << '\n';
  } else {
    vec[101] = 1;

    for (int i = 1; i <= 100; i++) {
      vec[i] = f(i) % MOD;
      vec[101] = (vec[101] + f(i)) % MOD;

      mat[i + 1][i] = 1;
      mat[i][100] = cnt[100 - i + 1];
      mat[i][101] = cnt[100 - i + 1];
    }

    mat[101][100] = 0;
    mat[101][101] = 1;

    work(x - 100);

    cout << vec[101] << '\n';
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