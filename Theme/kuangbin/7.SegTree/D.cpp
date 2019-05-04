#include <algorithm>
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
const int SIZE = 2e4 + 10;

ll sum[SIZE << 2], flag[SIZE << 2];
map<int, int> h;
vector<pii> v;

void pushup(int pos) { sum[pos] = sum[pos << 1] + sum[pos << 1 | 1]; }

void pushdown(int pos, int lcnt, int rcnt) {
  if (flag[pos]) {
    flag[pos << 1] = flag[pos];
    flag[pos << 1 | 1] = flag[pos];
    sum[pos << 1] = flag[pos] * lcnt;
    sum[pos << 1 | 1] = flag[pos] * rcnt;

    flag[pos] = 0;
  }
}

void update(int ul, int ur, ll val, int l, int r, int cur) {
  if (ul <= l && r <= ur) {
    sum[cur] = val * (r - l + 1);
    flag[cur] = val;
    return;
  }

  int m = ((r - l) >> 1) + l;
  pushdown(cur, m - l + 1, r - m);

  if (ul <= m) update(ul, ur, val, l, m, cur << 1);
  if (ur > m) update(ul, ur, val, m + 1, r, cur << 1 | 1);
  pushup(cur);
}

ll query(int ql, int qr, int l, int r, int cur) {
  if (ql <= l && r <= qr) return sum[cur];

  int m = ((r - l) >> 1) + l;
  pushdown(cur, m - l + 1, r - m);

  ll ans = 0;
  if (ql <= m) ans += query(ql, qr, l, m, cur << 1);
  if (qr > m) ans += query(ql, qr, m + 1, r, cur << 1 | 1);
  return ans;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n;

    memset(sum, 0, sizeof(sum));
    memset(flag, 0, sizeof(flag));
    v.clear();
    h.clear();

    set<int> p;
    int l, r;
    FOR(i, 0, n) {
      cin >> l >> r;
      p.insert(l);
      p.insert(r);
      v.push_back(mp(l, r));
    }

    k = p.size();

    int cnt = 1;
    for (set<int>::iterator it = p.begin(); it != p.end(); it++) h[*it] = cnt++;

    for (int i = 0; i < n; i++)
      update(h[v[i].first], h[v[i].second], i + 1, 1, k, 1);

    si ans;
    for (int i = 1; i <= k; i++) ans.insert(query(i, i, 1, k, 1));

    cout << ans.size() << endl;
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