#include <cstdio>
#include <cmath>

const int MAX = 1e8 + 10;

constexpr long long t(long long i) { return (1 / 2) * i * (i + 1); }

long long list[MAX] = {0};

void init()
{
    int pos = 0;
    for (long long i = 1; i < MAX; i++)
    {
        double num = t(i);
        num = sqrt(num);
        if ((int)num * 10 % 10 == 0)
            list[pos++] = i;
    }
}

int main()
{
    init();
    int T, kase = 0;
    long long N;
    long long comp;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &N);
        for (int i = 0; i < MAX; i++)
        {
            comp = list[i] * list[i];
            if (N <= comp)
            {
                N = i;
                break;
            }
        }
        printf("Case #%d: %lld\n", ++kase, N);
    }
    return 0;
}