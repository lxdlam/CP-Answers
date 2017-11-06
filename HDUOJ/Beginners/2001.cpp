#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        double d1 = x2 - x1, d2 = y2 - y1;
        printf("%.2lf\n", sqrt(d1 * d1 + d2 * d2));
    }
    return 0;
}