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
const int TEAMS = 5010;
const int PROBS = 20;

// negative means not solved
// else is solved
int sub_count[TEAMS][PROBS];

// total penalty, 0 means not solved
int penalty[TEAMS][PROBS];

map<string, int> memo;
map<int, string> rev;
int cnt = 0;
int maxLen = 0;
int probs;

int addTeam(const string& name) {
  if (!memo.count(name)) {
    maxLen = max((int)name.size(), maxLen);
    memo[name] = cnt;
    rev[cnt++] = name;
  }

  return memo[name];
}

inline int num(char ch) { return ch - '0'; }

void parse_submission(const string& s) {
  stringstream ss(s);
  char trans[50];

  ss >> trans;
  int pena = num(trans[1]) * 60 + num(trans[3]) * 10 + num(trans[4]);

  ss >> trans;
  int prob = trans[0] - 'A', team;

  ss >> trans;
  if (trans[0] == 'A') {
    stringstream tmp;
    while (ss >> trans) tmp << trans << ' ';
    team = addTeam(tmp.str());
    if (penalty[team][prob] == 0) {
      sub_count[team][prob] = 1 + abs(sub_count[team][prob]);
      penalty[team][prob] = (sub_count[team][prob] - 1) * 20 + pena;
    }
  } else if (trans[0] == 'C') {
    return;
  } else if (trans[0] == 'W' || trans[0] == 'R' || trans[0] == 'P') {
    ss >> trans;
    stringstream tmp;
    while (ss >> trans) tmp << trans << ' ';
    team = addTeam(tmp.str());
    if (penalty[team][prob] == 0) {
      sub_count[team][prob] = -1 - abs(sub_count[team][prob]);
    }
  } else if (trans[0] == 'T' || trans[0] == 'M' || trans[0] == 'O') {
    ss >> trans >> trans;
    stringstream tmp;
    while (ss >> trans) tmp << trans << ' ';
    team = addTeam(tmp.str());
    if (penalty[team][prob] == 0) {
      sub_count[team][prob] = -1 - abs(sub_count[team][prob]);
    }
  }
}

struct Result {
  int team;
  int problems;
  int pena;

  Result(int t) {
    team = t;
    problems = pena = 0;
    for (int i = 0; i < probs; i++) {
      if (sub_count[team][i] > 0) {
        problems++;
        pena += penalty[team][i];
      }
    }
  }

  bool operator<(const Result& r) const {
    if (problems == r.problems && pena == r.pena)
      return lexicographical_compare(all(rev[team]), all(rev[r.team]));
    else if (problems == r.problems)
      return pena < r.pena;
    return problems > r.problems;
  }

  bool operator==(const Result& r) const { return problems == r.problems && pena == r.pena; }

  void print(int rk) const {
    cout << setw(4) << rk << "  ";
    int len = rev[team].size();
    for (int i = 0; i < maxLen - len; i++) cout << ' ';
    cout << rev[team] << ' ';

    cout << setw(6) << problems << "  ";
    cout << setw(7) << pena;

    for (int i = 0; i < probs; i++) {
      if (sub_count[team][i] > 1) {
        cout << "   +" << sub_count[team][i] - 1;
      } else if (sub_count[team][i] == 1) {
        cout << "    +";
      } else if (sub_count[team][i] < 0) {
        cout << "   -" << -sub_count[team][i];
      } else {
        cout << "     ";
      }
    }
  }
};

void print_header() {
  cout << "Rank  Who";

  for (int i = 3; i < maxLen; i++) cout << ' ';
  cout << " Solved  Penalty";

  for (int i = 0; i < probs; i++) {
    for (int i = 0; i < 4; i++) cout << ' ';
    cout << (char)(i + 'A');
  }

  cout << '\n';
}

// Pre-Build Function
inline void build() {
  clr(penalty);
  clr(sub_count);
}

// Actual Solver
inline void solve() {
  cin >> probs;
  cin.get();

  string s;
  while (getline(cin, s)) {
    if (s[0] == 'G') break;
    parse_submission(s);
  }

  vector<Result> rets;
  int rk = 1;

  for (int i = 0; i < cnt; i++) rets.push_back(Result(i));

  sort(all(rets));

  print_header();

  rets[0].print(rk);
  cout << '\n';

  for (int i = 1; i < cnt; i++) {
    if (rets[i - 1] == rets[i])
      rets[i].print(rk);
    else
      rets[i].print(++rk);
    cout << '\n';
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