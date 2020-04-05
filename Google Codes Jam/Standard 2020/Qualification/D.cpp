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
struct Data {
  deque<int> bits;
  int ask_count;
  int next;
  int size;
  int sp, dp;

  Data(size_t n) : bits(n), size(n), sp(-1), dp(-1), next(1), ask_count(0) {}

  void reverse() { std::reverse(all(bits)); }

  void flip() {
    for (auto&& bit : bits) {
      bit = !bit;
    }
  }

  int ask_one(int p) {
    cout << p << endl;
    string s;
    cin >> s;
    assert(s[0] != 'N');

    ask_count++;
    return s[0] - '0';
  }

  void ask_pair() {
    bits[next - 1] = ask_one(next);
    bits[size - next] = ask_one(size - next + 1);

    if (bits[next - 1] == bits[size - next] && sp == -1) {
      sp = next - 1;
    } else if (bits[next - 1] != bits[size - next] && dp == -1) {
      dp = next - 1;
    }

    next++;
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << bits[i];
    }

    cout << endl;

    string s;
    cin >> s;

    assert(s[0] == 'Y');
  }

  void adjust() {
    int used = 0;
    int status = 0b1111;

    if (sp != -1) {
      int cur = ask_one(sp + 1);

      if (cur == bits[sp]) {
        status &= 0b0101;
      } else {
        status &= 0b1010;
      }

      used++;
    }

    if (dp != -1) {
      int cur = ask_one(dp + 1);

      if (cur == bits[dp]) {
        status &= 0b0011;
      } else {
        status &= 0b1100;
      }

      used++;
    }

    if (status & 1) {
      // Do not change
    } else if (status & (1 << 3)) {
      flip();
    } else if (status & (1 << 2)) {
      reverse();
    } else if (status & (1 << 1)) {
      flip();
      reverse();
    }

    if (used != 2) {
      ask_one(1);  // just waste one chance
    }
  }

  void advance() {
    if (ask_count && ask_count % 10 == 0) {
      adjust();
    } else {
      ask_pair();
    }
  }

  void run() {
    while (next * 2 <= size) {
      advance();
    }

    print();
  }
};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int T, B;
  cin >> T >> B;

  FOR(i, 0, T) { Data(B).run(); }
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