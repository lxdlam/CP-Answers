#include <iostream>

#define ll long long

using namespace std;

const int MOD = 998244353;
const int SIZE = 5000 + 10;

int c[SIZE][SIZE] = {0};
int n[SIZE] = {1};

void init()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    for (int i = 1; i < SIZE; i++)
        n[i] = (n[i - 1] * i) % MOD;
}

ll solve(ll a, ll b)
{
    ll res = 0, temp;

    for (ll i = 0; i <= a && i <= b; i++)
    {
        temp = 1;
        temp = (temp * c[a][i]) % MOD;
        temp = (temp * c[b][i]) % MOD;
        temp = (temp * n[i]) % MOD;
        res = (res + temp) % MOD;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    ll a, b, c;
    cin >> a >> b >> c;

    ll res = 1;
    res = (res * solve(a, b)) % MOD;
    res = (res * solve(a, c)) % MOD;
    res = (res * solve(b, c)) % MOD;
    cout << res << endl;

    return 0;
}