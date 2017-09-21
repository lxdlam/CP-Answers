#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

int sgn(double x)
{
    if (fabs(x) < EPS)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

struct Point
{
    double x, y;

    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator*(const Point &b) const
    {
        return x * b.x + y * b.y;
    }
};

Point center(Point a, Point b, Point c)
{
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    return Point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}

double d(Point a, Point b)
{
    return sqrt((a - b) * (a - b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    double ax, ay, bx, by, cx, cy, xx, xy;
    while (T--)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> xx >> xy;
        Point a(ax, ay);
        Point b(bx, by);
        Point c(cx, cy);
        Point cn = center(a, b, c);
        Point x(xx, xy);
        if (fabs(d(x, cn) - d(a, cn)) < EPS || d(x, cn) < d(a, cn))
            cout << "Rejected\n";
        else
            cout << "Accepted\n";
    }
    return 0;
}