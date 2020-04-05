#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define TemplateVersion "3.4.0"
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
#define all(x) (x).begin(), (x).end()
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
const int SIZE = 1e8 + 10;
const int MAGIC = 17729270;  // Don't ask me why

const int A[3][3] = {{1, 2, 2}, {-2, -1, -2}, {2, 2, 3}};

const int B[3][3] = {{-1, -2, -2}, {2, 1, 2}, {2, 2, 3}};

const int C[3][3] = {{1, 2, 2}, {2, 1, 2}, {2, 2, 3}};

struct Triple {
  int x, y, z;

  Triple() : x(0), y(0), z(0){};

  Triple(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

  Triple(const Triple& t) : x(t.x), y(t.y), z(t.z) {}

  bool operator==(const Triple& t) { return x == t.x && y == t.y && z == t.z; }
  bool operator!=(const Triple& t) { return !(*this == t); }
};

Triple seeds[] = {{2, 5, 6}, {1, 1, 3}, {3, 3, 5}, {11, 14, 18}};

Triple trans(const Triple& t, const int mat[3][3]) {
  return Triple(t.x * mat[0][0] + t.y * mat[1][0] + t.z * mat[2][0],
                t.x * mat[0][1] + t.y * mat[1][1] + t.z * mat[2][1],
                t.x * mat[0][2] + t.y * mat[1][2] + t.z * mat[2][2]);
}

char* cnt;

void work(int n) {
  stack<Triple> s;

  for (auto i : seeds) {
    if (n >= i.z) s.push(i);

    while (s.size()) {
      auto t = s.top();
      s.pop();
      *(cnt + t.z) += 1;
      auto a = trans(t, A), b = trans(t, B), c = trans(t, C);
      // cout << t.x << ' ' << t.y << ' ' << t.z << '\n';
      if (a.z <= n) s.push(a);
      if (a.x != b.y && b.z <= n) s.push(b);
      if (c.z <= n) s.push(c);
    }
  }
}

int idx[MAGIC], val[MAGIC];

// Pre-Build Function
inline void build() {
  cnt = new char[SIZE];
  work(100000000);
  int back = 0;
  int cur = 1;
  FOR(i, 3, (int)(1e8 + 1)) {
    if (cnt[i]) {
      back += cnt[i];
      idx[cur] = i;
      val[cur++] = back;
    }
  }
  delete[] cnt;
}

// Actual Solver
inline void solve() {
  tcase() {
    int n;
    cin >> n;
    if (n == 1 || n == 2)
      cout << "0\n";
    else {
      auto p = upper_bound(idx, idx + MAGIC, n) - idx - 1;
      cout << val[p] << '\n';
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

  return 0;
}