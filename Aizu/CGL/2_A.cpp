#include <bits/stdc++.h>

using namespace std;

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
const double EPS = 1e-8;
const double PI = acos(-1);
const double FAC = 1e-18;

typedef double db;

int sgn(db x) {
  if (abs(x) < EPS) return 0;
  if (x < 0) return -1;
  return 1;
}

inline db sqr(db x) { return x * x; }

// Point/Vector
struct Point {
  db x, y;

  Point() : x(FAC), y(FAC) {}

  Point(db _x, db _y) : x(_x + FAC), y(_y + FAC) {}

  bool operator==(const Point &p) {
    return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
  }

  bool operator<(const Point &p) {
    int c = sgn(x - p.x);
    if (c) return c == -1;
    return sgn(y - p.y) == -1;
  }

  Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
  Point operator*(db d) { return Point(x * d, y * d); }
  Point operator/(db d) { return Point(x / d, y / d); }

  db operator^(const Point &p) { return x * p.y - y * p.x; }
  db operator*(const Point &p) { return x * p.x + y * p.y; }

  db dis(const Point &p) { return (*this - p).len(); }
  db alpha() { return atan2(y, x); }

  Point unit() { return *this / len(); }

  Point rotac() { return Point(-y, x); }
  Point rotcl() { return Point(y, -x); }

  Point rot(Point p, db angle) {
    Point v = *this - p;
    db c = cos(angle), s = sin(angle);
    return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
  }

  db len() { return hypot(x, y); }
  db len2() { return x * x + y * y; }

  db rad(Point a, Point b) {
    Point ap = a - *this, bp = b - *this;
    return abs(atan2(abs(ap ^ bp), ap * bp));
  }

  void read() { cin >> x >> y; }
  void write() { cout << '(' << x << ", " << y << ")\n"; }
};

// Line
struct Line {
  Point s, e;

  Line(){};

  Line(Point _s, Point _e) : s(_s), e(_e) {}

  Line(Point p, db angle) {
    s = p;
    if (sgn(angle - PI / 2))
      e = (s + Point(1, tan(angle)));
    else
      e = (s + Point(0, 1));
  }

  // ax+by+c=0
  Line(db a, db b, db c) {
    if (sgn(a) == 0) {
      s = Point(0, -c / b);
      e = Point(1, -c / b);
    } else if (sgn(b) == 0) {
      s = Point(-c / a, 0);
      e = Point(-c / a, 1);
    } else {
      s = Point(0, -c / b);
      e = Point(1, -(c + a) / b);
    }
  }

  db len() { return s.dis(e); }
  db angle() {
    db ans = atan2(e.y - s.y, e.x - s.x);
    if (sgn(ans) == -1) ans += PI;
    if (sgn(ans - PI) == 0) ans -= PI;
    return ans;
  }

  // 1 -> On Counter-clockwise
  // 2 -> On Clockwise
  // 3 -> On Line BUT MAY NOT ON THE SEGMENT!
  int relation(Point p) {
    int c = sgn((p - s) ^ (e - s));
    if (c < 0)
      return 1;
    else if (c > 0)
      return 2;
    return 3;
  }

  bool checkOn(Point p) {
    return relation(p) == 3 && sgn((p - s) ^ (p - e)) <= 0;
  }

  bool parallel(Line l) { return sgn((e - s) ^ (l.e - l.s)) == 0; }

  // 0 -> Formal Intersection
  // 1 -> Informal
  // 2 -> Not Intersect
  int crossSS(Line l) {
    int d1 = sgn((e - s) ^ (l.s - s));
    int d2 = sgn((e - s) ^ (l.e - s));
    int d3 = sgn((l.e - l.s) ^ (s - l.s));
    int d4 = sgn((l.e - l.s) ^ (e - l.s));
    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
    return (d1 == 0 && sgn((l.s - s) * (l.s - e)) <= 0) ||
           (d2 == 0 && sgn((l.e - s) * (l.e - e)) <= 0) ||
           (d3 == 0 && sgn((s - l.s) * (s - l.e)) <= 0) ||
           (d4 == 0 && sgn((e - l.s) * (e - l.e)) <= 0);
  }

  // 0 -> Formal Intersection
  // 1 -> Informal
  // 2 -> Not Intersect
  int crossLS(Line l) {
    int d1 = sgn((e - s) ^ (l.s - s));
    int d2 = sgn((e - s) ^ (l.e - s));
    if ((d1 ^ d2) == -2) return 2;
    return (d1 == 0 || d2 == 0);
  }

  // 0 -> Parallel
  // 1 -> Same
  // 2 -> Intersect
  int crossLL(Line l) {
    if (this->parallel(l)) return l.relation(s) == 3;
    return 2;
  }

  Point crossP(Line l) {
    db a1 = (l.e - l.s) ^ (s - l.s);
    db a2 = (l.e - l.s) ^ (e - l.s);
    return Point((s.x * a2 - e.x * a1) / (a2 - a1),
                 (s.y * a2 - e.y * a1) / (a2 - a1));
  }

  db disPL(Point p) { return abs((p - s) ^ (e - s)) / len(); }
  db disPS(Point p) {
    if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
      return min(p.dis(s), p.dis(e));
    return disPL(p);
  }
  db disSS(Line l) {
    return min(min(disPS(l.s), disPS(l.e)), min(l.disPS(s), l.disPS(e)));
  }

  Point proj(Point p) {
    return s + ((e - s) * ((e - s) * (p - s))) / ((e - s).len2());
  }
  Point refl(Point p) {
    Point q = proj(p);
    return Point(2 * q.x - p.x, 2 * q.y - p.y);
  }

  bool operator==(Line l) { return s == l.s && e == l.e; }

  void adjust() {
    if (e < s) swap(s, e);
  }

  void read() {
    s.read();
    e.read();
  }

  void write() {
    cout << "Line:\n";
    s.write();
    e.write();
  }
};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int q;
  cin >> q;
  while (q--) {
    Line l1, l2;
    l1.read();
    l2.read();
    l1.adjust();
    l2.adjust();
    if (l1.crossLL(l2) == 2)
      cout << "1\n";
    else {
      auto d = abs(l1.angle() - l2.angle());
      if (sgn(d - PI) > 0) d -= PI;
      if (!sgn(PI - 2 * d))
        cout << "1\n";
      else
        cout << "0\n";
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