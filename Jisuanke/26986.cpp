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
const int CHARSIZE = 26;
const char START = 'a';
const int SIZE = 1e6 + 100;

int nxt[SIZE][CHARSIZE];
ll num[SIZE];
int root;
int sze;

int newnode();

void init() {
  memset(nxt, 0, sizeof(nxt));
  memset(num, 0, sizeof(num));
  sze = 0;
  root = newnode();
}

int newnode() {
  for (int i = 0; i < CHARSIZE; i++) nxt[sze][i] = -1;
  num[sze++] = 0;
  return sze - 1;
}

void insert(const string& s, const ll& val) {
  int cur = root;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (nxt[cur][s[i] - START] == -1) nxt[cur][s[i] - START] = newnode();
    cur = nxt[cur][s[i] - START];
    num[cur] += val;
  }
}

ll query(const string& s) {
  int cur = root;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (nxt[cur][s[i] - START] == -1) return 0;
    cur = nxt[cur][s[i] - START];
  }
  return num[cur];
}

ll dquery(const string& s) {
  int cur = root;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (nxt[cur][s[i] - START] == -1) return 0;
    cur = nxt[cur][s[i] - START];
  }
  ll ans = num[cur];
  for (int i = 0; i < CHARSIZE; i++)
    if (nxt[cur][i]) ans -= num[nxt[cur][i]];
  return ans;
}

void transfer(const string& s, const string& k, const ll& val) {
  int st = root, kt = root;
  for (int i = s.size() - 1; i >= 1; i--) {
    st = nxt[st][s[i] - START];
    num[st] -= val;
  }
  // ???????????????????????????????????????????????????????????
  int tmp = nxt[st][s[0] - START];
  nxt[st][s[0] - START] = -1;
  for (int i = k.size() - 1; i >= 1; i--) {
    if (nxt[kt][k[i] - START] == -1) nxt[kt][k[i] - START] = newnode();
    kt = nxt[kt][k[i] - START];
    num[kt] += val;
  }
  nxt[kt][k[0] - START] = tmp;
}

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int T;
  string op, s, k;
  ll t, n;
  cin >> T;
  while (T--) {
    init();
    cin >> n;
    while (n--) {
      cin >> op;
      if (op == "insert") {
        cin >> s >> t;
        insert(s, t);
      } else if (op == "delete") {
        cin >> s;
        ll val = dquery(s);
        if (!val) {
          cout << "Empty" << endl;
          continue;
        }
        insert(s, -val);
      } else if (op == "update") {
        cin >> s >> k;
        ll val = query(s);
        if (!val)
          cout << "Empty" << endl;
        else if (query(k))
          cout << "Conflict" << endl;
        else
          transfer(s, k, val);
      } else {
        cin >> s;
        cout << query(s) << endl;
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
  cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

  return 0;
}