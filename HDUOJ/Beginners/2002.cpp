#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double PI = 3.1415927;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double r;
    while (cin >> r)
        printf("%.3lf\n", 4.0 / 3.0 * PI * r * r * r);
    return 0;
}