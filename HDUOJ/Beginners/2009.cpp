#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double n, res;
    int m;
    while (~scanf("%lf %d", &n, &m))
    {
        res = 0;
        while (m--)
        {
            res += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", res);
    }
    return 0;
}