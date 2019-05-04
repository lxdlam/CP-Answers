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
unordered_map<char, string> ta{
    {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"}, {'4', "0100"},
    {'5', "0101"}, {'6', "0110"}, {'7', "0111"}, {'8', "1000"}, {'9', "1001"},
    {'A', "1010"}, {'B', "1011"}, {'C', "1100"}, {'D', "1101"}, {'E', "1110"},
    {'F', "1111"}, {'a', "1010"}, {'b', "1011"}, {'c', "1100"}, {'d', "1101"},
    {'e', "1110"}, {'f', "1111"}};

const int CHARSIZE = 2;
const char START = '0';
const int SIZE = 1e4 + 10;

struct Trie {
  int next[SIZE][CHARSIZE];
  int num[SIZE];
  int root;
  int size;
  int m, cnt;

  Trie() { init(); }

  void init() {
    memset(next, 0, sizeof(next));
    memset(num, 0, sizeof(num));
    size = 0;
    root = newnode();
    cnt = 0;
  }

  int newnode() {
    for (int i = 0; i < CHARSIZE; i++) next[size][i] = -1;
    num[size++] = 0;
    return size - 1;
  }

  void insert(const string &s, int asc) {
    int cur = root;
    for (int i = 0; i < s.size(); i++) {
      if (next[cur][s[i] - START] == -1) next[cur][s[i] - START] = newnode();
      cur = next[cur][s[i] - START];
    }
    num[cur] = asc;
  }

  void query(const string &s, stringstream &ss, int st) {
    if (st >= s.size() || cnt == m) return;
    int cur = root;
    while (!num[cur]) cur = next[cur][s[st++] - START];
    ss << static_cast<char>(num[cur]);
    cnt++;
    query(s, ss, st);
  }
} trie;

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  tcase() {
    int m, n;
    cin >> m >> n;
    trie.init();
    trie.m = m;
    int asc;
    string token, data;
    while (n--) {
      cin >> asc >> token;
      trie.insert(token, asc);
    }
    stringstream ss, de;
    cin >> data;

    for (auto i : data) de << ta[i];

    data = de.str();
    de.str("");

    int len = data.size() - data.size() % 9;

    for (int i = 0; i < len; i += 9) {
      int cnt = 0;
      FOR(j, 0, 8)
      cnt += data[i + j] == '1';
      if ((cnt & 1) && data[i + 8] == '0') {
        FOR(j, 0, 8)
        de << data[i + j];
      } else if (!(cnt & 1) && data[i + 8] == '1') {
        FOR(j, 0, 8)
        de << data[i + j];
      }
    }

    data = de.str();

    trie.query(data, ss, 0);

    cout << ss.str() << '\n';
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