#include <iostream>

using namespace std;

const int SIZE = 1e3 + 10;

long long ns[SIZE] = {1};

void init()
{
    for (int i = 1; i < SIZE; i++)
        ns[i] = i * ns[i - 1];
}

inline long long solve(long long base, long long expr, long long p)
{
    long long res = 1;
    while (expr--)
    {
        res = (res * base) % p;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T, n;
    long long a, p;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        cin >> a >> n >> p;
        cout << solve(a, ns[n], p) << endl;
    }
    return 0;
}