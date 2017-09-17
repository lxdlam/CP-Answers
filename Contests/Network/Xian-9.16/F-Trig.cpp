#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int MOD = 998244353;

long long nCr(int m, int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= m - i;
        res /= i + 1;
    }
    return res;
}

int main()
{
    int n, m, k;
    long long res;
    while (scanf("%d%d", &n, &m) == 2)
    {
        k = (n - m) / 2;
        if (k <= 0)
            res = ((0 + nCr(n - 1 - k, k - 1)) * pow(2, n - 1 - 2 * k) * (k % 2 == 0 ? 1 : -1));
        else
            res = ((nCr(n - k, k) + nCr(n - 1 - k, k - 1)) * pow(2, n - 1 - 2 * k) * (k % 2 == 0 ? 1 : -1));
        // cout << "nCr(n - k, k): " << nCr(n - k, k) << endl;
        // cout << "nCr(n - 1 - k, k - 1): " << nCr(n - 1 - k, k - 1) << endl;
        // cout << "pow(2, (double)(n - 1 - 2 * k): " << pow(2, (double)(n - 1 - 2 * k)) << endl;
        // cout << "res: " << res << endl;
        if (res < 0)
            res += MOD;
        else
            res %= MOD;
        cout << res << endl;
    }
    return 0;
}