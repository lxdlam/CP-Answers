#include <cstdio>

const int MAX = 1e9 + 10;

long long fib[MAX] = {0, 1};
long long ans[MAX] = {4};

bool isInFib(int a)
{
    for (int i = 0; i < MAX; i++)
    {
        if (fib[i] == a)
            return true;
        else if (a > fib[i] && a < fib[i + 1])
            return false;
    }
    return false;
}

void init()
{
    for (int i = 2; i < MAX; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    for (int j = 1; j < MAX; j++)
    {
        for (int i = 1; i < MAX; i++)
        {
            if (!isInFib(ans[j - 1] + fib[i]))
            {
                ans[j] = (ans[j - 1] + fib[i]) % 998244353;
                break;
            }
        }
    }
}

int main()
{
    init();
    long long k;
    while (scanf("%lld", &k) == 1)
        printf("%lld", ans[k - 1]);
    return 0;
}