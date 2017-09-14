#include <cstdio>

const int MAX = 1e8 + 10;

long long list[MAX] = {1, 8, 49};

void init()
{
    for (int i = 3; i < MAX; i++)
        list[i] = 7 * list[i - 1] - 7 * list[i - 2] + list[i - 3];
}

int main()
{
    init();
    int T, kase = 0;
    long long N;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &N);
        for (int i = 0; i < MAX; i++)
        {
            if (N <= list[i])
            {
                printf("Case #%d: %lld\n", ++kase, list[i]);
                break;
            }
        }
    }
    return 0;
}