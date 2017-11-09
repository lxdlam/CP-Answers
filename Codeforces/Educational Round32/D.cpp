#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 1e3 + 10;

long long c[SIZE][SIZE] = {0};

long long d[SIZE] = {0};


void getCom()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        // Will be extremely large!
    }
}

void getD()
{
    long long res;
    d[1] = 0, d[2] = 1;
    for (int i = 3; i < SIZE; i++)
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
}

void init()
{
    getCom();
    getD();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    long long res = 0;

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        res += d[i] * c[n][n - i];

    cout << res + 1 << endl;

    return 0;
}