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

  Point() : x(0.0), y(0.0) {}

  Point(db _x, db _y) : x(_x), y(_y) {}

  bool operator==(const Point& p) { return sgn(x - p.x) == 0 && sgn(y - p.y) == 0; }

  bool operator<(const Point& p) {
    int c = sgn(x - p.x);
    if (c) return c == -1;
    return sgn(y - p.y) == -1;
  }

  Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }
  Point operator*(db d) { return Point(x * d, y * d); }
  Point operator/(db d) { return Point(x / d, y / d); }

  db operator^(const Point& p) { return x * p.y - y * p.x; }
  db operator*(const Point& p) { return x * p.x + y * p.y; }

  db dis(const Point& p) { return (*this - p).len(); }
  db alpha() { return atan2(y, x); }

  Point unit() { return *this / len(); }
  Point scale(db r) { return unit() * r; }

  Point rotCC() { return Point(-y, x); }
  Point rotCL() { return Point(y, -x); }

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

  // Point P,A,B
  // -2 -> B is at back of PA
  // -1 -> PB is on the clock-wise side of PA
  // 0 -> B is on PA
  // 1 -> PB is on the counter clock-wise side of PA
  // 2 -> B is at the front of PA
  int relation(Point a, Point b) {
    Point p = *this;
    if (sgn((a - p) ^ (b - p)) > 0) return 1;
    if (sgn((a - p) ^ (b - p)) < 0) return -1;
    if (sgn((a - p) * (b - p)) < 0) return -2;
    if (sgn((p - a) * (b - a)) < 0) return 2;
    return 0;
  }

  void read() { cin >> x >> y; }
  void write(char trail = ' ') { cout << x << ' ' << y << trail; }
  void Debug() { cerr << "Point: (" << x << ", " << y << ")\n"; }
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

  int relation(Point p) { return s.relation(e, p); }

  bool parallel(Line l) { return sgn((e - s) ^ (l.e - l.s)) == 0; }

  // 0 -> Not Intersect
  // 1 -> Informal
  // 2 -> Formal Intersection
  int crossSS(Line l) {
    int d1 = sgn((e - s) ^ (l.s - s));
    int d2 = sgn((e - s) ^ (l.e - s));
    int d3 = sgn((l.e - l.s) ^ (s - l.s));
    int d4 = sgn((l.e - l.s) ^ (e - l.s));
    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
    return (d1 == 0 && sgn((l.s - s) * (l.s - e)) <= 0) || (d2 == 0 && sgn((l.e - s) * (l.e - e)) <= 0) ||
           (d3 == 0 && sgn((s - l.s) * (s - l.e)) <= 0) || (d4 == 0 && sgn((e - l.s) * (e - l.e)) <= 0);
  }

  // 0 -> Not Intersect
  // 1 -> Informal
  // 2 -> Formal Intersection
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

  Point intersec(Line l) {
    db a1 = (l.e - l.s) ^ (s - l.s);
    db a2 = (l.e - l.s) ^ (e - l.s);
    return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
  }

  db disPL(Point p) { return abs((p - s) ^ (e - s)) / len(); }
  db disPS(Point p) {
    if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0) return min(p.dis(s), p.dis(e));
    return disPL(p);
  }
  db disSS(Line l) { return min(min(disPS(l.s), disPS(l.e)), min(l.disPS(s), l.disPS(e))); }

  Point proj(Point p) { return s + ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()); }
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

  void Debug() { cerr << "Line: Start: (" << s.x << ", " << s.y << ") End: (" << e.x << ", " << e.y << ")\n"; }
};

// Polygon
struct Polygon {
  // Functor for sorting by polar angle
  struct cmp {
    Point p;
    cmp(const Point& b) { p = b; }
    bool operator()(const Point& a, const Point& b) {
      Point x = a, y = b;
      int d = sgn((x - p) ^ (y - p));
      if (!d) return sgn(x.dis(p) - y.dis(p)) > 0;
      return d > 0;
    }
  };

  vector<Point> ps;
  vector<Line> ls;

  Polygon() {}

  void add(Point p) { ps.push_back(p); }

  int size() { return static_cast<int>(ps.size()); }

  void getLines() {
    int s = size();
    for (int i = 0; i < s; i++) ls.push_back(Line(ps[i], ps[(i + 1) % s]));
  }

  void norm() {
    Point p = ps[0];
    for (int i = 1; i < size(); i++) {
      if (p < ps[i]) continue;
      p = ps[i];
    }
    sort(ps.begin(), ps.end(), cmp(p));
  }

  void getConvexJarvis(Polygon& conv) {
    sort(ps.begin(), ps.end());
    conv.ps.resize(2 * size());

    int n = size();
    for (int i = 0; i < min(2, n); i++) conv.ps[i] = ps[i];
    if (conv.size() == 2 && (conv.ps[0] == conv.ps[1])) conv.ps.resize(1);

    if (n <= 2) return;

    int top = 1;

    for (int i = 2; i < n; i++) {
      while (top && sgn((conv.ps[top] - ps[i]) ^ (conv.ps[top - 1] - ps[i])) <= 0) top--;
      conv.ps[++top] = ps[i];
    }

    int t = top;
    conv.ps[++top] = ps[n - 2];

    for (int i = n - 3; i >= 0; i--) {
      while (top != t && sgn((conv.ps[top] - ps[i]) ^ (conv.ps[top - 1] - ps[i])) <= 0) top--;
      conv.ps[++top] = ps[i];
    }

    while (conv.size() > top) conv.ps.pop_back();

    if (top == 2 && (conv.ps[0] == conv.ps[1])) conv.ps.pop_back();

    conv.norm();  // Counter Clock-wise
  }

  void getConvexWithPointOnLine(Polygon& conv) {
    int m, n = size();
    if (n < 3) {
      for (auto i : ps) conv.add(i);
      return;
    }

    vector<Point>& g = conv.ps;

    sort(ps.begin(), ps.end());
    for (int i = 0; i < n; i++) {
      while ((m = g.size()) >= 2 && g[m - 2].relation(g[m - 1], ps[i]) <= 0) g.pop_back();
      g.push_back(ps[i]);
    }

    int t = g.size();

    for (int i = n - 2; i >= 0; i--) {
      while ((m = g.size()) > t && g[m - 2].relation(g[m - 1], ps[i]) <= 0) g.pop_back();
      g.push_back(ps[i]);
    }

    g.pop_back();
  }

  // Cannot get the point on the edge
  void getConvexGraham(Polygon& conv) {
    norm();
    int top = 0, n = size();
    if (n == 1) {
      conv.add(ps[0]);
      return;
    }

    if (n == 2) {
      conv.add(ps[0]);
      conv.add(ps[1]);
      if (conv.ps[0] == conv.ps[1]) conv.ps.pop_back();
      return;
    }

    conv.ps.resize(size());
    conv.ps[0] = ps[0];
    conv.ps[1] = ps[1];
    top = 2;
    for (int i = 2; i < n; i++) {
      while (top > 1 && sgn((conv.ps[top - 1] - conv.ps[top - 2]) ^ (ps[i] - conv.ps[top - 2])) <= 0) top--;
      conv.ps[top++] = ps[i];
    }

    while (conv.size() > top) conv.ps.pop_back();

    if (top == 2 && (conv.ps[0] == conv.ps[1])) conv.ps.pop_back();
  }

  bool isConvex() {
    bitset<3> s;
    int n = size();
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      int k = (j + 1) % n;
      s.set(sgn((ps[j] - ps[i]) ^ (ps[k] - ps[i])) + 1);
      if (s[0] && s[2]) return false;
    }
    return true;
  }

  void read(int s) {
    for (int i = 0; i < s; i++) {
      Point p;
      p.read();
      ps.push_back(p);
    }
  }

  void Debug() {
    cerr << "Polygon:\nPoints:\n";
    for (auto i : ps) i.Debug();
    cerr << "Lines:\n";
    for (auto i : ls) i.Debug();
  }
};

// Circle
struct Circle {
  Point p;
  db r;

  Circle(){};

  Circle(Point _p, db _r) : p(_p), r(_r) {}

  Circle(db x, db y, db _r) : p({x, y}), r(_r) {}

  Circle(Point a, Point b, Point c, bool in = false) {
    if (!in) {
      Line u = Line((a + b) / 2, (a + b) / 2 + (b - a).rotCC());
      Line v = Line((b + c) / 2, (b + c) / 2 + (c - b).rotCC());
      p = u.intersec(v);
      r = p.dis(a);
    } else {
      Line u, v;
      db m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
      u.s = a;
      u.e = a + Point(cos((n + m) / 2), sin((n + m) / 2));
      v.s = b;
      m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
      v.e = b + Point(cos((n + m) / 2), sin((n + m) / 2));
      p = u.intersec(v);
      r = Line(a, b).disPS(p);
    }
  }

  bool operator==(const Circle& c) { return p == c.p && sgn(r - c.r) == 0; }

  bool operator<(const Circle& c) { return (p < c.p) || (p == c.p && sgn(r - c.r) < 0); }

  db area() { return PI * r * r; }

  db cir() { return 2 * PI * r; }

  Point on(db ang) { return Point(p.x + r * cos(ang), p.y + r * sin(ang)); }

  // 0 -> Outside
  // 1 -> On
  // 2 -> Inside
  int relationP(Point v) {
    db dis = v.dis(p);
    if (sgn(dis - r) < 0)
      return 2;
    else if (sgn(dis - r) == 0)
      return 1;
    return 0;
  }

  // The number of intersections
  int relationS(Line l) {
    db dis = l.disPS(p);
    if (sgn(dis - r) < 0)
      return 2;
    else if (sgn(dis - r) == 0)
      return 1;
    return 0;
  }

  // The number of intersections
  int relationL(Line l) {
    db dis = l.disPL(p);
    if (sgn(dis - r) < 0)
      return 2;
    else if (sgn(dis - r) == 0)
      return 1;
    return 0;
  }

  // 1 -> Inside
  // 2 -> Internally-tangent
  // 3 -> Intersect
  // 4 -> Externally-tangent
  // 5 -> Disjoint
  int relationC(Circle c) {
    db d = p.dis(c.p);
    if (sgn(d - r - c.r) > 0) return 5;
    if (sgn(d - r - c.r) == 0) return 4;
    db l = abs(r - c.r);
    if (sgn(d - r - c.r) < 0 && sgn(d - l) > 0) return 3;
    if (sgn(d - l) == 0) return 2;
    // TODO: Check if this one is necessary
    // if (sgn(d - l) < 0)
    return 1;
  }

  // The return value is the number of intersections
  int crossC(Circle c, Point& p1, Point& p2) {
    int re = relationC(c);
    if (re == 1 || re == 5) return 0;
    db d = p.dis(c.p), l = (d * d + r * r - c.r * c.r) / (2.0 * d), h = sqrt(r * r - l * l);
    Point tmp = p + (c.p - p).scale(l);
    p1 = tmp + (c.p - p).rotCC().scale(h);
    p2 = tmp + (c.p - p).rotCL().scale(h);
    if (re == 2 || re == 4) return 1;
    return 2;
  }

  // Same as above
  int crossL(Line l, Point& p1, Point& p2) {
    if (!this->relationL(l)) return 0;
    Point a = l.proj(p);
    db d = l.disPL(p);
    d = sqrt(r * r - d * d);
    if (sgn(d) == 0) {
      p1 = a;
      p2 = a;
      return 1;
    }
    p1 = a + (l.e - l.s).scale(d);
    p2 = a - (l.e - l.s).scale(d);
    return 2;
  }

  int tangent(Point q, Point& u, Point& v) {
    int x = relationP(q);
    if (x == 2) return 0;
    if (x == 1) {
      u = q + (q - p).rotCC();
      v = u;
      return 1;
    }
    db d = p.dis(q);
    db l = r * r / d;
    db h = sqrt(r * r - l * l);
    u = p + ((q - p).scale(l) + (q - p).rotCC().scale(h));
    v = p + ((q - p).scale(l) + (q - p).rotCL().scale(h));
    return 2;
  }

  int tangent(Circle c, vector<Point>& u, vector<Point>& v) {
    if (sgn(r - c.r) < 0) return c.tangent(*this, v, u);

    int ret = relationC(c) - 1;
    if (!ret || *this == c) return 0;
    u.clear();
    v.clear();

    db b = (c.p - p).alpha();

    if (ret == 1 || ret == 3) {
      u.push_back(on(b));
      v.push_back(on(b));
    }

    db ang = acos((r - c.r) / p.dis(c.p));

    if (ret != 1) {
      u.push_back(on(b + ang));
      u.push_back(on(b - ang));
      v.push_back(c.on(b + ang));
      v.push_back(c.on(b - ang));
    }

    if (ret == 4) {
      ang = acos((r + c.r) / p.dis(c.p));
      u.push_back(on(b + ang));
      u.push_back(on(b - ang));
      v.push_back(c.on(PI + b + ang));
      v.push_back(c.on(PI + b - ang));
    }

    return ret;
  }

  // The area of intersecting space
  // With circle c
  db area(Circle c) {
    int re = relationC(c);
    if (re >= 4) return 0;
    if (re <= 2) return min(area(), c.area());
    db d = p.dis(c.p);
    db hf = (r + c.r + d) / 2.0;
    db ss = 2 * sqrt(hf * (hf - r) * (hf - c.r) * (hf - d));
    db a1 = acos((r * r + d * d - c.r * c.r) / (2.0 * r * d));
    a1 = a1 * r * r;
    db a2 = acos((c.r * c.r + d * d - r * r) / (2.0 * c.r * d));
    a2 = a2 * c.r * c.r;
    return a1 + a2 - ss;
  }

  // The area of intersecting space
  // With triangle PAB
  db area(Point a, Point b) {
    if (sgn((p - a) ^ (p - b)) == 0) return 0.0;
    Point q[5];
    int len = 0;
    q[len++] = a;
    Line l(a, b);
    Point p1, p2;
    if (crossL(l, q[1], q[2]) == 2) {
      if (sgn((a - q[1]) * (b - q[1])) < 0) q[len++] = q[1];
      if (sgn((a - q[2]) * (b - q[2])) < 0) q[len++] = q[2];
    }
    q[len++] = b;
    if (len == 4 && sgn((q[0] - q[1]) * (q[2] - q[1])) > 0) swap(q[1], q[2]);
    db res = 0;
    for (int i = 0; i < len - 1; i++) {
      if (relationP(q[i]) == 0 || relationP(q[i + 1]) == 0) {
        db arg = p.rad(q[i], q[i + 1]);
        res += r * r * arg / 2.0;
      } else
        res += abs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
    }
    return res;
  }

  // Two circle whose center are a and b respectivelly
  static int GetCircle(Point a, Point b, db r, Circle& c1, Circle& c2) {
    Circle x(a, r), y(b, r);
    int t = x.crossC(y, c1.p, c2.p);
    if (!t) return 0;
    c1.r = c2.r = r;
    return t;
  }

  // The circle which tangent is l and point p on it
  static int GetCircle(Line l, Point p, db r, Circle& c1, Circle& c2) {
    db dis = l.disPL(p);
    if (sgn(dis - r * 2) > 0) return 0;
    if (sgn(dis) == 0) {
      c1.p = p + ((l.e - l.s).rotCC().scale(r));
      c2.p = p + ((l.e - l.s).rotCL().scale(r));
      c1.r = c2.r = r;
      return 2;
    }
    Line u1 = Line((l.s + (l.e - l.s).rotCC().scale(r)), (l.e + (l.e - l.s).rotCC().scale(r)));
    Line u2 = Line((l.s + (l.e - l.s).rotCL().scale(r)), (l.e + (l.e - l.s).rotCL().scale(r)));
    Circle cc(p, r);
    Point p1, p2;
    if (!cc.crossL(u1, p1, p2)) cc.crossL(u2, p1, p2);
    c1 = Circle(p1, r);
    if (p1 == p2) {
      c2 = c1;
      return 1;
    }
    c2 = Circle(p2, r);
    return 2;
  }

  // u and v are the common tangent of the four circles
  static int GetCircle(Line u, Line v, db r, Circle& c1, Circle& c2, Circle& c3, Circle& c4) {
    if (u.parallel(v)) return 0;
    Line u1 = Line(u.s + (u.e - u.s).rotCC().scale(r), u.e + (u.e - u.s).rotCC().scale(r));
    Line u2 = Line(u.s + (u.e - u.s).rotCL().scale(r), u.e + (u.e - u.s).rotCL().scale(r));
    Line v1 = Line(v.s + (v.e - v.s).rotCC().scale(r), v.e + (v.e - v.s).rotCC().scale(r));
    Line v2 = Line(v.s + (v.e - v.s).rotCL().scale(r), v.e + (v.e - v.s).rotCL().scale(r));
    c1.r = c2.r = c3.r = c4.r = r;
    c1.p = u1.intersec(v1);
    c2.p = u1.intersec(v2);
    c3.p = u2.intersec(v1);
    c4.p = u2.intersec(v2);
    return 4;
  }

  // Tangent with circle cx and cy
  static int GetCircle(Circle cx, Circle cy, db r, Circle& c1, Circle& c2) {
    Circle x(cx.p, r + cx.r), y(cy.p, r + cy.r);
    int t = x.crossC(y, c1.p, c2.p);
    if (!t) return 0;
    c1.r = c2.r = r;
    return t;
  }

  void read() {
    p.read();
    cin >> r;
  }

  void Debug() { cerr << "Circle: Center: (" << p.x << ", " << p.y << ") Radius: " << r << '\n'; }
};

// Pre-Build Function
inline void build() {}

// Actual Solver
inline void solve() {
  int n;
  cin >> n;
  Polygon p;
  p.read(n);
  cout << p.isConvex() << '\n';
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