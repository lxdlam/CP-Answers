#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int y, m, d;
    while (scanf("%d/%d/%d", &y, &m, &d) == 3)
    {
        d += days[m - 1];
        if (m > 2 && isLeap(y))
            d++;
        printf("%d\n", d);
    }
    return 0;
}