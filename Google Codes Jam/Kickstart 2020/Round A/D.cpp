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
const int SIZE = 2e6 + 10;  // size of the trie;
const int CHARSIZE = 26;
const char START = 'A';

struct Trie {
  int next[SIZE][CHARSIZE];
  int num[SIZE];
  int root;
  int size;
  int ans;

  Trie() { clear(); }

  void clear() {
    memset(next, 0, sizeof(next));
    memset(num, 0, sizeof(num));
    size = ans = 0;
    root = newnode();
  }

  int newnode() {
    for (int i = 0; i < CHARSIZE; i++) next[size][i] = -1;
    num[size++] = 0;
    return size - 1;
  }

  void insert(const string& s) {
    int cur = root;
    for (int i = 0; i < s.size(); i++) {
      if (next[cur][s[i] - START] == -1) next[cur][s[i] - START] = newnode();
      cur = next[cur][s[i] - START];
      num[cur]++;
    }
  }

  // consumed and ans
  pair<int, int> query(int sz, int cur, int len) {
    int con = 0, ans = 0;
    for (int i = 0; i < 26; i++) {
      if (next[cur][i] != -1) {
        auto p = query(sz, next[cur][i], len + 1);
        con += p.first;
        ans += p.second;
      }
    }

    ans += (num[cur] - con) / sz * len;
    con += (num[cur] - con) / sz * sz;
    return {con, ans};
  }

  int query(int sz) { return query(sz, root, 0).second; }
} trie;

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    trie.clear();

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      trie.insert(s);
    }

    cout << "Case #" << kase << ": " << trie.query(K) << '\n';
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
