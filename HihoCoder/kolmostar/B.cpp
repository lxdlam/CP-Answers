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
#include <bits/stdc++.h>

using namespace std;

// Pre-Build Function
inline void build() {}

/* Oberservation script:
 * #!/bin/python3
 * A = [(1, -1, -1, -1, -1, -1, -1, 1, -1), (1, -1, -1, -1, -1, -1, 1, -1, -1),
 *      (1, -1, -1, -1, 1, -1, -1, -1, -1), (1, -1, -1, -1, 1, 1, 1, 1, 1),
 *      (1, -1, -1, 1, -1, 1, -1, 1, 1), (1, -1, -1, 1, 1, -1, 1, -1, 1),
 *      (1, -1, -1, 1, 1, 1, -1, -1, -1), (1, -1, -1, 1, 1, 1, -1, 1, 1),
 *      (1, -1, 1, -1, -1, 1, 1, 1, -1), (1, -1, 1, -1, 1, -1, -1, 1, 1),
 *      (1, -1, 1, -1, 1, 1, -1, -1, -1), (1, -1, 1, 1, -1, -1, -1, 1, -1),
 *      (1, -1, 1, 1, -1, -1, -1, 1, 1), (1, -1, 1, 1, -1, -1, 1, -1, 1),
 *      (1, -1, 1, 1, 1, 1, 1, -1, 1), (1, 1, -1, -1, -1, -1, -1, -1, 1),
 *      (1, 1, -1, -1, -1, 1, -1, -1, -1), (1, 1, -1, -1, -1, 1, 1, 1, 1),
 *      (1, 1, -1, -1, 1, -1, 1, -1, 1), (1, 1, -1, 1, -1, 1, -1, -1, 1),
 *      (1, 1, -1, 1, 1, -1, -1, 1, -1), (1, 1, -1, 1, 1, 1, 1, 1, -1),
 *      (1, 1, 1, -1, -1, -1, -1, -1, -1), (1, 1, 1, -1, 1, 1, -1, -1, 1),
 *      (1, 1, 1, -1, 1, 1, 1, 1, 1), (1, 1, 1, 1, -1, 1, 1, -1, -1),
 *      (1, 1, 1, 1, 1, -1, 1, 1, -1), (1, 1, 1, 1, 1, 1, -1, 1, 1)]
 *
 *
 * def diff(A, B):
 *     ret = []
 *     for i in range(9):
 *         if A[i] != B[i]:
 *             ret.append(i)
 *     return ret
 *
 *
 * diffs = [(-1, [0 for _ in range(29)]) for __ in range(28)]
 *
 * for i in range(28):
 *     for j in range(28):
 *         if i == j:
 *             continue
 *         ret = diff(A[i], A[j])
 *         if (len(ret) < len(diffs[i][1])):
 *             diffs[i] = (j, ret)
 *
 * for i in range(28):
 *     print(f"Row {i+1}: {diffs[i][0]+1}, differ: {diffs[i][1]}")
 */

// Matrix A itself
vector<vector<int>> A{
    {1, -1, -1, -1, -1, -1, -1, 1, -1}, {1, -1, -1, -1, -1, -1, 1, -1, -1},
    {1, -1, -1, -1, 1, -1, -1, -1, -1}, {1, -1, -1, -1, 1, 1, 1, 1, 1},
    {1, -1, -1, 1, -1, 1, -1, 1, 1},    {1, -1, -1, 1, 1, -1, 1, -1, 1},
    {1, -1, -1, 1, 1, 1, -1, -1, -1},   {1, -1, -1, 1, 1, 1, -1, 1, 1},
    {1, -1, 1, -1, -1, 1, 1, 1, -1},    {1, -1, 1, -1, 1, -1, -1, 1, 1},
    {1, -1, 1, -1, 1, 1, -1, -1, -1},   {1, -1, 1, 1, -1, -1, -1, 1, -1},
    {1, -1, 1, 1, -1, -1, -1, 1, 1},    {1, -1, 1, 1, -1, -1, 1, -1, 1},
    {1, -1, 1, 1, 1, 1, 1, -1, 1},      {1, 1, -1, -1, -1, -1, -1, -1, 1},
    {1, 1, -1, -1, -1, 1, -1, -1, -1},  {1, 1, -1, -1, -1, 1, 1, 1, 1},
    {1, 1, -1, -1, 1, -1, 1, -1, 1},    {1, 1, -1, 1, -1, 1, -1, -1, 1},
    {1, 1, -1, 1, 1, -1, -1, 1, -1},    {1, 1, -1, 1, 1, 1, 1, 1, -1},
    {1, 1, 1, -1, -1, -1, -1, -1, -1},  {1, 1, 1, -1, 1, 1, -1, -1, 1},
    {1, 1, 1, -1, 1, 1, 1, 1, 1},       {1, 1, 1, 1, -1, 1, 1, -1, -1},
    {1, 1, 1, 1, 1, -1, 1, 1, -1},      {1, 1, 1, 1, 1, 1, -1, 1, 1}};

// cooresponding rows that has minimum differs
vector<int> coor{-1, 0,  0,  -1, -1, 13, 2,  4,  0,  12, 2, -1, 11, 5,
                 5,  -1, 15, 3,  5,  4,  -1, 20, 15, 10, 3, 8,  20, 7};

vector<pair<int, vector<int>>> diffs{
    {1, {6, 7}},    {0, {6, 7}},  {0, {4, 7}},  {7, {3, 6}},    {7, {4}},
    {13, {2, 4}},   {2, {3, 5}},  {4, {4}},     {0, {2, 5, 6}}, {12, {3, 4}},
    {2, {2, 5}},    {12, {8}},    {11, {8}},    {5, {2, 4}},    {5, {2, 5}},
    {16, {5, 8}},   {15, {5, 8}}, {3, {1, 4}},  {5, {1, 3}},    {4, {1, 7}},
    {21, {5, 6}},   {20, {5, 6}}, {15, {2, 8}}, {10, {1, 8}},   {3, {1, 2}},
    {8, {1, 3, 7}}, {20, {2, 6}}, {7, {1, 2}}};

// Total operations: 36 + 396 = 432 operaions
// result will be stored into ret
void matrix_mul_spec(const vector<int> &v, vector<int> &ret) {
  // first, calculate necessary rows
  vector<int> necessary_rows{0, 4, 5, 11, 15, 20};
  vector<int> spec_rows{7,  12, 1,  2,  3,  6,  8,  9,  10, 13, 14,
                        16, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27};

  // 6 * (3 * read + multi + add + store) = 36 operations
  for (const auto& i : necessary_rows) {
    for (int j = 0; j < 9; j++) {
      ret[i] = ret[i] + A[i][j] * v[j];
    }
  }

  // 22 * 4 + 44 * ( 3 * read + minus + 2 * mult + store) = 396 operations
  // Then, calculate differences
  for (const auto& i : spec_rows) {

    // get diff index and indices
    // 2 operations required
    int idx;
    vector<int> indices;
    tie(idx, indices) = diffs[i];

    // load into the result section
    // 2 opetaions required
    ret[i] = ret[idx];

    for (auto it : indices) {
      ret[i] = ret[i] - 2 * A[idx][it] * v[it];
    }
  }
}

// Actual Solver
inline void solve() {
  vector<int> v(9), ret(28);

  for (auto &i : v) cin >> i;

  matrix_mul_spec(v, ret);

  for (int i = 0; i < 28; i++) cout << ret[i] << " \n"[i == 27];
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