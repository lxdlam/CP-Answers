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
int val[14];
int cnt[38];

map<char, int> ha;
map<int, char> rev;

bool checkRemain() {
  int tmp[38];
  int inCnt = 0;

  for (int i = 1; i <= 37; i++) tmp[i] = cnt[i];

  for (int i = 0; i <= 2; i++) {
    for (int j = 1; j <= 9; j++) {
      int cur = i * 10 + j;

      if (tmp[cur] >= 3) {
        tmp[cur] -= 3;
        inCnt++;
      }

      while (j <= 7 && tmp[cur] && tmp[cur + 1] && tmp[cur + 2]) {
        tmp[cur]--;
        tmp[cur + 1]--;
        tmp[cur + 2]--;
        inCnt++;
      }
    }
  }

  for (int i = 31; i <= 37; i++) {
    if (tmp[i] >= 3) {
      tmp[i] -= 3;
      inCnt++;
    }
  }

  return inCnt == 4;
}

bool check() {
  clr(cnt);

  for (auto it : val) {
    cnt[it]++;
    if (cnt[it] > 4) return false;
  }

  for (int i = 1; i <= 37; i++) {
    if (cnt[i] >= 2) {
      cnt[i] -= 2;
      if (checkRemain()) return true;
      cnt[i] += 2;
    }
  }

  return false;
}

void reg(char ch, int num) {
  ha[ch] = num;
  rev[num] = ch;
}

// Pre-Build Function
inline void build() {
  reg('m', 0);
  reg('s', 1);
  reg('p', 2);
  reg('z', 3);
}

// Actual Solver
inline void solve() {
  string s;
  while (cin >> s) {
    val[0] = s[0] - '0' + ha[s[1]] * 10;

    for (int i = 1; i < 13; i++) {
      cin >> s;
      val[i] = s[0] - '0' + ha[s[1]] * 10;
    }

    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= (i == 3 ? 7 : 9); j++) {
        val[13] = (j + i * 10);

        if (check()) cout << j << rev[i] << '\n';
      }
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC
       << "ms." << endl;
#endif

  return 0;
}