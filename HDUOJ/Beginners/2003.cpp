#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    double r;
    while (cin >> r)
        printf("%.2lf\n", r > 0 ? r : -r);
    return 0;
}